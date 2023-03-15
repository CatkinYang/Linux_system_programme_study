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
    int i,n;
    char buf[1024];
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
        write(fd[1],"1.hello\n",strlen("1.hello\n"));
    }
    if(i == 1)//little brother wc -l close write end and dup2()
    {
        close(fd[0]);
        write(fd[1],"2.world\n",strlen("2.world\n"));
    }
    if(i == 2)//parent process : wait()
    {
       close(fd[1]);
       sleep(1);
       n = read(fd[0],buf,1024);
       write(STDOUT_FILENO,buf,n);
       for(i = 0;i < 2; i++)
       {
           wait(NULL);
       }
    }
    return 0;
}

