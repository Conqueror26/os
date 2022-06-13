#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

int main() {
   key_t my_key = ftok("shmfile",65); // ftok function is used to generate unique key
   int shmid = shmget(my_key,1024,0666|IPC_CREAT); // shmget returns an ide in shmid
   char *str = (char*) shmat(shmid,(void*)0,0); // shmat to join to shared memory
   
   printf("Data read from memory: %s\n",str);
 printf("enter :");
   scanf("%s",str);
   printf("Data read from memory: %s\n",str);
   shmdt(str);
   
   printf("do u want to continue chatting with the client(y/n):");
   char k;
   scanf(" %c",&k);
   if(k=='n')
   shmctl(shmid,IPC_RMID,NULL); // destroy the shared memory
   
}

