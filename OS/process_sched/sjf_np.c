#include<stdio.h>
struct sjf 
{
    int wt,at,tat,bt,ct;
};

struct sjf a[10];

void sjf_sort(int n)
{
    struct sjf temp;
    for(int i=0;i<n;i++)
    {
       int mini=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[mini].bt>a[j].bt)
            {
                mini=j;
            }
        }
        temp=a[i];
        a[i]=a[mini];
        a[mini]=temp;
      
    }
}
void sjf_calc(int n)
{
    int time=0;
   for (int i=0; i<n; i++)
   {
      if(time<a[i].at)
      {
        time=a[i].at;
        i--;
      }
      else
      {
        time+=a[i].bt;
        a[i].ct=time;
        a[i].tat=a[i].ct-a[i].at;
        a[i].wt=a[i].tat-a[i].bt;
        }
      }
       
   
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
    sjf_sort(n);
    sjf_calc(n);
    
}