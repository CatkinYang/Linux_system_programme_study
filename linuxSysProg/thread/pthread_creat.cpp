/*************************************************************************
 > File Name: pthread_creat.cpp
 > Author: Catkin 
 > Created Time: Wed Mar  1 18:48:19 2023
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
#include<iostream>
#include<errno.h>
#include<fcntl.h>
using namespace std;

void sys_err(const char *str)
{
    perror(str);
    exit(1);
}

void *tfn(void *arg)
{
    printf("thread: pid = %d,tid = %llu\n",getpid(),pthread_self());
    return NULL;
}
int main(int argc, char* argv[])
{
    pthread_t tid;
    printf(" main: pid = %d,tid = %llu\n",getpid(),pthread_self());

    int ret =  pthread_create(&tid,NULL,tfn,NULL);
    if(ret != 0)
    {
        perror("pthread_create error");
    }
    // sleep(1);
    // return 0;
    pthread_exit((void*) 0);
}

