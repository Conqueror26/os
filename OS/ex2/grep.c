#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
int main(int argc, char **argv)
{
    char *p;
    int fd1=open(argv[1],O_RDONLY);
    printf("enter pattern:");
    scanf("%s",p);
    char line[20];
    char buf[1];
    int k=0;
    while(read(fd1,buf,1))
    {
        if(buf[0]=='\n')
        {
            line[k++]='\0';
            if(strstr(line,p)) 

                printf("%s\n",line);
            k=0;
        }
        else
        {
            line[k++]=buf[0];
        }
    }

}