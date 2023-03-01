/*************************************************************************
 > File Name: kill.cpp
 > Author: Catkin 
 > Created Time: Sun Feb 26 20:31:52 2023
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
#include<iostream>
#include<errno.h>
#include<signal.h>
using namespace std;

void sys_err(const char *str)
{
    perror(str);
    exit(1);
}
int main(int argc, char* argv[])
{
    pid_t pid = fork();
    if(pid > 0)
    {
        printf("parent,pid = %d\n",getpid());
        while(1);
    }
    else if(pid == 0)
    {
        printf("child pid = %d,ppid = %d\n",getpid(),getppid());
        sleep(1);
        kill(getppid(),SIGKILL);
    }
    return 0;
}

