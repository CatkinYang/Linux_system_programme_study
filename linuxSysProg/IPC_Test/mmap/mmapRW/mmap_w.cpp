/*************************************************************************
 > File Name: mmap_w.cpp
 > Author: Catkin 
 > Created Time: Sun Feb 26 14:43:36 2023
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
#include<iostream>
#include<fcntl.h>
#include<sys/mman.h>
using namespace std;
struct student
{
    int id;
    char name[256];
    int age;
};

void sys_err(const char *str)
{
    perror(str);
    exit(1);
}
int main(int argc, char* argv[])
{
    struct student stu = {10,"xiaoming",18};
    struct student *p;
    int fd;
    fd = open("test_map",O_RDWR|O_CREAT|O_TRUNC,0644);
    if(fd == -1)
    {
        sys_err("open error");
    }
    ftruncate(fd,sizeof(stu));
    p =(struct student*)mmap(NULL,sizeof(stu),PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
    close(fd);
    if(p == MAP_FAILED)
        sys_err("mmap error");
    while(1){
        memcpy(p,&stu,sizeof(stu));
        stu.id++;
        sleep(1);
    }
    munmap(p,sizeof(stu));
    return 0;
}

