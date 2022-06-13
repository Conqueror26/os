#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
typedef struct ll{
int s,e;
char pid[5];
struct ll *nxt;
}ll;

void insert(ll **h,int s,int e,char pid[])
{
    ll *new;
    new = (ll *)malloc(sizeof(ll));
    new->s = s;
    new->e = e;
    strcpy(new->pid,pid);
    if(*h==NULL){
        *h = new;
        new->nxt = NULL;
        return;
}
    ll *ptr;
    ptr = *h;
    while(ptr->nxt){
        ptr = ptr->nxt;
    }
    ptr->nxt = new;
    new->nxt = NULL;
}
void display(ll *h){
ll *ptr;
ptr=h;
while(ptr){
printf("| %d (%s) %d |",ptr->s,ptr->pid,ptr->e);
ptr = ptr->nxt;
}
printf("\n");
}
void firstFit(ll **h,char pid[],int sz){
    ll *ptr = *h;
    while(ptr){
        if((ptr->e-ptr->s)>=sz && strcmp(ptr->pid,"H")==0)
        {
            if((ptr->e-ptr->s)==sz)
            {
                strcpy(ptr->pid,pid);
                break;
            }  
            else
            {
                ll *new = (ll *)malloc(sizeof(ll));
                new->s = ptr->s + sz;
                new->e = ptr->e;
                new->nxt = ptr->nxt;
                ptr->nxt = new;
                ptr->e = new->s;
                strcpy(ptr->pid,pid);
                strcpy(new->pid,"H");
                break;
            }
        }
    ptr = ptr->nxt;
    }
    display(*h);
}
void bestFit(ll **h,char pid[],int sz){
    ll *ptr = *h,*min = *h;
    int mn=999999;
    while(ptr)
    {
        if((ptr->e-ptr->s)>=sz && strcmp(ptr->pid,"H")==0)
        {
            if((ptr->e-ptr->s)<mn)
            {
                min = ptr;
                mn = ptr->e - ptr->s;
            }
        }
        ptr = ptr->nxt;
    }
        if(mn==999999){
            printf("NO MEMORY");
            return;
        }
        if(min->e-min->s==sz){
            strcpy(min->pid,pid);
        }
        else if(min->e-min->s>sz){
            ll *new = (ll *)malloc(sizeof(ll));
            new->s = min->s+sz;
            new->e = min->e;
            new->nxt = min->nxt;
            min->nxt = new;
            min->e = new->s;
            strcpy(new->pid,"H");
            strcpy(min->pid,pid);
        }
        display(*h);
}
void worstFit(ll **h,char pid[],int sz){
ll *ptr = *h,*max = *h;
int mx=0;
while(ptr){
if((ptr->e-ptr->s)>=sz && strcmp(ptr->pid,"H")==0){
if((ptr->e-ptr->s)>mx){
max = ptr;
mx = ptr->e - ptr->s;
}
}
ptr = ptr->nxt;
}
if(mx==0){
printf("NO MEMORY");
return;
}
if(max->e-max->s==sz){
strcpy(max->pid,pid);
}
else if(max->e-max->s>sz){
ll *new = (ll *)malloc(sizeof(ll));
new->s = max->s+sz;
new->e = max->e;
new->nxt = max->nxt;
max->nxt = new;
max->e = new->s;
strcpy(new->pid,"H");
strcpy(max->pid,pid);
}
display(*h);
}
void deallocate(ll **h,char pid[]){
ll *ptr = *h;
while(ptr){
if(strcmp(pid,ptr->pid)==0){
strcpy(ptr->pid,"H");
break;
}
ptr = ptr->nxt;
}
display(*h);
}
int main(){
ll *mem = NULL;
printf("Memory Allocation\n");
int n;
printf("No of Free Spaces:");
scanf("%d",&n);
while(n){
int s,e,h;
printf("start & end :");
scanf("%d %d",&s,&e);
insert(&mem,s,e,"H");
n--;
}
do{
int choice,sz;
char pid[5];
printf("1.First Fit\n");
printf("2.Best Fit\n");
printf("3.Worst Fit\n");
printf("4.De-Allocate\n");
printf("Choice:");
scanf("%d",&choice);
switch(choice){
case 1:
printf("Enter pid and size:");
scanf("%s %d",pid,&sz);
firstFit(&mem,pid,sz);
break;
case 2:
printf("Enter pid and size:");
scanf("%s %d",pid,&sz);
bestFit(&mem,pid,sz);
break;
case 3:
printf("Enter pid and size:");
scanf("%s %d",pid,&sz);
worstFit(&mem,pid,sz);
break;
case 4:
printf("Enter pid:");
scanf("%s",pid);
deallocate(&mem,pid);
break;
default:
printf("wrong choice");
break;
}
printf("Continue?");
int c;
scanf("%d",&c);
if(c)break;
}while(1);
return 0;
}