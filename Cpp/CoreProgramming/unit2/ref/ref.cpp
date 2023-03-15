/*************************************************************************
 > File Name: ref.cpp
 > Author: Catkin 
 > Created Time: Sun Feb 26 13:51:15 2023
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
#include<iostream>
using namespace std;
//引用必须初始化
//引用在初始化后 不可以改变
int main() {
    int a = 10;
    int &b = a;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    b = 100;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    return 0;
}

