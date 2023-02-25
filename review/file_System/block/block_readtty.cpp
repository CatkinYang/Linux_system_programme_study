/*************************************************************************
 > File Name: block_readtty.cpp
 > Author: Catkin 
 > Created Time: Sat Feb 18 21:51:48 2023
 ************************************************************************/

#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
#include<iostream>
using namespace std;

int main(int argc, char* argv[])
{
    int fd = open("/dev/tty",O_RDWR);
    if(fd<0)
    {
        perror("open error");
        exit(1);
    }
    char buf[10];
    int ret = read(fd,buf,10);
    if(ret>0)
    {
        write(STDOUT_FILENO,buf,10);
    }

    return 0;
}

