#include<stdio.h>

void bankers( int alloc[][3],int max[][3],int avail[],int need[][10],int r,int c)
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            need[i][j]=max[i][j]-alloc[i][j];
            printf("%d",need[i][j]);
        }
        printf("\n");
    }
    int completed[10];
    for(int k=0;k<c;k++)
    {
        completed[i]=0;
    }
    int flag=0;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            
           if(need[i][j]<avail[j])
           {
               avail[j]+=alloc[i][j];
                flag=1;
                break;
               
           }
           
        }
       if(flag==1)
       {
         printf("p[%d]->",i);
       }
    }
}


int main()
{
    int avail[10],need[10][10];
    int r=5,c=3;
    /*printf("enter number of processes:");
    scanf("%d",&r);
    printf("enter number of colummns:");
    scanf("%d",&c);
   
    for(int i=0;i<r;i++)
    {
        printf("enter allocation for p[%d]:",i+1);
        for(int j=0;j<c;j++)
            scanf("%d",&alloc[i][j]);
    }
     for(int i=0;i<r;i++)
    {
        printf("enter max for p[%d]:",i+1);
        for(int j=0;j<c;j++)
            scanf("%d",&max[i][j]);
    }
     
    for(int i=0;i<c;i++)
    {
        scanf("enter available resources:");
        scanf("%d",&avail[i]);
    }*/
    
   int  alloc[5][3]={
                {0,1,0},
                {2,0,0},
                {3,0,2},
                {2,1,1},
                {0,0,2}
                };
    int max[5][3]={
            {7,5,3},
            {3,2,2},
            {9,0,2},
            {2,2,2},
            {4,3,3}
                 };
    bankers(alloc,max,avail,need,r,c);
    

    
}