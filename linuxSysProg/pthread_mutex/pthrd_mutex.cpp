/*************************************************************************
 > File Name: pthrd_mutex.cpp
 > Author: Catkin 
 > Created Time: Fri Mar  3 21:33:06 2023
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
pthread_mutex_t mutex1;      // 定义一把互斥锁  


void *tfn(void *arg)  {  
    srand(time(NULL));  
    while (1) {  
        pthread_mutex_lock(&mutex1);     // 加锁  
        printf("hello ");  
        sleep(rand() % 3);  // 模拟长时间操作共享资源，导致cpu易主，产生与时间有关的错误  
        printf("world\n");  
        pthread_mutex_unlock(&mutex1);   // 解锁  
        sleep(rand() % 3);  
    }  
    return NULL;  
}  

int main(void)  
{  
    pthread_t tid;  
    srand(time(NULL));  
    int ret = pthread_mutex_init(&mutex1, NULL);    // 初始化互斥锁  
    if(ret != 0){  
        fprintf(stderr, "mutex init error:%s\n", strerror(ret));  
        exit(1);  
    }  
    pthread_create(&tid, NULL, tfn, NULL);  
    while (1) {  
        pthread_mutex_lock(&mutex1);     // 加锁  
        printf("HELLO ");  
        sleep(rand() % 3);  
        printf("WORLD\n");  
        pthread_mutex_unlock(&mutex1);   // 解锁  
        sleep(rand() % 3);  
    }  
    pthread_join(tid, NULL);  
    pthread_mutex_destroy(&mutex1);     // 销毁互斥锁  
    return 0;  
}  
