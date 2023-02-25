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

int main(int argc, char* argv[])
{
    int i;
    for(i=0;i<5;i++)
    {
        pid_t pid = fork();
        if(pid == 0 )
            break;
    }
    if(i == 5)
    {
        sleep(5);
        printf("i'm parent\n");
    }else 
    {
        sleep(i);
        printf("i'm %dth child\n",i+1);

    }
    return 0;
}
