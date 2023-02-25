/************************************************************************
 > File Name: lseek.cpp
 > Author: Catkin 
 > Created Time: Sun Feb 19 10:08:05 2023
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
    int fd = open("lseek.txt",O_RDWR|O_CREAT,0644);
    if(fd < 0)
    {
        perror("open error");
        exit(1);
    }
    char msg[] = "my name is Catkin\n";
    write(fd,msg,strlen(msg));
    
    char ch;
    int n;
    lseek(fd,0,SEEK_SET);
    while(n == read(fd,&ch,1))
    {
        if(n<0)
        {
            perror("read error");
            exit(1);
        }
        write(STDOUT_FILENO,&ch,n);
    }
    close(fd);
    return 0;
}

