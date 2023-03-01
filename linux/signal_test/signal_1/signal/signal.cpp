/*************************************************************************
 > File Name: signal.cpp
 > Author: Catkin 
 > Created Time: Mon Feb 27 20:47:26 2023
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
#include<iostream>
#include<errno.h>
#include<fcntl.h>
#include<signal.h>
using namespace std;

void sys_err(const char *str)
{
    perror(str);
    exit(1);
}

void sig_cath(int signo)
{
    printf("catch you!! %d\n",signo);
    return ;
}
int main(int argc, char* argv[])
{

    signal(SIGINT,sig_cath);
    while(1);
    return 0;
}

