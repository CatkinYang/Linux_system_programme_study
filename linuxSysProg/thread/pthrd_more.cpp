/*************************************************************************
 > File Name: pthrd_more.cpp
 > Author: Catkin 
 > Created Time: Wed Mar  1 19:41:15 2023
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

void sys_err(const char *str) {  
    perror(str);  
    exit(1);  
}  

void *tfn(void *arg){  
    int i = (uintptr_t)arg;  
    sleep(i);  
    printf("--I'm %dth thread: pid = %d, tid = %llu\n",i+1, getpid(), pthread_self());  

    return NULL;  
}  

int main(int argc, char *argv[]){  
    int i;  
    int ret;  
    pthread_t tid;  

    for(i=0;i<5;i++){  
        ret = pthread_create(&tid, NULL, tfn, (void *)i);  //直接传值不是传地址
        if (ret != 0) {  
            sys_err("pthread_create error");  
        }  
    }  
    sleep(i);  //主进程最后退出
    printf("I'm main, pid = %d, tid = %lu\n", getpid(), pthread_self());  

    return 0;  
}  
