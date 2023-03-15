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

void catch_child(int signo)
{
    pid_t wpid;
    while ( (wpid = wait(NULL)) != -1)
    {
        if(wpid == -1)
        {
            sys_err("wait error");
        }
        printf("-------catch child id %d\n",wpid);
    }
    return ;
}
int main(int argc, char* argv[])
{

    pid_t pid;
    int i;
    for(i=0;i<5;i++)
        if((pid = fork()) == 0)
            break;

    if(i == 5)
    {
        struct sigaction act;
        act.sa_handler = catch_child;
        sigemptyset(&act.sa_mask);
        sigaction(SIGCHLD,&act,NULL);

        printf("i am parent,pid = %d\n",getpid());
        while(1);
        
    }
    else
    {
        printf("i am %dth child,pid = %d\n",i+1,getpid());
    }
    return 0;
}

