#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct node
{
    int sz;
    char pid[10];
    struct node *next;
}node;

void insert(node*p,int x,char pid[])
{
    node*new=(node*)malloc(sizeof(node));
    node *ptr;
    new->sz=x;
    strcpy(new->pid,pid);
    if(p==NULL)
    {
        p=new;
        new->next=NULL;
    }
    else
    {
        ptr=p;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=new;
        new->next=NULL;
    }
   
}
void disp(node*p)
{
    node*ptr=p;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->sz);
        ptr=ptr->next;
    }
    printf("\n");
}
void first(node *p,char pid[],int size)
{
        node*ptr;
        ptr=p;
        while(ptr!=NULL)
        {
            if(ptr->sz>=size && strcmp(ptr->pid,"H")==0)
            {
                if(ptr->sz=size)
                {
                    strcpy(ptr->pid,pid);
                    break;
                }
                else
                {
                    node * new=(node*)malloc(sizeof(node));
                    new->sz=ptr->sz-size;
                    ptr->next=new->next;
                    ptr->next=new;
                    ptr->sz=new->sz;
                    strcpy(ptr->pid,pid);
                    strcpy(new->pid,"H");
                    
                }
            }
            ptr=ptr->next;
        }
        disp(p);
}

int main()
{
    node*mem=(node*)malloc(sizeof(node));
    mem->next=NULL;
   
    int n;
    int size;
    printf("enter size of memory");
    scanf("%d",&n);
    while(n--)
    {
        printf("enter size");
        scanf("%d",&size);
        insert(mem,size,"H");

    }
    first(mem,"1",100);
    first(mem,"2",200);
}