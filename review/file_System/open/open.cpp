/*************************************************************************
 > File Name: open.cpp
 > Author: Catkin 
 > Created Time: Sat Feb 18 16:59:08 2023
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
    int fd = open("test.txt",O_RDWR|O_CREAT,0644);
    if(fd<0)
    {
        perror("open error");
        exit(1);
    }
    close(fd);
    return 0;
}

