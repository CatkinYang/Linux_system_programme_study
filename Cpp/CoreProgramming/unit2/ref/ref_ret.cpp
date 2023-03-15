/*************************************************************************
 > File Name: ref_ret.cpp
 > Author: Catkin 
 > Created Time: Sun Feb 26 14:17:09 2023
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
#include<iostream>
using namespace std;

//返回局部变量引用
int& test01() {

    int a = 10; //局部变量 放在栈区
    return a;
}

//返回静态变量引用 函数调用可以作为左值
int& test02() {

    static int a = 20;//静态变量 存放在全局区 全局区的数据在程序结束后系统释放
    return a;
}

int main() {


    //不能返回局部变量的引用
    int& ref = test01();
    cout << "ref = " << ref << endl;//第一次结果正确
    cout << "ref = " << ref << endl;//第二次错误，a的内存已经释放

    //如果函数做左值，那么必须返回引用
    int& ref2 = test02();
    cout << "ref2 = " << ref2 << endl;
    cout << "ref2 = " << ref2 << endl;

    test02() = 1000;

    cout << "ref2 = " << ref2 << endl;
    cout << "ref2 = " << ref2 << endl;

    return 0;
}
