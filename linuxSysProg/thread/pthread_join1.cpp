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

void sys_err(const char *str)  {  
    perror(str);  
    exit(1);  
}  

void *tfn(void *arg)  {  

    return (void *)74;  
}  

int main(int argc, char *argv[])  
{  
    pthread_t tid;  

    int *retval;  

    int ret = pthread_create(&tid, NULL, tfn, NULL);  
    if (ret != 0)  
        sys_err("pthread_create error");  

    ret = pthread_join(tid, (void **)&retval);  
    if (ret != 0)  
        sys_err("pthread_join error");  

    printf("child thread exit with var= %d\n",(void *)retval);  

    pthread_exit(NULL);  

}  


