#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
typedef struct pagetable{
char pid[10];
int f[1000],n;
}pgtab;

int rando(int lower,int upper){
    return (rand()%(upper - lower + 1)) + lower;
}

typedef struct ll{
int f;
struct ll *nxt;
}ll;

int map[1000];
pgtab tab[1000];
int t=0;
void insert(ll **h,int x){
    ll *new;
    new = (ll *)malloc(sizeof(ll));
    new->f = x;
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
        printf("%d ",ptr->f);
        ptr = ptr->nxt;
    }
    printf("\n");
}
void all(ll **h,char pid[],int sz,int *n){
    if(*n>=sz)
    {
        strcpy(tab[t].pid,pid);
        tab[t].n=sz;
        for(int i=0;i<sz;i++)
        {
            tab[t].f[i] = (*h)->f;
            *h = (*h)->nxt;
            (*n)--;
        }
        t++;
    }
    else
    {
     printf("Out of free space\n");
    }
}
void pgtable(){
    for(int i=0;i<t;i++)
    {
        printf("PID:%s N:%d\n",tab[i].pid,tab[i].n);
    for(int j=0;j<tab[i].n;j++)
    {
        printf("%d ",tab[i].f[j]);
    }
    printf("\n");
    }
}
void del(ll **h,char pid[],int *n){
int pos;
    for(int i=0;i<t;i++)
    {
        if(!strcmp(tab[i].pid,pid))
        {
            for(int j=0;j<tab[i].n;j++)
            {
                insert(h,tab[i].f[j]);
            }
            pos = i;
            *n+=tab[i].n;
        }
    }
    for(int i=pos+1;i<t;i++){
        tab[i-1] = tab[i];
    }
    t--;
}
int main(){
srand(time(0));
int mem_sz,pg_sz;
int ff = mem_sz;
printf("enter memory size:");
scanf("%d",&mem_sz);
int n = rando(1,mem_sz);
printf("%d\n",n);
ll *frames = NULL;
for(int i=0;i<n;i++){
while(1){
int r = rando(1,mem_sz);
if(map[r]==0){
insert(&frames,r);
map[r] = 1;
break;
}
}
}
display(frames);
printf("\n1.Allocation\n");
printf("2.Deallocation\n");
printf("3.Page Table\n");
printf("4.Free Frames\n");
printf("5.Exit\n");
do{
int choice;
printf("Enter Choice:");
scanf("%d",&choice);
int sz;
char pid[5];
switch(choice){
case 1:
printf("Enter pid and size:");
scanf("%s %d",pid,&sz);
all(&frames,pid,sz,&n);
pgtable();
break;
case 2:
printf("Enter the pid:");
scanf("%s",pid);
del(&frames,pid,&n);
printf("Free Frames:");
display(frames);
pgtable();
break;
case 3:
printf("Page Table:\n");
pgtable();
break;
case 4:
printf("Free Frames:");
display(frames);
break;
case 5:
exit(0);
}
}while(1);
return 0;
}