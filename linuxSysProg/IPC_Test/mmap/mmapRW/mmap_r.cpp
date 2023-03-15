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
    struct student stu; 
    struct student *p;
    int fd;

    fd = open("test_map",O_RDONLY);
    if(fd == -1)
    {
        sys_err("open error");
    }

    ftruncate(fd,sizeof(stu));
    
    p =(struct student*)mmap(NULL,sizeof(stu),PROT_READ,MAP_SHARED,fd,0);
    if(p == MAP_FAILED)
        sys_err("mmap error");
    
    close(fd);
    while(1){
        printf("id = %d,name = %s,age = %d\n",p->id,p->name,p->age);
        sleep(1);
    }

    munmap(p,sizeof(stu));
    return 0;
}

