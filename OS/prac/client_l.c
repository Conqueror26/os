#include<sys/ipc.h>
#include<sys/shm.h>
#include<ctype.h>
#include<stdio.h>


int main()
{
    key_t key =ftok("shmfile",65);
    int shmid=shmget(key,1024,0666|IPC_CREAT);
    int * a=(int *)shmat(shmid,(void*)0,0);

    *a=123;
    printf("%d",*a);
    shmdt(a);

}