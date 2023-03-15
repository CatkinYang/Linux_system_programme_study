/************************************************************************
 > File Name: pipe.cpp
 > Author: Catkin 
 > Created Time: Fri Feb 24 15:51:10 2023
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
#include<iostream>
#include<errno.h>
using namespace std;

void sys_err(const char *str)
{
    perror(str);
    exit(1);
}

// ls | wc -l
int main(int argc, char* argv[])
{
    int ret;
    int fd[2];
    ret = pipe(fd);
    if(ret == -1)
        sys_err("pipe error");
    pid_t pid;
    pid = fork();
    char buf[1024];

    if(pid > 0)//parent exec wc -l
    {
        
        close(fd[1]);//close write end
        dup2(fd[0],STDIN_FILENO);
        execlp("wc","wc","-l",NULL);
        sys_err("exec error");

    }

    else if (pid == 0)//child exec ls
    {
 
        close(fd[0]);//close read end
        dup2(fd[1],STDOUT_FILENO);
        execlp("ls","ls",NULL);
        sys_err("exec error");

    }

    else
    {
        sys_err("fork error");
    }

    return 0;
}

