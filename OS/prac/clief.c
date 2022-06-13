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

printf("enter file name:");
scanf("%s",str);

shmdt(str);
}