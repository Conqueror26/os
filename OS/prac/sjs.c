
#include<stdio.h>

struct sjs
{
    int tat,wt,at,bt;
};

struct sjs a[10];

int main()
{ 
    int n,count=0,t,index;
    int sum_tat=0;
    int  sum_wt=0;
    int temp[10];
    printf("enter number of processes:");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("enter arrival time[%d]:",i+1);
        scanf("%d",&a[i].at);
        printf("enter burst time[%d]:",i+1);
        scanf("%d",&a[i].bt);
       temp[i]=a[i].bt;
       
      
       
      
    }
    
     
       
        
    a[9].bt=10000;
    for(t=0;count!=n;t++)
    {
         index=9 ;
        for(int i=0;i<n;i++)
        {
            if(a[index].bt>a[i].bt&&a[i].at<t &&a[i].bt>0)
            {
                index=i;
            }
        }
    
    a[index].bt=a[index].bt-1;

    if(a[index].bt==0)
    {
        count ++;
        a[index].wt=t+1-a[index].at-temp[index];
        a[index].tat=t+1-a[index].at;
        sum_wt = sum_wt + a[index].wt;
        sum_tat = sum_tat + a[index].tat;
    }
}
    for (int i=0; i<n; i++) {
     
      printf(" %d\t  %d\t\t %d \t%d\n", i+1, a[i].bt, a[i].wt, a[i].tat);
   }
   printf("Average waiting time = %f\n", (float)sum_wt / (float)n);
   printf("Average turn around time = %f\n", (float)sum_tat / (float)n); 
}