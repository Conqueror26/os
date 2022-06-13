#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <semaphore.h>
#include <pthread.h> 
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/wait.h>
#include <sys/errno.h>
#include <sys/types.h>
#include <unistd.h>
extern int errno;
#define SIZE 10
#define VARSIZE 1 
#define INPUTSIZE 20
#define SHMPERM 0666 
int main()
{
int segid; 
int empty_id;
int full_id;
int mutex_id;
int * buff;
sem_t *empty;
sem_t *full;
sem_t *mutex;
int *n;
segid = shmget (100, SIZE, IPC_CREAT | SHMPERM );
empty_id=shmget(200,sizeof(sem_t),IPC_CREAT|
SHMPERM);
full_id=shmget(300,sizeof(sem_t),IPC_CREAT|
SHMPERM);
mutex_id=shmget(400,sizeof(sem_t),IPC_CREAT|
SHMPERM);
int id1=shmget(500, SIZE, IPC_CREAT | SHMPERM);
n=shmat(id1,NULL,0);
buff = shmat( segid,NULL, 0 );
empty = shmat(empty_id,(char *)0,0);
full = shmat(full_id,(char *)0,0);
mutex = shmat(mutex_id,(char *)0,0);
sem_init(mutex,1,1);
sem_init(full,1,0);
sem_init(empty,1,SIZE);
printf("\n Enter N: ");
scanf("%d",n);
int i=0,c,p;
while(i<*n){
    sem_wait(mutex);
    sem_getvalue(empty,&p);
    while(p)
    {
        sem_wait(empty);
        int next_produced =rand()%100;
        buff[SIZE-p]=next_produced;
        i++;
        sem_post(full);
        sem_getvalue(empty,&p);
        if(i==*n)
        break;
    } 
    sem_post(mutex);
}
shmdt(buff);
shmdt(empty);
shmdt(full);
shmdt(mutex);
shmctl(segid, IPC_RMID, NULL);
semctl( empty_id, 0, IPC_RMID, NULL);
semctl( full_id, 0, IPC_RMID, NULL);
semctl( mutex_id, 0, IPC_RMID, NULL);
sem_destroy(empty);
sem_destroy(full);
sem_destroy(mutex);
return(0);
}