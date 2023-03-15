/*************************************************************************
 > File Name: unlink_exe.c
 > Author: Catkin 
 > Created Time: Thu Feb 16 21:10:32 2023
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
#include<fcntl.h>
int main()
{
    int fd,ret;
    char *p = "test of unlink\n";
    char *p2 = "after write something\n";

    fd = open("temp.txt",O_RDWR|O_CREAT|O_TRUNC,0644);
    
    if(fd<0)
    {
        perror("open temp error");
        exit(1);
    }

    ret = unlink("temp.txt");//具备了被释放的条件
    if(ret<0)
    {
        perror("unlink error");
        exit(1);
    }

    ret = write(fd,p,strlen(p));
    if(ret == -1)
    {   
        perror("----write error");
    }
    
    printf("hi i'm printf\n");
    ret = write(fd,p2,strlen(p2));
    if(ret == -1)
    {
        perror("----write error");
    }
    
    p[3] = 'H';
    printf("enter anykey continue\n");
    getchar();
    close(fd);


    return 0;
}
