/*************************************************************************
 > File Name: fork.c
 > Author: Catkin 
 > Created Time: Sat Feb 18 10:11:24 2023
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
#include<sys/wait.h>
int main(int argc, char* argv[])
{
    pid_t pid = fork();
    if(pid == 0)
    {
        printf("---child,my parent = %d,going to sleep 10s\n",getppid());
        sleep(10);
        printf("---child die\n");
    }
    else if (pid > 0)
    {
        while(1)
        {
            printf("i'm parent,pid = %d,my son = %d\n",getpid(),pid);
            sleep(1);
        }
    }
    else if (pid < 0)
    {
        perror("fork error");
        return 1;
    }
    return 0;
}
