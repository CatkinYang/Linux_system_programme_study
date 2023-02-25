/************************************************************************
 > File Name: dup.cpp
 > Author: Catkin 
 > Created Time: Sun Feb 19 14:53:37 2023
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
    int fd = open(argv[1],O_RDONLY);
    if(fd<0)
    {
        perror("open error");
        exit(1);
    }
    int newfd = fcntl(fd,F_DUPFD,0);
    printf("newfd is = %d",newfd);
    return 0;
}

