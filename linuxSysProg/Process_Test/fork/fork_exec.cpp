/*************************************************************************
 > File Name: fork.c
 > Author: Catkin 
 > Created Time: Sat Feb 18 10:11:24 2023
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>

int main(int argc, char* argv[])
{
    pid_t pid = fork();
    if(pid == -1)
    {
        perror("fork error");
        exit(1);
    }
    else if (pid == 0)
    {
       // execlp("ls","ls","-l","-d","-h",NULL); 

       // execlp("date","date",NULL); 

       execl("./a.out","./a.out",NULL);
       perror("exec error");
       exit(1);
    }
    else if (pid > 0)
    {
        sleep(1);
        printf("I'm parent : %d\n",getpid());
    }


    return 0;
}
