/*************************************************************************
 > File Name: pointer.cpp
 > Author: Catkin 
 > Created Time: Wed Mar  1 20:28:23 2023
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

int main(int argc, char* argv[])
{
    int a = 12 ;
    int *b = &a;
    int **c = &b;
    cout<<"a = "<<a<<endl;
    cout<<"&a = "<<&a<<endl;
    cout<<"b = "<<b<<endl;
    cout<<"&b = "<<&b<<endl;
    cout<<"*b = "<<*b<<endl;
    cout<<"c = "<<c<<endl;
    cout<<"&c = "<<&c<<endl;
    cout<<"*c = "<<*c<<endl;
    cout<<"**c = "<<**c<<endl;
}

