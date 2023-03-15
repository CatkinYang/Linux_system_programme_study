/*************************************************************************
 > File Name: pipe_bro.cpp
 > Author: Catkin 
 > Created Time: Fri Feb 24 19:41:07 2023
 ************************************************************************/
#include<errno.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
#include<iostream>
using namespace std;

// old brother : exec ls
// little brother : exec wc -l
// parent : wait child process
// fork()
// pipe()

void sys_err(const char* str)
{
    perror(str);
    exit(1);
}

int main(int argc, char* argv[])
{
    int fd[2];
    int ret;
    ret = pipe(fd);
    if(ret == -1)
    {
        sys_err("pipe error");
    }
    int i;
    pid_t pid,wpid;
    for(i = 0; i < 2; i++)// expression 2 exit only for father process
    {
        pid = fork();
        if(pid == 0) //child process 
            break;
    }
    if(i == 0)//old brother ls close read end and dup2()
    {
        close(fd[0]);
        dup2(fd[1],STDOUT_FILENO);
        execlp("ls","ls",NULL);
        sys_err("exec error");
    }
    if(i == 1)//little brother wc -l close write end and dup2()
    {
        close(fd[1]);
        dup2(fd[0],STDIN_FILENO);
        execlp("wc","wc","-l",NULL);
        sys_err("exec error");
    }
    if(i == 2)//parent process : wait()
    {
       close(fd[0]);
       close(fd[1]);
       wait(NULL);
       wait(NULL);
    }
    return 0;
}

