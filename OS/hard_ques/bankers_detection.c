#include<stdio.h>

int main()
{
    int avail[10];
    int alloc[10][10],req[10][10];
    int i,j;
    int process;
    int count=0;
    int p;
    int r;
    int completed[10];
    int safe[20];

    printf("enter number of processes:");
    scanf("%d",&p);
    printf("enter number of resources:");
    scanf("%d",&r);
    printf("enter alloc matrix:");
    for(i=0;i<p;i++)
    {
        printf("enter for p[%d]",i+1);
        for(j=0;j<r;j++)
        {
            scanf("%d",&alloc[i][j]);
        }
    
    }
    printf("enter req matrix:");
    for(i=0;i<p;i++)
    {
        printf("enter for p[%d]",i+1);
        for(j=0;j<r;j++)
        {
            scanf("%d",&req[i][j]);
        }
    
    }
     printf("enter avail resources:");
     for(i=0;i<r;i++)
     {
        scanf("%d",&avail[i]);
     }

    for(i=0;i<p;i++)
    {
        
        for(j=0;j<r;j++)
        {
            printf("%d\t%d ",alloc[i][j],req[i][j]);
        }
    
    }

    while(process!=-1 && count!=p)
    {
        process=-1;
        for(i=0;i<p;i++)
        {
            if(completed[i]==0)
            {
                process=i;
                for(j=0;j<r;j++)
                {
                    if(req[i][j]>avail[j])
                    {
                        process=-1;
                        break;
                    }
                }
            }
            if(process!=-1)
            {
                break;
            }
        }
        if(process!=-1)
        {
            safe[count++]=process+1;
            for(j=0;j<r;j++)
            {
                avail[j]+=alloc[process][j];
                alloc[process][j]=0;
                //req[process][j]
                completed[process]=1;
            }
            
        }

    }
    if(count==p)
    {
        printf("it is safe");
    }
    else
    {
        printf("NOT IN SAFE SEQUENCE");
        for(i=0;i<p;i++)
        {
            printf("p[%d]",safe[i]);
        }
    }
}