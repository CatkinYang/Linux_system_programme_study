/*************************************************************************
 > File Name: nonblock_readtty.cpp
 > Author: Catkin 
 > Created Time: Sat Feb 18 21:51:48 2023
 ************************************************************************/

#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
#include<iostream>
using namespace std;
#define MSG_TRY "try again\n"
#define MSG_TIMEOUT "time out\n"

int main(int argc, char* argv[])
{
    int fd = open("/dev/tty",O_RDWR|O_NONBLOCK);
    if(fd<0)
    {
        perror("open error");
        exit(1);
    }
    char buf[10];
    int i=0;
    int ret = read(fd,buf,10);
    while(ret<0 && i++ < 5)
    {
        if(errno != EAGAIN)
        {
            perror("read /dev/tty");
            exit(1);
        }
        else
        {
            write(STDOUT_FILENO,MSG_TRY,strlen(MSG_TRY));
            sleep(2);
        }
        ret = read(fd,buf,10);
    }
    if(i == 4)
         write(STDOUT_FILENO,MSG_TIMEOUT,strlen(MSG_TIMEOUT));
    else
         write(STDOUT_FILENO,buf,ret);
    close(fd);
    return 0;
}

