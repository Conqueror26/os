#include<stdio.h>
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
int segid; 
int empty_id;
int full_id;
int mutex_id;
char * buff;
char * input_string;
sem_t *empty;
sem_t *full;
sem_t *mutex;
int p=0,c=0;

void produce()
{
while(1){
sem_wait(mutex);
sem_getvalue(empty,&p);
int i=0;

while(p)
{
if(strlen(input_string)==0)
break;
sem_wait(empty);
char next_produced = *input_string;
*(buff+i)=next_produced;
input_string++;
i++;
sem_post(full);
sem_getvalue(empty,&p);

} 
sem_post(mutex);
if(strlen(input_string)==0)
break;
}
}
void consume()
{
int len=strlen(input_string);
while(1){
int x=0;
sem_wait(mutex);
sem_getvalue(full,&c);
while(c)
{
sem_wait(full);
char next_consumed = *(buff+x);
printf("%c",next_consumed);
x++;
len--;
sem_post(empty);
sem_getvalue(full,&c);

} 
sem_post(mutex);
if(len==0)
break;
}
} 
int main()
{
int i=0;
pid_t temp_pid;
segid = shmget (IPC_PRIVATE, SIZE, IPC_CREAT | IPC_EXCL | SHMPERM );
empty_id=shmget(IPC_PRIVATE,sizeof(sem_t),IPC_CREAT|IPC_EXCL|
SHMPERM);
full_id=shmget(IPC_PRIVATE,sizeof(sem_t),IPC_CREAT|IPC_EXCL|
SHMPERM);
mutex_id=shmget(IPC_PRIVATE,sizeof(sem_t),IPC_CREAT|IPC_EXCL|
SHMPERM);
buff = shmat( segid, (char *)0, 0 );
empty = shmat(empty_id,(char *)0,0);
full = shmat(full_id,(char *)0,0);
mutex = shmat(mutex_id,(char *)0,0);

printf("\n STARTED \n");

sem_init(mutex,1,1);
sem_init(full,1,0);
sem_init(empty,1,SIZE);
printf("\n Enter the input string  : ");
input_string=malloc(21);
scanf("%20s",input_string);
temp_pid = fork();
if(temp_pid>0)
{
produce();
wait(NULL);
}
else
{
printf("Output in child:");
consume();
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
printf("\n  EXITED %d\n\n",temp_pid);
return(0);
}