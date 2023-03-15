/*************************************************************************
  > File Name: pthread_join.cpp
  > Author: Catkin 
  > Created Time: Wed Mar  1 21:15:18 2023
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

struct thrd {  
    int var;  
    char str[256];  
};  

void sys_err(const char *str)  {  
    perror(str);  
    exit(1);  
}  

void *tfn(void *arg)  {  
    struct thrd *tval;  

    tval = static_cast<struct thrd*>(malloc(sizeof(tval)));  
    tval->var = 100;  
    strcpy(tval->str, "hello thread");  

    return (void *)tval;  
}  

int main(int argc, char *argv[])  
{  
    pthread_t tid;  

    struct thrd *retval;  

    int ret = pthread_create(&tid, NULL, tfn, NULL);  
    if (ret != 0)  
        sys_err("pthread_create error");  

    //int pthread_join(pthread_t thread, void **retval);  
    ret = pthread_join(tid, (void **)&retval);  
    if (ret != 0)  
        sys_err("pthread_join error");  

    printf("child thread exit with var= %d, str= %s\n", retval->var, retval->str);  

    pthread_exit(NULL);  

}  


