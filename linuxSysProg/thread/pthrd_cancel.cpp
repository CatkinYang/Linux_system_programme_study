/*************************************************************************
 > File Name: pthread_creat.cpp
 > Author: Catkin 
 > Created Time: Wed Mar  1 18:48:19 2023
 ************************************************************************/

#include <cstdio>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
#include<iostream>
#include<errno.h>
#include<fcntl.h>
using namespace std;

void *tfn(void *arg)
{
    while(1){
     printf("thread: pid = %d,tid = %llu\n",getpid(),pthread_self());
     sleep(1);
    }
    return NULL;
}
int main(int argc, char* argv[])
{
    pthread_t tid;
    int ret = pthread_create(&tid,NULL,tfn,NULL);
    if(ret != 0)
    {
        fprintf(stderr,"pthread_create error:%s\n",strerror(ret));
        exit(1);
    }

    printf(" main: pid = %d,tid = %llu\n",getpid(),pthread_self());

    sleep(5);
    ret = pthread_cancel(tid);//end
    if(ret != 0)
    {
        fprintf(stderr,"pthread_cancel error:%s\n",strerror(ret));
        exit(1);
    }
    printf("pthread will be cancel");
    while(1);

    pthread_exit((void*)0);
}

