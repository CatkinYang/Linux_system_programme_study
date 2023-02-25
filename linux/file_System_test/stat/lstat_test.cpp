#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/stat.h>
using namespace std;

int main(int argc,char *argv[])
{
    struct stat sb;
    int ret = lstat(argv[1],&sb);
    if(ret == -1)
    {
        perror("stat error");
        exit(1);
    }
    if(S_ISREG(sb.st_mode))
    {
        printf("it is a regular\n");
    }
    else if(S_ISDIR(sb.st_mode))
    {
        printf("it is a dir\n");
    }
    else if(S_ISFIFO(sb.st_mode)){
        printf("it is a fifo\n");
    }
    else if(S_ISLNK(sb.st_mode)){
        printf("it is a link\n");
    }
    return 0;
}
