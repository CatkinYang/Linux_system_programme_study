/*************************************************************************
 > File Name: myMy.cpp
 > Author: Catkin 
 > Created Time: Sun Feb 19 13:52:21 2023
 ************************************************************************/
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
#include<iostream>
using namespace std;

int main(int argc, char* argv[])
{
    //mv argv[1] argv[2]
    link(argv[1],argv[2]);
    unlink(argv[1]);
    
    return 0;
}

