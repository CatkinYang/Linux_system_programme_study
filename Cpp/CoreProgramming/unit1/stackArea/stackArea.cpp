/*************************************************************************
 > File Name: stackArea.cpp
 > Author: Catkin 
 > Created Time: Sun Feb 26 12:57:51 2023
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
#include<iostream>
using namespace std;
int * func(int b)
{
    b = 100;
    int a = 10; //局部变量 存放在栈区，栈区的数据在函数执行完后自动释放
    return &a;//返回局部变量的地址
}

int main() {
    //接受func函数的返回值
    int *p = func(1);
    cout << *p << endl;//   第一次可以打印正确的数字是因为 编译器做了保留
    cout << *p << endl;//   第二次这个数据就不再保留
    return 0;
}
