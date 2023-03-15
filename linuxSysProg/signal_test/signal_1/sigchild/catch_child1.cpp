/*************************************************************************
 > File Name: catch_child.cpp
 > Author: Catkin 
 > Created Time: Tue Feb 28 21:33:43 2023
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
#include<iostream>
#include<errno.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<signal.h>
using namespace std;

void sys_err(const char *str)
{
    perror(str);
    exit(1);
}

void catch_child(int signo)//有子进程终止，发送sigchld信号时，该函数会被内核回调
{
    pid_t wpid;
    int status;
    
    while ( (wpid = waitpid(-1,&status,0)) != -1)  //循环回收，防止僵尸进程出现
    {
        if(WIFEXITED(status))
            printf("-------catch child id = %d, ret = %d\n",wpid,WEXITSTATUS(status));
    }
    return ;
}
int main(int argc, char* argv[])
{
    pid_t pid;
    //阻塞
    sigset_t set;
    sigemptyset(&set);
    sigaddset(&set,SIGCHLD);
    sigprocmask(SIG_BLOCK,&set,NULL);

    int i;
    for(i=0;i<15;i++)
        if((pid = fork()) == 0)//创建多个子进程
            break;

    if(i == 15)
    {
        struct sigaction act;
        act.sa_handler = catch_child;//设置回调函数
        sigemptyset(&act.sa_mask);//设置捕捉函数执行期间屏蔽字
        act.sa_flags = 0;   //设置默认属性，本信号自动屏蔽
        sigaction(SIGCHLD,&act,NULL);//注册信号捕捉函数
        
        //解除阻塞
        sigprocmask(SIG_UNBLOCK,&set,NULL);//如果没有解除阻塞步骤，回调函数没有执行机会
        
        printf("i am parent,pid = %d\n",getpid());
        while(1);//模拟父进程进行后续逻辑
        
    }
    else
    {
        printf("i am %dth child,pid = %d\n",i+1,getpid());
        return i;
    }
    return 0;
}

