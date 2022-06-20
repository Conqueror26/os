#include <stdio.h>

int main()
{
    int f[50], i, st, len, j, c, k, count;

    for(i=0;i<50;i++)
        f[i]=0;
    printf("Files Allocated are : \n");
    count=0;
    printf("Enter starting block and length of files: ");
    scanf("%d%d", &st,&len);
    for(k=st;k<(st+len);k++)
        if(f[k]==0)
             count++;
    if(len==count)
    {
        for(j=st;j<(st+len);j++)
        if(f[j]==0)
        {
            f[j]=1;
            printf("%d\t%d\n",j,f[j]);
        }
        if(j!=(st+len-1))
            printf(" The file is allocated to disk\n");
    }
    else
    printf( "The file is not allocated \n");


}