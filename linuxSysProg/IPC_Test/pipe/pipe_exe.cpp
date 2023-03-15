/*************************************************************************
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
int main(int argc, char* argv[])
{
    int ret;
    int fd[2];
    ret = pipe(fd);
    if(ret == -1)
        sys_err("pipe error");
    pid_t pid;
    pid = fork();
    char *str = "hello pipe\n";
    char buf[1024];
    if(pid > 0)//parent
    {
        close(fd[0]);//close read end
        sleep(2);
        // write(fd[1],str,strlen(str));
        close(fd[1]);
    }
    else if (pid == 0)//child
    {
        close(fd[1]);//close write end
        ret = read(fd[0],buf,sizeof(buf));
        printf("child read ret = %d\n", ret);
        write(STDOUT_FILENO,buf,ret);
        close(fd[0]);
    }
    else
    {
        sys_err("fork error");
    }

    return 0;
}

