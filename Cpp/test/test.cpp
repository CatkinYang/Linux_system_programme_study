/*************************************************************************
  > File Name: test.cpp
  > Author: Catkin 
  > Created Time: Thu Mar  9 23:05:57 2023
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
#include<iostream>
#include<errno.h>
#include<fcntl.h>
#include<sys/socket.h>
using namespace std;
class Test
{
public:
    Test()
    {
        m_x = 1;
        m_y = 2;
        cout<<"this is default construct func"<<"x= "<<m_x<<"y= "<<m_y<<endl;
    }
    Test(int x,int y)
    {
        m_x = x;
        m_y = y;
        cout<<"this is construct func"<<"x= "<<m_x<<"y= "<<m_y<<endl;
    }
    Test(const Test &another)
    {
        m_x = another.m_x;
        m_y = another.m_y;
        cout<<"this is dup construct func"<<"x= "<<m_x<<"y= "<<m_y<<endl;
    }
    ~Test()
    {
        cout<<"this is delete func"<<endl;
    }
private:
    int m_x,m_y;
};
void test1()
{
    Test t1(10,10);
    Test t2(t1);
}
void test2()
{
    Test t1(10,10);
    Test t2;
    t2=t1;
}
int main(int argc, char* argv[])
{
    // test1();
    test2();
    return 0;
}

