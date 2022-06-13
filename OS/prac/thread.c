#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
int avg,sum;
int n;
void * averag(void *param);
int main(int argc,char**argv)
{
    pthread_t id1;
    pthread_t id2;
    pthread_t id3;
    pthread_attr_t attr1;
    pthread_attr_t attr2;
    pthread_attr_t attr3;

    int *num=(int *)malloc((argc-1)*sizeof(int *));
    for(int i=1;i<argc;i++)
    {
        num[i-1]=atoi(argv[i]);
    }
    n=argc-1;
    pthread_attr_init(&attr1);
    pthread_create(&id1,&attr1,averag,(void*)num);
    pthread_join(id1,NULL);
    printf("%d",avg);




}
void *averag(void * param)
{
    int *arr=(int *)param;
    sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
    }
    avg=sum/n;
    pthread_exit(0);
}