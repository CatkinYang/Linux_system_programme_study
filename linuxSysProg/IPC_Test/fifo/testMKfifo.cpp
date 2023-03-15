/*************************************************************************
 > File Name: testMKfifo.cpp
 > Author: Catkin 
 > Created Time: Fri Feb 24 20:40:28 2023
 ************************************************************************/
#include<errno.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
#include<iostream>
#include<sys/stat.h>
using namespace std;

void sys_err(const char *str)
{
    perror(str);
    exit(1);
}

int main(int argc, char* argv[])
{
    int ret = mkfifo("mytestfifo",0644);
    if(ret == -1)
    {
        sys_err("mkfifo error");
    }
    return 0;
}

