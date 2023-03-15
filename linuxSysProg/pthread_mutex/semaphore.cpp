/*************************************************************************
 > File Name: semaphore.cpp
 > Author: Catkin 
 > Created Time: Sat Mar  4 12:57:52 2023
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
#include<iostream>
#include<errno.h>
#include<fcntl.h>
#include<semaphore.h>
using namespace std;
#define NUM 5                 

int queue[NUM];                                     //全局数组实现环形队列  
sem_t blank_number, product_number;                 //空格子信号量, 产品信号量  

void *producer(void *arg)  {  
    int i = 0;  
    while (1) {  
        sem_wait(&blank_number);                    //生产者将空格子数--,为0则阻塞等待  
        queue[i] = rand() % 1000 + 1;               //生产一个产品  
        printf("----Produce---%d\n", queue[i]);          
        sem_post(&product_number);                  //将产品数++  

        i = (i+1) % NUM;                            //借助下标实现环形  
        sleep(rand()%1);  
    }  
}  

void *consumer(void *arg)  {  
    int i = 0;  
    while (1) {  
        sem_wait(&product_number);                  //消费者将产品数--,为0则阻塞等待  
        printf("-Consume---%d\n", queue[i]);  
        queue[i] = 0;                               //消费一个产品   
        sem_post(&blank_number);                    //消费掉以后,将空格子数++  

        i = (i+1) % NUM;  
        sleep(rand()%3);  
    }  
}  

int main(int argc, char *argv[])  
{  
    sem_init(&blank_number, 0, NUM);                //初始化空格子信号量为5, 线程间共享 -- 0  
    sem_init(&product_number, 0, 0);                //产品数为0  

    pthread_t pid, cid;  
    pthread_create(&pid, NULL, producer, NULL);  
    pthread_create(&cid, NULL, consumer, NULL);  

    pthread_join(pid, NULL);  
    pthread_join(cid, NULL);   
    sem_destroy(&blank_number);  
    sem_destroy(&product_number);  
    return 0;  
}  



