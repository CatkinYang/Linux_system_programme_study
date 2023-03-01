/*************************************************************************
 > File Name: alarm_test.cpp
 > Author: Catkin 
 > Created Time: Sun Feb 26 22:01:37 2023
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
#include<iostream>
using namespace std;

int main(int argc, char* argv[])
{
    int temp;
    alarm(5);
    sleep(3);
    temp = alarm(4);
    cout<<temp<<endl;
    sleep(5);
    temp = alarm(5);
    cout<<temp<<endl;
    temp = alarm(0);
    cout<<temp<<endl;
    return 0;
}

