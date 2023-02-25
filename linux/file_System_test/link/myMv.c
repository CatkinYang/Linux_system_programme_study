/*************************************************************************
 > File Name: myMv.c
 > Author: Catkin 
 > Created Time: Thu Feb 16 21:03:48 2023
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>

int main(int argc, char* argv[])
{
    link(argv[1],argv[2]);
    
    unlink(argv[1]);
    return 0;
}
