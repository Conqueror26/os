#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main(int argc ,char **argv)
{
    char line[20];
    int fd1=open(argv[1],O_RDONLY);
    char buf[1];
    int i=0;
    int k=0;
    int n=0;
    while(read(fd1,buf,1))
    {
       // printf("\nEntered");
       if(n<=5){
        if(buf[0]=='\n')
        {
            line[k++]='\0';
            printf("\n%s",line);
            k=0;
            n++;
           strcpy(line, "");
          strcpy(buf, "");
        }
        else 
        {
            line[k++] = buf[0];
        }
       }
    
    }
    
    
}