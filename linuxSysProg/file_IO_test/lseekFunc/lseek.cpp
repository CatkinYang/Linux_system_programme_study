#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
using namespace std;
int main()
{
    int fd,n;
    char msg[]="it's a test for lseek\n";
    char ch;
    fd = open("lseek.txt",O_RDWR|O_CREAT,0644);
    if(fd<0)
    {
        perror("open lseek.txt error");
        exit(1);
    }

    write(fd,msg,strlen(msg));//fd is used to do write operation on the files which is been opened
    lseek(fd,0,SEEK_SET);
    while(n==read(fd,&ch,1))
    {
        if(n<0)
        {
            perror("read error");
            exit(1);
        }
        write(STDOUT_FILENO,&ch,n);//print the content in this file by bytes,and output them in the screen
    }
    close(fd);
    return 0;    

}
