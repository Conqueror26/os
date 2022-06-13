#include<stdio.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
key_t key =ftok("shmfile",65);

int shmid =shmget(key,1024,0666|IPC_CREAT);
char *str= (char *)shmat(shmid,(void*)0,0);

int fd1=open(str,O_RDONLY);
char buf[1];

int k=0;;
char line[10];
while(read(fd1,buf,1))
{
    if(buf[0]=='\n')
    {
        line[k++]='\0';
        printf("%s\n",line);
        k=0;
    }
    else
    {
        line[k++]=buf[0];
    }
}
shmdt(str);
shmctl(shmid,IPC_RMID,NULL);
}
