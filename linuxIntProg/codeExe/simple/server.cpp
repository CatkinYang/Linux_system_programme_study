/*************************************************************************
 > File Name: server.c
 > Author: Catkin 
 > Created Time: Thu Mar  9 12:20:42 2023
 ************************************************************************/

#include <netinet/in.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <sys/_endian.h>
#include <sys/_types/_socklen_t.h>
#include<unistd.h>
#include<ctype.h>
#include<pthread.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#define SERV_PORT 7777

//socket() bind() listen() accept() 
int main(int argc, char* argv[])
{
    int lfd,cfd,len;
    char buf[BUFSIZ],clt_IP[BUFSIZ];

    struct sockaddr_in serv_addr,clt_addr;//定义地址结构体
    socklen_t clt_addr_len;

    lfd = socket(AF_INET,SOCK_STREAM,0);
    
    bzero(&serv_addr,sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERV_PORT);
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    
    bind(lfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr));
    
    listen(lfd,128);
    printf("waiting for client connecat\n");
    
    clt_addr_len = sizeof(clt_addr);

    cfd = accept(lfd,(struct sockaddr *)&clt_addr,&clt_addr_len);
    printf("client IP:%s\t,Port:%d\n",
            inet_ntop(AF_INET,&clt_addr.sin_addr.s_addr,clt_IP,sizeof(clt_IP)),
            ntohs(clt_addr.sin_port)
            );
    while(1)
    {
        len = read(cfd,buf,sizeof(buf));
        write(STDOUT_FILENO,buf,len);
        for(int i=0;i<len;i++)
            buf[i] = toupper(buf[i]);
        write(cfd,buf,len);
    }
    close(lfd);
    close(cfd);
    
    return 0;
}
