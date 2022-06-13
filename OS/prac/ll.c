#include <stdio.h>
#include<stdlib.h>



typedef struct node
{

int val;
struct node * next;
}node;

void inserte(node *p,int x)
{
    node *new=(node*)malloc(sizeof(node));
    new->val=x;
    new->next=NULL;
    p->next=new;

}
void print(node*p)
{
    node*ptr;
    for(ptr=p->next;ptr!=NULL;ptr=ptr->next)
    {
        printf(" %d",ptr->val);
    }
    
}
void insertE(node *p,int x)
{
    node *new=(node*)malloc(sizeof(node));
    node*ptr;
    new->val=x;
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
int main()
{
    node *l=(node*)malloc(sizeof(node));
    l->next=NULL;
    inserte(l,1);
    insertE(l,2);
    print(l);
}