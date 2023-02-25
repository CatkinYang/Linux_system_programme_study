/*************************************************************************
 > File Name: link.cpp
 > Author: Catkin 
 > Created Time: Sun Feb 19 12:54:00 2023
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
#include<iostream>
using namespace std;

int main(int argc, char* argv[])
{
    int ret = link(argv[1],argv[2]);
    if(ret == -1)
    {
        perror("link error");
        exit(1);
    }

    return 0;
}

