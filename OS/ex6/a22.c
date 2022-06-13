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
    int i=0,p,c;
    while(i<*n){
        sem_wait(mutex);
        sem_getvalue(full,&c);
        int x=0;
        while(c)
        {
            sem_wait(full);
            int next_consumed = buff[x++];
            printf("%d ",next_consumed);
            i++;
            sem_post(empty);
            sem_getvalue(full,&c);
        } 
        sem_post(mutex);
    }
    printf("\n");
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
