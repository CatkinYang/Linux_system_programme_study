/*************************************************************************
 > File Name: exec_ps.cpp
 > Author: Catkin 
 > Created Time: Sat Feb 18 13:04:36 2023
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
    int fd;
    
    fd = open("ps.out",O_WRONLY|O_CREAT|O_TRUNC,0644);
    if(fd<0)
    {
        perror("open ps.out error");
        exit(1);
    }

    dup2(fd,STDOUT_FILENO);
    execlp("ps","ps","ax",NULL);
    perror("execlp error");
    close(fd);
    return 0;
}

