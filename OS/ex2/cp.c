#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

void cp()
{
	int fd1,fd2;
	char buf[60];
	fd1=open("f1.txt",O_RDONLY);
	fd2=open("f2.txt",O_RDWR);
	int f=read(fd1,buf,60);
	write(fd2,buf,f);
	printf("FILE COPIED\n");
	
	close(fd1);
	close(fd2);

}
void cpi()
{
	int fd1,fd2;
	char buf[60];
	char key[10];
	fd1=open("f1.txt",O_RDONLY);
	printf("DO YOU WANT TO OVERWRITE(y/n):");
	scanf("%s",key);
    if(strcmp(key,"y")==0)
	{
	fd2=open("f2.txt",O_RDWR | O_CREAT);
	int f=read(fd1,buf,60);
	write(fd2,buf,f);
	printf("FILE COPIED\n");
	
	close(fd1);
	close(fd2);
	}
	else
	{
	
	printf("FILE NOT OVERWRITTEN\n");
	}
	
}






void main(int argc ,char * argv[])
{
	char k[10];
	scanf("%s",k);
    if(strcmp(k,"cp-i")==0)
     cpi();
	 else
	 cp();

}
