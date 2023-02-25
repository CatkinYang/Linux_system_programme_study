/*************************************************************************
 > File Name: dup2.cpp
 > Author: Catkin 
 > Created Time: Sun Feb 19 14:58:42 2023
 ************************************************************************/
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
#include<iostream>
using namespace std;
#define msg "i am catkin and i am lib\n"
int main(int argc, char* argv[])
{
    int fd1 = open(argv[1],O_RDWR); 
    int fd2 = open(argv[2],O_RDWR);
    int fdret = dup2(fd1,fd2);
    printf("fdret = %d\n",fdret);

    int ret = write(fd2,msg,strlen(msg));
    printf("ret = %d\n",ret);
    return 0;
}

