#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
int main(int argc,char **argv)
{
if(argc!=3)
printf("two arguments only required");
char buf[100];
int fd=open(argv[2],O_RDONLY);
if(fd==-1)
{printf("file could not be opened");return 0;}
int nr=read(fd,buf,100);
int i,k;char a[100];i=0;
while(i<nr)
{
for(k=0;buf[i]!='\n';i++,k++)
a[k]=buf[i];
a[k]='\0';
i++;
if(strstr(a,argv[1]))
printf("\n%s ",a);
}
return 0;
}