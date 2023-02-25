/*************************************************************************
 > File Name: loop_fork.cpp
 > Author: Catkin 
 > Created Time: Sun Feb 19 16:37:59 2023
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
    int i;
    for(i=0;i<5;i++)
    {
        pid_t pid = fork();
        if(pid == -1)
        {
            perror("fork error\n");
            exit(1);
        }
        else if(pid > 0)//  parent process
        {
            continue;
        }
        else if (pid == 0)//child process
        {
            break;   
        }
    }
    if(i == 5)
    {
        sleep(5);
        printf("i am parent\n");
    }
    else
    {
        sleep(i);
        printf("i am %dth child\n",i+1);
    }

    return 0;
}

