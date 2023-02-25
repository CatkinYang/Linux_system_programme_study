/*************************************************************************
 > File Name: unlink.cpp
 > Author: Catkin 
 > Created Time: Sun Feb 19 13:16:03 2023
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
    char p1[] = "test of unlink";
    char p2[] = "after write something";
    int fd1;
    fd1=open("test.txt",O_RDWR | O_CREAT | O_TRUNC,0644);
    if(fd1<0)
    {
        perror("open error");
        exit(1);
    }
    int ret;
    ret = write(fd1,p1,strlen(p1));
    if(ret == -1)
    {
        printf("---write error");
    }
    ret = write(fd1,p2,strlen(p2));
    if(ret == -1)
    {
        printf("---write error");
    }
    
    printf("---enter antkey continue");
    getchar();

    ret = unlink("test.txt");
    if(ret < 0)
    {
        perror("unlink error");
        exit(1);
    }

    close(fd1);
    return 0;

}

