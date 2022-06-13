#include<stdio.h>

struct bank
{
   int id,avail,alloc,max,need;
};
struct bank a[20][20];
struct bank b[10];


int main()
{
    int r,c;
    printf("enter number of processes:");
    scanf("%d",&r);
    printf("enter number of resources:");
    scanf("%d",&c);
    for(int i=0;i<r;i++)
    {
        b[i].id=i;
        printf("enter max req for p[%d] ",b[i].id);
        for(int j=0;j<c;j++)
        {
            
            scanf("%d",&a[i][j].max);
        }
    }
    for(int i=0;i<r;i++)
    {
       
        printf("enter allocated instances  for p[%d] ",b[i].id);
        for(int j=0;j<c;j++)
        {
            
            scanf("%d",&a[i][j].alloc);
        }
    }
    for(int i=0;i<r;i++)
    {
        printf("enter availabale instances:");
        
        scanf("%d",&b[i].avail);
    }
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            a[i][j].need= a[i][j].max-a[i][j].alloc;
            //printf("%d\n",a[i][j].need);
        }
    }
    int finish;
    finish=0;
    for(int i=0;i<r;i++)
    {
        for(int  j=0;i<c;j++)
        {
           
            if(a[i][j].need<a[i][j].avail && finish==0)
            {
            a[i][j].avail=a[i][j].avail+a[i][j].alloc;
            finish=1;
            }
            
        }
        if(finish==1)
            {
                printf("%d ->",b[i].id);
            }
    }
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            printf("%d\n",a[i][j].avail);
        }
    }
}