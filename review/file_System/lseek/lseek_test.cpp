/*************************************************************************
 > File Name: lseek_test.cpp
 > Author: Catkin 
 > Created Time: Sun Feb 19 10:54:10 2023
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
    int fd = open(argv[1],O_RDWR);
    if(fd == -1)
    {
        perror("open error");
        exit(1);
    }
    int length = lseek(fd,101,SEEK_END);
    printf("file size: %d\n",length);
    write(fd,"$",1);
    close(fd);
    return 0;
}

