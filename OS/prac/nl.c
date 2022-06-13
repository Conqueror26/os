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
    int count=0;
    while(read(fd1,buf,1))
    {
       // printf("\nEntered");
       if(n<=5){
        if(buf[0]=='\n')
        {
            line[k++]='\0';
            printf("\n %d :%s",count+1,line);
            k=0;
            n++;
            count++;
           /*strcpy(line, "");
          strcpy(buf, "");*/
        }
        else 
        {
            line[k++] = buf[0];
        }
       }
    
    }
    
    
}