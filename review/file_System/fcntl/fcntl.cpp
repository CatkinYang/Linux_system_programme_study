/************************************************************************
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
    int flags = fcntl(STDIN_FILENO,F_GETFL);
    if(flags == -1)
    {
        perror("fcntl error");
        exit(1);
    }

    flags |= O_NONBLOCK;
    char buf[10];
    int i=0;
    int ret = fcntl(STDIN_FILENO,F_SETFL,flags);
    if(ret == -1)
    {
        perror("fcntl error");
        exit(1);
    }
    int res = read(STDIN_FILENO,buf,10);
    while(res<0 && i++ < 5)
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
        res = read(STDIN_FILENO,buf,10);
    }
    write(STDOUT_FILENO,buf,res);
    return 0;
}

