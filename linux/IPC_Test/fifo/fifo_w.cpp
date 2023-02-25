/*************************************************************************
 > File Name: fifo_w.cpp
 > Author: Catkin 
 > Created Time: Fri Feb 24 20:49:46 2023
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
#include<iostream>
#include<fcntl.h>
using namespace std;
void sys_err(const char *str)
{
    perror(str);
    exit(1);
}
int main(int argc, char* argv[])
{
    int fd , i;
    char buf[4096];

    if(argc < 2)
    {
        printf("enter like this : ./a.out fifoname\n");
        return -1;
    }
    fd = open(argv[1],O_WRONLY);
    if(fd < 0)
        sys_err("open");

    i = 0;
    while(1)
    {
        sprintf(buf,"hello catkin %d\n",i++);
        write(fd,buf,strlen(buf));
        sleep(1);
    }
    close(fd);
    return 0;
}

