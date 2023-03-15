/*************************************************************************
 > File Name: fork_test.c
 > Author: Catkin 
 > Created Time: Sat Feb 18 12:38:02 2023
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>

void sys_err(const char *str)
{
    perror(str);
    exit(1);
}
int main(int argc, char* argv[])
{
    printf("-----exec test\n");
    return 0;
}
