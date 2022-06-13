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
    int c;
    
    while(read(fd1,buf,1))
    {
       // printf("\nEntered");
        if(buf[0]=='\n')
        {
            n++;
        }
    }
    close(fd1);
    fd1=open(argv[1],O_RDONLY);
    int y=0;
   
    while(read(fd1,buf,1))
    {
       // printf("\nEntered");
       if(buf[0]=='\n')
        {
            line[k++]='\0';
            if(y>=(n-5))
            {
                //if(strlen(line)==1 && line[0]='\n' )
                    printf("%s\n",line);
            }    
            k=0;
            y++;
            
        }
       else
            line[k++] = buf[0];
    
    }
    
    
}