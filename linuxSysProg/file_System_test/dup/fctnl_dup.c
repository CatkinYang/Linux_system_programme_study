/*************************************************************************
 > File Name: fctnl_dup.c
 > Author: Catkin 
 > Created Time: Fri Feb 17 19:53:56 2023
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
#include<fcntl.h>
int main(int argc, char* argv[])
{
    int fd1 = open(argv[1],O_RDWR);
    printf("fd1 = %d\n",fd1);

    int newfd = fcntl(fd1,F_DUPFD,0);
    printf("newfd = %d\n",newfd);

    int newfd2 = fcntl(fd1,F_DUPFD,9);
    printf("newfd2 = %d\n",newfd2);

    int ret = write(newfd2,"megumin is my wife\n",22);
    printf("ret = %d\n",ret);
     
    return 0;
}
