/*************************************************************************
 > File Name: dup.c
 > Author: Catkin 
 > Created Time: Fri Feb 17 15:21:02 2023
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
#include<fcntl.h>
int main(int argc, char* argv[])
{
    int fd = open(argv[1],O_RDONLY);
    
    int newfd = dup(fd);

    printf("newfd = %d\n",newfd);
    
    return 0;
}
