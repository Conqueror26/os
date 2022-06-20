#include<stdio.h>
#include<stdlib.h>
int main()
{
    int f[100];
    int ind;
    int nb;
    int r,a;
    int nf;
    int l;
    int fi[20];
  
    char * file;
   
    for(int i=0;i<20;i++)
    {
        f[i]=0;
    }
    
    printf("enter indexed bloc:");
    scanf("%d",&ind);
    if(f[ind]!=1)
    {
        printf("enter number  of block:");
        scanf("%d",&nb);
        printf("enter number of files to be entered on the disk");
        scanf("%d",&nf);
    }
    else
    {
        printf("index already allocated on disck");
    }
     int count=0;
    for(int i=0;i<nf;i++)
    {   
        /*printf("enter name of file 1:");
        scanf("%s",file);*/
        printf("enter size of files:");
        scanf("%d",&fi[i]);
        if(f[fi[i]]==0)
        {
            count++;
        }
        if(count=nf)
        {
            for(int j=0;j<nf;j++)
            {
                f[fi[j]]==1;
                for(int k=0;k<nf;k++)
                    printf("%d:%d-->%d",ind,fi[k],f[fi[k]]);
                

                
            }
        }
        else
        {
            printf("already allocated");
        }


    }
}