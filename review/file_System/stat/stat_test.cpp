/*************************************************************************
 > File Name: stat_test.cpp
 > Author: Catkin 
 > Created Time: Sun Feb 19 11:44:30 2023
 ************************************************************************/
#include<sys/stat.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
#include<iostream>
using namespace std;

int main(int argc, char* argv[])
{
    struct stat sb;
    int ret = stat(argv[1],&sb);
    if(ret == -1)
    {
        perror("stat error");
        exit(1);
    }

    if(S_ISREG(sb.st_mode))
    {
        printf("it is a regular\n");
    }
    if(S_ISDIR(sb.st_mode))
    {
        printf("it is a dir\n");
    }
    if(S_ISLNK(sb.st_mode))
    {
        printf("it is a link\n");
    }
    if(S_ISFIFO(sb.st_mode))
    {
        printf("it is a fifo\n");
    }
    return 0;
}

