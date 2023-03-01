/*************************************************************************
 > File Name: alarm.cpp
 > Author: Catkin 
 > Created Time: Sun Feb 26 21:52:48 2023
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
#include<iostream>
#include<errno.h>
#include<signal.h>
using namespace std;

int main(int argc, char* argv[])
{
    int i;
    alarm(1);
    for(i = 0;;i++)
        printf("%d\n",i);
    return 0;
}

