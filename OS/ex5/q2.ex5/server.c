#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
# include<string.h>
#include<stdlib.h>
int main() {
   key_t my_key = ftok("shmfile",65); // ftok function is used to generate unique key
   int shmid = shmget(my_key,1024,0666|IPC_CREAT); // shmget returns an ide in shmid
   char *str = (char*) shmat(shmid,(void*)0,0); // shmat to join to shared memory
   
  
	char *a,*b,c,*start;
	a = (char *)malloc(sizeof(char)*50);
	start=a;
	FILE *fptr;
	
	
	printf("File name received:%s\n",str);
	fptr=fopen(str,"r");
	
	c=fgetc(fptr);//reading character by character from file
    printf("file contents:\n");
	while(c!=EOF)
	{
		*a=c;
        printf("%c",c);
		c=fgetc(fptr);
        
		a++;
	}
    printf("\n");
	*a='\0';
	strcpy(str,start);//copying file contents to shared memory
	shmdt(str);
	fclose(fptr);
    

   
   shmdt(str);
   
  
   shmctl(shmid,IPC_RMID,NULL); // destroy the shared memory
   
}

