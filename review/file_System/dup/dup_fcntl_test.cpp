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
#define msg "i am lib\n"
int main(int argc, char* argv[])
{
    int fd = open(argv[1],O_RDONLY);
    if(fd<0)
    {
        perror("open error");
        exit(1);
    }
    int newfd = fcntl(fd,F_DUPFD,0);
    printf("newfd is = %d\n",newfd);
    int newfd2= fcntl(fd,F_DUPFD,9);
    printf("newfd is = %d\n",newfd2);

    int ret = write(newfd2,msg,strlen(msg));
    printf("ret = %d\n",ret);
    return 0;
}

