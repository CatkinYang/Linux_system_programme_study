/*************************************************************************
 > File Name: mycp.cpp
 > Author: Catkin 
 > Created Time: Sat Feb 18 17:09:37 2023
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
#include<iostream>
#include<fcntl.h>
using namespace std;

int main(int argc, char* argv[])
{
    int fd1 = open(argv[1],O_RDWR);
    if(fd1<0)
    {
        perror("open error");
        exit(1);
    }
    int fd2 = open(argv[2],O_RDWR|O_CREAT|O_TRUNC,0644);
    if(fd2<0)
    {
        perror("open error");
        exit(1);
    }
    char buf[1024];
    int n;
    while((n=read(fd1,buf,1024))>0)
    {
        printf("%d\n",n);
        write(fd2,buf,n);
    }
    close(fd1);
    close(fd2);
    return 0;
}

