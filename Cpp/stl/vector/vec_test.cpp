/*************************************************************************
 > File Name: vec_test.cpp
 > Author: Catkin 
 > Created Time: Tue Feb 28 12:41:19 2023
 ************************************************************************/
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
#include<iostream>
#include<errno.h>
#include<fcntl.h>
using namespace std;
void printVector(vector<int>& v) {

    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {

        cout << *it << " ";
    }
    cout << endl;
}

//赋值操作
void test01()
{

    vector<int> v1; //无参构造
    for (int i = 0; i < 10; i++)
    {

        v1.push_back(i);
    }
    printVector(v1);

    vector<int>v2;
    v2 = v1;
    printVector(v2);

    vector<int>v3;
    v3.assign(v1.begin(), v1.end());
    printVector(v3);

    vector<int>v4;
    v4.assign(10, 100);
    printVector(v4);
}

int main() {

    test01();

    return 0;
}

