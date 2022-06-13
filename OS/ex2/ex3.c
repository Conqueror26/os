#include<stdio.h>
#include<stdlib.h>
struct process{
int at,bt;
char pi[20];
};
struct PQ 
{
struct process elt[100];
int ctptr;
};
struct GC{ 
struct process p[20];
int start[20];
};
void enqueue(struct PQ *p,struct process d)
{
p->ctptr++;
p->elt[p->ctptr]=d;
for(int i=p->ctptr;p->elt[i/2].bt>d.bt;i=i/2)
{
p->elt[i]=p->elt[i/2];
p->elt[i/2]=d;
}
}
struct process dequeue(struct PQ *p)
{
struct process min=p->elt[1];
int child=1;
p->elt[1]=p->elt[p->ctptr];
p->ctptr--;
for(int i=1;2*i<=p->ctptr;i=child)
{
child=2*i;
if(p->elt[child].bt<p->elt[i].bt||p->elt[child+1].bt<p->elt[i].bt)
{
if(p->elt[child+1].bt<p->elt[child].bt)
child++;
struct process t=p->elt[i];
p->elt[i]=p->elt[child];
p->elt[child]=t;
}
}
return min;
}
int isEmpty(struct PQ *p){
if(p->ctptr==0)
return 1;
return 0;
}
void sort(struct process p[20],int np){
for(int i=0;i<np-1;i++)
{
int t=i;
for(int j=i+1;j<np;j++){
if(p[j].at<p[t].at)
t=j;
}
struct process d=p[t];
p[t]=p[i];
p[i]=d;
}
}
void display(struct GC gc,int np){ 
printf(" ");
for(int i=0;i<np;i++)
printf("%s\t",gc.p[i].pi);
printf("\n");
for(int i=0;i<np;i++){
printf("%d\t",gc.start[i]);
}
printf("%d",gc.p[np-1].bt+gc.start[np-1]);
}
int main(){
int ch,np;
struct process p[20];
printf("Enter no.of processes:");
scanf("%d",&np);
printf("Enter process id,arrival time,burst time:");
for(int i=0;i<np;i++)
scanf(" %s %d %d",p[i].pi,&p[i].at,&p[i].bt);
char c='y';
sort(p,np); 
do{
printf("1)FCFS 2)SJF:");
scanf("%d",&ch);
if(ch==1){
struct GC gc;
float tt=0,sum1=0,sum2=0;
int wt[20],k=0;
for(int i=0;i<np;i++)

{
gc.p[k]=p[i];
gc.start[k++]=sum1;
wt[i]=sum1-p[i].at;
sum2+=sum1-p[i].at;
sum1+=p[i].bt;
}
display(gc,np); 
printf("\nAverage waiting time=%f\n",sum2/np);
for(int i=0;i<np;i++)
{
tt+=wt[i]+p[i].bt;
}
printf("Average turn around time=%f\n",tt/np);
printf("Average response time=%f",sum2/np);
}
else if(ch==2){
printf("1)premptive 2) non-premptive:");
scanf("%d",&ch);
if(ch==1){
struct GC gc;
struct process temp_bt[20];
int res[20],r=0;
for(int i=0;i<np;i++){ 
temp_bt[i]=p[i];
}
int t=0,curr=15,cnt=0,k=0,prev=-1,d=0;
float wt=0,tt=0,rt=0;
temp_bt[15].bt=1000;
while(cnt<np){ 

curr=15;
for(int j=0;j<np;j++){
if(temp_bt[j].bt>0 && p[j].at<=t){
if(temp_bt[curr].bt>temp_bt[j].bt){
curr=j;
}
}
}
if(prev!=curr){
gc.p[k]=temp_bt[curr];
gc.start[k++]=t;
d++;
}

int f=0;
for(int l=0;l<r;l++)
{
if(res[l]==curr)
f=1;
}
if(f==0){
res[r++]=curr;
rt+=t-p[curr].at;
}

temp_bt[curr].bt--;
if(temp_bt[curr].bt==0){ 

cnt++;
wt+=t+1-p[curr].at-p[curr].bt;
tt+=t+1-p[curr].at;
}
t++;
prev=curr;
}
display(gc,d); 
printf("\nAverage waiting time:%f\n",wt/np);
printf("Average turn around time:%f\n",tt/np);
printf("Average response time:%f",rt/np);
}
else{
struct GC gc;
struct PQ * pq=(struct PQ*)malloc(sizeof(struct PQ));
pq->ctptr=0;
struct process dummy;
dummy.bt=-10;
pq->elt[pq->ctptr]=dummy;
int i=0,k=0,sum=0,f=0;
while(i<np){
if(isEmpty(pq)){ 
gc.p[k]=p[i];
gc.start[k++]=sum;
sum+=p[i].bt;
i++;
f++;
}
else{
struct process cp=dequeue(pq);
sum+=cp.bt;
gc.p[k]=cp;
gc.start[k++]=sum;
i++;
}

for(int j=f;j<np;j++){
if(sum>p[j].at){
enqueue(pq,p[j]);
f++;
}
}
}
float tt=0,sum1=0,sum2=0;
int wt[20];
for(int i=0;i<np;i++)
{
wt[i]=sum1-gc.p[i].at;
sum2+=sum1-gc.p[i].at;
sum1+=gc.p[i].bt;
}
display(gc,np); 
printf("\nAverage waiting time=%f\n",sum2/np);
for(int i=0;i<np;i++)
tt+=wt[i]+gc.p[i].bt;
printf("Average turn around time=%f\n",tt/np);
printf("Average response time=%f\n",sum2/np);
}
}
printf("\n");
printf("Want to continue(y/n)?:");
scanf(" %c",&c);
}while(c=='y');
return 0;
}
