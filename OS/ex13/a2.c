#include <pthread.h>
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
int avg;
int sum;
int min;
int max;
void *average(void*param);
void *minimum(void*param);
void *maxi(void*param);

int main(int argc, char *argv[])
{
    int arr[10];
    int n;

    printf("enter n:");
    scanf("%d",&n);
     printf("enter the values:");
    for(int i=0;i<n;i++)
    {
   
    scanf("%d",&arr[i]);
    }
    sum=0;
    for(int i=0;i<n;i++)
    {
        sum=sum+arr[i];
    }
    avg=sum/n;
   min=arr[0];
    for(int i=0;i<n;i++)
    {
        if(arr[i]<min)
        {
            min=arr[i];
        }
    }
    max=arr[0];
    for(int i=0;i<n;i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
        }
    }
       
    
    pthread_t tid1; 
    pthread_attr_t attr1; 
    pthread_attr_init(&attr1);

    pthread_create(&tid1,&attr1,average,NULL);

    pthread_join(tid1,NULL);
    
    printf("the average value is = %d\n",avg);
     pthread_t tid2; 
    pthread_attr_t attr2; 
    pthread_attr_init(&attr2);

    pthread_create(&tid2,&attr2,minimum,NULL);

    pthread_join(tid2,NULL);
    printf("the minimum value is= %d\n",min);
     pthread_t tid3; 
    pthread_attr_t attr3; 
    pthread_attr_init(&attr3);

    pthread_create(&tid3,&attr3,maxi,NULL);

    pthread_join(tid3,NULL);
    printf("the maximum value is= %d\n",max);

}
void *average(void *param)
{
   
    pthread_exit(0);

}
void *minimum(void *param)
{
   
    pthread_exit(0);

}
void *maxi(void*param)
{
    pthread_exit(0);
}