/*************************************************************************
 > File Name: kill_test.cpp
 > Author: Catkin 
 > Created Time: Sun Feb 26 20:58:08 2023
 ************************************************************************/
//循环创建 5 个子进程 父进程 用kill函数终止 任意一个子进程
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
#include<iostream>
#include<signal.h>
#include<errno.h>
using namespace std;

void sys_err(const char* str)
{
    perror(str);
    exit(1);
}

int main(int argc, char* argv[])
{
    int i;
    for(i=0;i<5;i++)//creat 5 child process
    {
        pid_t pid = fork();
        if(pid == 0)//child
        {
            break;
        }
        if(pid < 0)
        {
            sys_err("fork error");
        }
    }
    if(i == 5)
    {
        sleep(5);
        printf("i'm parent,pid is %d\n",getpid());
    }
    else
    {
        sleep(i);
        printf("i'm %dth child,pid is %d,ppid is %d\n",i,getpid(),getppid());
    }
    

    return 0;
}

