/*************************************************************************
 > File Name: fork_mmap.cpp
 > Author: Catkin 
 > Created Time: Sat Feb 25 10:49:55 2023
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
#include<sys/mman.h>
#include<iostream>
#include<errno.h>
#include<fcntl.h>
using namespace std;

int var = 100;
int main(int argc, char* argv[])
{
    int *p;
    pid_t pid;
    int fd;
    fd = open("temp",O_RDWR|O_CREAT|O_TRUNC,0644);
    if(fd<0)
    {
        perror("open error");
        exit(1);
    }
    ftruncate(fd,4);

    // p = (int*)mmap(NULL,4,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
    p = (int*)mmap(NULL,4,PROT_READ|PROT_WRITE,MAP_PRIVATE,fd,0);

    if(p == MAP_FAILED)
    {
        perror("mmap error");
        exit(1);
    }
    close(fd);

    pid = fork();
    if(pid == 0)
    {
        *p = 7000;//写共享内存
        var = 1000;
        printf("child,*p = %d,var = %d\n",*p,var);
    }
    else
    {
        sleep(1);
        printf("parent,*p = %d,var = %d\n",*p,var);//读共享内存
        wait(NULL);

        int ret = munmap(p,4);
        if(ret == -1)
        {
            perror("munmap error");
            exit(1);
        }

    }
    return 0;
}

