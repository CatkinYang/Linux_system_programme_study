/*************************************************************************
 > File Name: client.cpp
 > Author: Catkin 
 > Created Time: Thu Mar  9 13:13:37 2023
 ************************************************************************/
#include<arpa/inet.h>
#include <cstdio>
#include <netinet/in.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <strings.h>
#include <sys/_endian.h>
#include<unistd.h>
#include<pthread.h>
#include<iostream>
#include<errno.h>
#include<fcntl.h>
#include<sys/socket.h>
using namespace std;
#define SERV_PORT 7777
#define SERV_IP "127.0.0.1"
//socket() connect()
int main(int argc, char* argv[])
{
    char buf[BUFSIZ];
    int sfd,len;

    struct sockaddr_in serv_addr;
    bzero(&serv_addr,sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    inet_pton(AF_INET,SERV_IP,&serv_addr.sin_addr.s_addr);
    serv_addr.sin_port = htons(SERV_PORT);
    
    sfd = socket(AF_INET,SOCK_STREAM,0);
    connect(sfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr));
    
    while(1)
    {
        fgets(buf,sizeof(buf),stdin);
        write(sfd,buf,strlen(buf));
        len=read(sfd,buf,sizeof(buf));
        write(STDOUT_FILENO,buf,len);
    }
    
    close(sfd);
    return 0;
}

