#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/stat.h>
using namespace std;

int main(int argc,char *argv[])
{
    struct stat sbuf;
    int ret = stat(argv[1],&sbuf);
    if(ret == -1)
    {
        perror("stat error");
        exit(1);
    }
    printf("file size:%lld\n",sbuf.st_size);
    return 0;
}
