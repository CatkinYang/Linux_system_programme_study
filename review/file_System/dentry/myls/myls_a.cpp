/*************************************************************************
 > File Name: myls_a.cpp
 > Author: Catkin 
 > Created Time: Sun Feb 19 14:14:39 2023
 ************************************************************************/
#include<dirent.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
#include<iostream>
using namespace std;

int main(int argc, char* argv[])
{
    DIR *dp;
    struct dirent *sdp;

    dp = opendir (argv[1]);
    if(dp == NULL)
    {
        perror("opendir error");
        exit(1);
    }

    while((sdp = readdir(dp)) != NULL)
    {
        if(strcmp(&sdp->d_name[0],".") == 0)
            continue;
        printf("%s\t",sdp->d_name);
    }
    printf("\n");
    closedir(dp);

    return 0;
}

