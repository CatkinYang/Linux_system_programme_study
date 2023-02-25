/*************************************************************************
 > File Name: fork.cpp
 > Author: Catkin 
 > Created Time: Sun Feb 19 16:15:51 2023
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
#include<iostream>
using namespace std;

int main(int argc, char* argv[])
{
    pid_t pid = fork();
    if(pid == -1)
    {
        printf("no child process is Created\n");
        exit(1);
    }
    else if (pid == 0)//child process
    {
        printf("----i am child precess\n");
        execlp("ls","ls","-l",NULL);
        exit(1);
    }
    else if (pid > 0)//parent process
    {
       sleep(1);
       printf("i'm parent: %d\n",getpid());
    }


    
    return 0;
}

