#include<stdio.h>

int main()
{
    int st[30];
    int n;


    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&st[i]);
    }
    int fr[10];
    int sz;
    scanf("%d",&sz);
    int count=0;
    int pf=0,j,i,k;
    for( i=0;i<sz;i++)
    {
       fr[i]=-1;
    }

    for( i=0;i<n;i++)
    {
        for( j=0;j<sz;j++)
        {
            if(fr[j]==st[i])
            {
                break;
            }
        }
        if(j==sz)
        {
            fr[count++]=st[i];
            pf++;
        }
        for( k=0;k<sz;k++)
        {
            printf("\t%d",fr[k]);
        }
        if(j==sz)
        {
            printf("\t%d",pf);
        }
        printf("\n");
        if(count==sz)
        {
            count=0;
        }
    }
}