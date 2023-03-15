/*************************************************************************
  > File Name: heapArea.cpp
  > Author: Catkin 
  > Created Time: Sun Feb 26 13:07:41 2023
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
#include<iostream>
using namespace std;

int* func()
{
    //利用new关键字 可以将数据开辟到堆区
    //指针本质也是局部变量，放在栈上
    int* a = new int(10);
    return a;
}

int main() {
    //在堆区开辟数据
    int *p = func();

    cout << *p << endl;
    cout << *p << endl;
    cout << *p << endl;
    cout << *p << endl;
    return 0;
}
