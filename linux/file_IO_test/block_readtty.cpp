#include<unistd.h>
#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
    char buf[10];
    int n;
    
    n= read(STDIN_FILENO,buf,10);
    if(n<0)
    {
        perror("read STDIN_FILENO");
        exit(1);
    }
    write(STDOUT_FILENO,buf,n);
    return 0;
}
