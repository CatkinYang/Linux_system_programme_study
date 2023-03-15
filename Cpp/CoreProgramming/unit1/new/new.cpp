/*************************************************************************
 > File Name: new.cpp
 > Author: Catkin 
 > Created Time: Sun Feb 26 13:20:42 2023
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
    int* a = new int(10);
    return a;
}
//new的基本语法
void test01() {
    int *p = func();
    cout << *p << endl;
    cout << *p << endl;
    //利用delete释放堆区数据
    delete p;
    cout << *p << endl; //报错，释放的空间不可访问
}
//开辟数组
void test02()
{
    //创建10整型数据的数组，在堆区
    int * arr = new int[10];
    for(int i = 0;i<10;i++)
    {
        arr[i] = i + 100;
    }
    for(int i =0;i<10;i++)
    {
        cout << arr[i] << endl;
    }
    //释放堆区数组
    delete [] arr;

}
int main()
{
    // test01();
    test02();
    return 0;
}
