#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct node
{
    int val;
    struct node * next;

}node;

int rando(int u)
{
    return ((rand()%u)+1);
}

int main()
{
    int z=10;
    for(int i=0;i<z;i++)
    {
    int n=rando(100);
    printf("%d ",n);
    }
}