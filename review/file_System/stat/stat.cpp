/*************************************************************************
 > File Name: stat.cpp
 > Author: Catkin 
 > Created Time: Sun Feb 19 11:20:38 2023
 ************************************************************************/
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
#include<iostream>
#include<sys/stat.h>
using namespace std;

int main(int argc, char* argv[])
{
    int ret;
    struct stat sb;
    ret = stat(argv[1],&sb);
    if(ret == -1)
    {
        perror("stat error");
        exit(1);
    }
    printf("file size: %lld\n",sb.st_size);
    return 0;
}

