/*************************************************************************
 > File Name: session.cpp
 > Author: Catkin 
 > Created Time: Wed Mar  1 12:28:39 2023
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
#include<iostream>
#include<errno.h>
#include<fcntl.h>
using namespace std;

void sys_err(const char *str)
{
    perror(str);
    exit(1);
}

int main(int argc, char* argv[])
{
    pid_t pid;
    if((pid = fork()) < 0)
    {
        perror("fork");
        exit(1);
    }
    else if (pid == 0)
    {
        printf("child process PID is %d\n",getpid());
        printf("group id of child is %d\n",getpgid(0));
        printf("session id of child is %d\n",getsid(0));
        sleep(10);
        setsid();

        printf("changed:\n");

        printf("child process PID is %d\n",getpid());
        printf("group id of child is %d\n",getpgid(0));
        printf("session id of child is %d\n",getsid(0));
        sleep(20);
        exit(0);

    }


    return 0;
}

