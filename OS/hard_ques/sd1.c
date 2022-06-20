#include<stdio.h>
#include<string.h>
int main()
{
    char *file[10];
    char * direct;
    char *name;
    int nf;
    int ch;
    printf("enter director name:");
    scanf("%s",direct);
    /*printf("enter number of files:");
    scanf("%d",&nf);*/
    do{
    printf("enter file name:");
    scanf("%s",name);
   int flag=0;
        nf=0;
        for(int i=0;i<nf;i++)
        {
            
            if(strcmp(file[i],name)==0)
            {
               
               flag=1;
               break;
            }
           
        }
        if(flag==0 || nf==0)
        {
            strcpy(file[nf++],name);
        }
        else
        {
            for(int i=0;i<nf;i++)
            printf("%s",file[i]);
        }
    }while(1);
     //print

   
    }