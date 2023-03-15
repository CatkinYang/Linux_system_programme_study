/*************************************************************************
 > File Name: setitimer_alarm.cpp
 > Author: Catkin 
 > Created Time: Sun Feb 26 22:15:39 2023
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
#include<iostream>
#include<sys/time.h>
using namespace std;
int main(int argc, char* argv[])
{
    struct itimerval it,old;
    setitimer(ITIMER_REAL,&it,&old);
    it.it_value.tv_sec = 1;
    it.it_value.tv_usec = 0;
    it.it_interval.tv_sec = 0;
    it.it_interval.tv_usec = 0;
   
    if((setitimer(ITIMER_REAL,&it,&old)) == -1)
    {
        perror("set error");
        exit(1);
    }
    for(int i =0;;i++)
    {
        printf("%d\n",i);
    }
    return 0;
}

