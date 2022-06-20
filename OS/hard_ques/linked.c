#include<stdio.h>

#include<stdlib.h>



int main()
{
    int f[100] ,p,i, st, len, j, c, k, a,r;
    char *b;
    b="free";
    printf("enter number of blocks:");
    scanf("%d",&p);
    for(i=0;i<p;i++)
        f[i]=0;
    printf("enter number of random allocations:");
    scanf("%d",&r);
    for(int i=1;i<r;i++)
    {
        a=rand()%(p+1);
        printf("%d\n",a);
    } 

    for(i=0;i<p;i++)
    {
     
     f[a]=1;
     b="blocked";
    
    }
    int n;
     printf("enter number of files:");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
  
   
    printf("Enter index starting block and length: ");
    scanf("%d%d", &st,&len);
    
    k=len;
    if(f[st]==0)
    {
        for(j=st;j<(st+k);j++)
        {
            if(f[j]==0)
            {
                f[j]=1;
                printf("%d-------->%s\n",j,b);
            }
            else
            {
                printf("%d Block is already allocated \n",j);
                k++;
            }
        }
    }
    
    else
    printf("%d starting block is already allocated \n",st);
    }
    
}
