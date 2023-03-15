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

void func(void)
{
    pthread_exit(NULL);//讲当前线程退出
}
void *tfn(void *arg)
{
    int i = (int)(size_t)arg;
    sleep(i);
    if( i == 2)
    {
        // exit(0);// 表示退出进程
        // return NULL; //表示返回到函数调用者那里去
        // func();
        pthread_exit(NULL);//讲当前线程退出

    }
    printf("--i am %dth thread: pid = %d,tid = %lu\n",i+1,getpid(),pthread_self());
    return NULL;
}
int main(int argc, char* argv[])
{
    int i,ret;
    pthread_t tid;

    for(i = 0;i<5;i++)
    {
        ret = pthread_create(&tid,NULL,tfn,(void *)i);
        if(ret != 0)
        {
            sys_err("pthread_create error");
        }
    }
    sleep(i);
    printf("main: i am main: pid = %d,tid = %lu\n",getpid(),pthread_self());

    return 0;
}

