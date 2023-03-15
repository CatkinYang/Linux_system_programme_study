/*************************************************************************
 > File Name: pthrd_detach.cpp
 > Author: Catkin 
 > Created Time: Fri Mar  3 18:50:42 2023
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
void *tfn(void *arg)  {
    printf("thread: pid = %d, tid = %lu\n", getpid(), pthread_self());
    return NULL;
}

int main(int argc, char *argv[])
{
    pthread_t tid;
    int ret = pthread_create(&tid, NULL, tfn, NULL);
    if (ret != 0) {
        fprintf(stderr, "pthread_create error: %s\n", strerror(ret));
        exit(1);
    }
    ret = pthread_detach(tid);              // 设置线程分离` 线程终止,会自动清理pcb,无需回收
    if (ret != 0) {
        fprintf(stderr, "pthread_detach error: %s\n", strerror(ret));
        exit(1);
    }

    sleep(1);

    ret = pthread_join(tid, NULL);
    printf("join ret = %d\n", ret);
    if (ret != 0) {
        //perror("pthread_join error");  //perror方法无法检查线程错误
        fprintf(stderr, "pthread_join error: %s\n", strerror(ret));
        exit(1);
    }

    printf("main: pid = %d, tid = %lu\n", getpid(), pthread_self());
    pthread_exit((void *)0);
}

