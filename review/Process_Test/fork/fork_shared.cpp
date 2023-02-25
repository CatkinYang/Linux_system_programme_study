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
    printf("----before fork----\n");
    printf("my pid is = %d\n",getpid());
    int var = 10;
    pid_t pid = fork();
    if(pid == -1)
    {
        printf("no child process is Created\n");
        exit(1);
    }
    else if (pid == 0)
    {
        var = 200;
        printf("----child var = %d\n",var);
        printf("----child process,child pid is %d\n----parent's pid is %d\n",getpid(),getppid());
    }
    else if (pid > 0)
    {
        var = 100;
        sleep(1);
        printf("----parent var = %d\n",var);
        printf("----parent process: my child is %d\n----my parent's pid is %d\n----my pid is %d\n",pid,getppid(),getpid());
    }

    printf("----end of file\n");

    
    return 0;
}

