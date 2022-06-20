#include<stdio.h>
#include<stdlib.h>

int main()
{
    int f[100];
    int l;
    int n;
    int r;
    int nf;
    int sb;
    int a;

    printf("enter number of blocks:");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        f[i]=0;
    }
    printf("enter number of blocks to be randomly allocated:");
    scanf("%d",&r);

    for(int i=1;i<=r;i++)
    {
         a=rand()%(n+1);
        printf("%d\n",a);
    
    }
    for(int i=0;i<n;i++)
    {
        f[a]=1;;
    }

    printf("enter number of files:");
    scanf("%d",&nf);
    for(int i=0;i<nf;i++)
    {
        printf("enter starting block:");
        scanf("%d",&sb);
        printf("enter length of file:");
        scanf("%d",&l);
         int len=l;
        if(f[sb]==0)
        {
        for(int k=sb;k<(sb+len);k++)
        {
            if(f[k]==0)
            {
                f[k]=1;
                printf(" %d ->%d\n",k ,f[k]);
            }
            else
            {
                printf("allocated\n");
                len++;
            }
        }
        }
        else
        {
            printf("already alllocated");
        }
    }

}