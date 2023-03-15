/*************************************************************************
  > File Name: server.c
  > Author: Catkin 
  > Created Time: Thu Mar  9 15:00:25 2023
 ************************************************************************/
#include<arpa/inet.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <sys/_endian.h>
#include <sys/_types/_pid_t.h>
#include <sys/_types/_socklen_t.h>
#include <sys/signal.h>
#include <sys/wait.h>
#include<unistd.h>
#include<ctype.h>
#include<pthread.h>
#include<sys/socket.h>
#include<signal.h>
#include "wrap.h"
#define SERV_PORT 8000
#define MAXLINE 8192
//多进程服务器 服务器端 每收到一个客户端请求，就建立一个子进程来为其服务
//子进程继承父进程的套接字，应该将监听套接字关闭
//父进程应该将connect套接字关闭，只保留listen套接字
//子进程结束时，应该回收
//socket() bind() listen() accept() 
//回调函数完成子进程回收
void waitProcess(int num)
{
    while(waitpid(0,NULL,WNOHANG)>0);
}
int main(int argc, char* argv[])
{
    struct sigaction newact;
    newact.sa_handler = waitProcess;
    sigemptyset(&newact.sa_mask);
    sigaction(SIGCHLD,&newact,NULL);

    int lfd,cfd;
    char buf[BUFSIZ];
    char CLT_IP[BUFSIZ];
    lfd = Socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in serv_addr,clt_addr;//定义一个服务器地址结构体

    bzero(&serv_addr,sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port =htons(SERV_PORT);
    serv_addr.sin_addr.s_addr =htonl(INADDR_ANY);

    socklen_t clt_addr_len;
    clt_addr_len = sizeof(clt_addr);

    Bind(lfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr));

    Listen(lfd,128);

    printf("waiting for client connect------\n");

    pid_t pid;
    while(1)
    {
        cfd = Accept(lfd,(struct sockaddr*)&clt_addr,&clt_addr_len);
        pid = fork();
        if(pid == 0)//child process
        {
            close(lfd);
            while(1){
                printf("i'm child process:%d\t,handle the client IP:%s\t PORT:%d\n",
                        getpid(),
                        inet_ntop(AF_INET,&clt_addr.sin_addr,CLT_IP,sizeof(CLT_IP)),
                        ntohs(clt_addr.sin_port)
                      );
                int n = Read(cfd,buf,MAXLINE);
                if(n == 0)
                {
                    printf("the other side has been closed\n");
                    break;
                }
                for(int i=0;i<n;i++)
                    buf[i] = toupper(buf[i]);
                Write(STDOUT_FILENO,buf,n);
                Write(cfd,buf,n);
            }
            Close(cfd);
            return 0;
        }
        else if(pid > 0)
        {
            close(cfd);
        }
        else 
        {
            perr_exit("fork");
        }
    
    } 
    return 0;
}















