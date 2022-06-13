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
int j=0,i;char a[100];i=0;int count=0;
while(j<nr)
{
for(int k=0;buf[i]!='\n';i++,k++)
a[k]=buf[i];
i++;
if(strstr(a,argv[1]))
{ count++;}
j=j+i;
}
printf("\nno of lines matched:%d",count);
return 0;