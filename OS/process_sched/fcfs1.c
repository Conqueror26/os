#include<stdio.h>
struct fcfs
{
    int tat,wt,at,bt;
};


void fcfs_sort(struct fcfs a[], int n)
{
    for(int i=0;i<n-1;i++)
    {
        int min_i = i;
        struct fcfs temp;
        for(int j=i+1;j<n;j++)
        {
                if(a[min_i].at>a[j].at)
                {
                    min_i=j;
                }
            
        }
        temp=a[i];
        a[i]=a[min_i];
        a[min_i]=temp;
        

    }
}
void fcfs_calc(struct fcfs a[], int n)
{
    int time=0,idle=0;
   for (int i=0; i<n; i++) {
        a[i].wt = time- a[i].at;
        if (a[i].wt<0) 
        {
            idle += (0 - a[i].wt);
            a[i].wt = 0;
        }
        time = time + a[i].bt + idle;
        if(idle > 0);
            idle = 0;
        a[i].tat = a[i].bt + a[i].wt;
   }
    int sum_tat=0;
    int  sum_wt=0;
    for(int i=0;i<n;i++)
    {
        sum_tat+=a[i].tat;
        sum_wt+=a[i].wt;
        
    }
    float avg_tat=sum_tat/n;
    float avg_wt=sum_wt/n;
    for(int i=0;i<n;i++)
    {
         printf("%d %d %d %d\n",a[i].at,a[i].bt,a[i].wt,a[i].tat);
    }
   
}
int main()
{
    int n;
    printf("enter number of processes:");
    scanf("%d",&n);
    struct fcfs a[10];
    for(int i=0;i<n;i++)
    {
        printf("enter at for p[%d]:",i+1);
        scanf("%d",&a[i].at);
    }
    for(int i=0;i<n;i++)
    {
        printf("enter bt for p[%d]:",i+1);
        scanf("%d",&a[i].bt);
    }
    fcfs_sort(a,n);
    fcfs_calc(a,n);

    
}