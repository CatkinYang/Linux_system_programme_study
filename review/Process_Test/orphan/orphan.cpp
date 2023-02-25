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
    if(pid<0 )
    {
        perror("fork error");
        return 1;
    }
    else if (pid == 0)
    {
        while(1)
        {
            printf("i'm child,my parent pid = %d\n,my pid is %d\n",getppid(),getpid());
            sleep(1);
        }
    }
    else if (pid > 0)
    {
        printf("i am parent,my pid is = %d\n",getpid());
        sleep(9);
        printf("-----parent going to die\n");
    }
    return 0;
}
