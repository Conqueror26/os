#include<stdio.h>

struct fcfs
{
    int tat,wt,at,bt;
};

struct fcfs a[10];

int main()
{ 
    int n;
    int sum_tat=0;
    int  sum_wt=0;
    int count=0;
    int index,t;
    int temp[20];
    printf("enter number of processes:");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("enter arrival time[%d]:",i+1);
        scanf("%d",&a[i].at);
        printf("enter burst time[%d]:",i+1);
        scanf("%d",&a[i].bt);
      
    }

    for(int i=0;i<n;i++)
    {
        a[i].wt=a[i].wt+a[i].bt;
       
      

    }
      
    for(int i=0;i<n;i++)
    {
        a[i].tat=a[i].wt+a[i].bt;

    }

    for (int i=0; i<n; i++) {
      sum_wt = sum_wt + a[i].wt;
      sum_tat = sum_tat + a[i].tat;
      printf(" %d\t  %d\t\t %d \t%d\n", i+1, a[i].bt, a[i].wt, a[i].tat);
   }
   printf("Average waiting time = %f\n", (float)sum_wt / (float)n);
   printf("Average turn around time = %f\n", (float)sum_tat / (float)n);
   return 0;

    
    

    //printf("%f",(sum_wt/n));
 
        
 }
 
