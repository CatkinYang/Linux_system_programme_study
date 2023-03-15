/*************************************************************************
 > File Name: ref_test.cpp
 > Author: Catkin 
 > Created Time: Sun Feb 26 13:53:41 2023
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
#include<iostream>
using namespace std;
// 1. 值传递
void mySwap01(int a, int b) {

    int temp = a;
    a = b;
    b = temp;
}

// 2. 地址传递
void mySwap02(int* a, int* b) {

    int temp = *a;
    *a = *b;
    *b = temp;
}

//3. 引用传递
void mySwap03(int& a, int& b) {

    int temp = a;
    a = b;
    b = temp;
}

int main() {

    int a = 10;
    int b = 20;

    mySwap01(a, b);
    cout << "a:" << a << " b:" << b << endl;

    mySwap02(&a, &b);
    cout << "a:" << a << " b:" << b << endl;

    mySwap03(a, b);
    cout << "a:" << a << " b:" << b << endl;

    return 0;
}

