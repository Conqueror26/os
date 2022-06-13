#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node {
char data;
struct node *next;
};

struct node* insertNode(struct node *h, char x){
    struct node *temp = malloc(sizeof(struct node));
    temp->data = x;
    if(h == NULL)
    {
        h = temp;
        h->next = h;
    }
    else
    {
        struct node *ptr = h;
        while(ptr->next != h)
        {
            ptr = ptr->next;
        }
    ptr->next = temp;
    temp->next = h;
    }
    return h;
}
void printFrame(struct node *h)
{
    struct node *ptr = h;
    while(ptr->next != h)
    {
        printf("%c", ptr->data);
        ptr = ptr->next;
    }
    printf("%c ", ptr->data);
}
int findFrame(struct node *h, char x)
{
    struct node *ptr = h;
    if(ptr == NULL)
        eturn 0;
    while(ptr->next != h)
    {
        if(ptr->data == x)
        return 1;
        ptr = ptr->next;
    }
    if(ptr->data == x)
        return 1;
    return 0;
}
struct node* swapFrame(struct node *ptr, char x)
{
    ptr->data = x;
    ptr = ptr->next;
    return ptr;
}
struct node* swapFramelru(struct node *h, char x, char ref1[], int i, int n){
    char arr[n];
    int ind = 0;
    struct node *ptr = h;
    while(ptr->next != h){
        arr[ind++] = ptr->data;
        ptr = ptr->next;
    }
    arr[ind++] = ptr->data;
    int par = 0;
    for(int j=i; j>=0; j--){
        for(int k=0; k<n; k++){
            if(par == n-1)
                break;
            if(ref1[j] == arr[k]){
    a           rr[k] = 'a';
                par++;
    }
    }
    }
    char val;
    for(int j=0; j<n; j++){
    if(arr[j] != 'a'){
        val = arr[j];
    break;
    }
    }
    //reset ptr
    ptr = h;
    while(ptr->next != h){
    if(ptr->data == val){
    ptr = swapFrame(ptr, x);
    break;
    }
    ptr = ptr->next;
    }
    if(ptr->data == val){
    ptr = swapFrame(ptr, x);
    }
    return h;
}
struct node* swapFrameopt(struct node *h, char x, char ref1[], int i, int n,char fif[]){
char arr[n];
int ind = 0;
struct node *ptr = h;
while(ptr->next != h){
arr[ind++] = ptr->data;
ptr = ptr->next;
}
arr[ind++] = ptr->data;
int par = 0;
for(int j=i+1; j<strlen(ref1); j++){
for(int k=0; k<strlen(ref1); k++){
if(par == n-1)
break;
if(ref1[j] == arr[k]){
arr[k] = 'a';
par++;
}
}
}
//int flag=0;
char val;
/*for(int k=strlen(ref1)-1;k>i;k--){
for(int z=0;z<n;z++){
if(ref1[k]==arr[z]){
val=ref1[k];
flag=1;
break;
}
}
}*/
int flag=0;
if(par==n-1){
for(int j=0; j<n; j++){
if(arr[j] != 'a'){
val = arr[j];
break;
}
}
}
else{
for(int pt=0;pt<n && flag==0;pt++){
for(int k1=0;k1<n;k1++){
if(fif[pt]==arr[k1]){
val=fif[pt];
flag=1;
}
}
}
}
//reset ptr
ptr = h;
while(ptr->next != h){
if(ptr->data == val){
ptr = swapFrame(ptr, x);
break;
}
ptr = ptr->next;
}
if(ptr->data == val){
ptr = swapFrame(ptr, x);
}
int temp;
for(int z=0;z<n;z++){
if(fif[z]==val){
temp=z;
}
}
for(int z=temp+1;z<n;z++){
fif[z-1]=fif[z];
}
fif[n-1]=x;
return h;
}
struct node* swapFramelfu(struct node *h, char x, char ref1[], int i, int n){
char arr[n];
int ind = 0;
struct node *ptr = h;
while(ptr->next != h){
arr[ind++] = ptr->data;
ptr = ptr->next;
}
arr[ind++] = ptr->data;
// for finding freq of each page in ref string
int freq[n];
for(int j=0; j<i; j++){
for(int k=0; k<n; k++){
if(ref1[j] == arr[k]){
freq[k]++;
}
}
}
// finding min freq
int minf = freq[0], minj = 0;
for(int j = 1; j < n; j++){
if(freq[j] < minf){
minj = j;
minf = freq[j];
}
}
// checking exception case if more than one min value in freq
int fifo = 0;
char dupf[n];
for(int j = 0; j < n; j++)
if(freq[j] == minj)
dupf[fifo++] = arr[j];
// no duplicate min values
if(fifo == 1){
char val = arr[minf];
//reset ptr
ptr = h;
while(ptr->next != h){
if(ptr->data == val){
ptr = swapFrame(ptr, x);
break;
}
ptr = ptr->next;
}
if(ptr->data == val){
ptr = swapFrame(ptr, x);
}
}
else{
for(int j = 0; j < fifo; j++){
for(int k=0; k<i; k++){
//cont here
}
}
}
return h;
}
int main(void){
int N, n, count, i;
char ref[50];
char fif[10];
struct node *headfifo = NULL;
struct node *headopt = NULL;
struct node *headlru = NULL;
struct node *headlfu = NULL;
printf("\tPage replacement\n");
while(1){
printf("\n---MENU---\n1. Read input\n2. FIFO\n3. OPTIMAL\n4. LRU\n5. LFU\n6. EXIT\n");
int ch;
printf("Enter choice(1-6): ");
scanf("%d",&ch);
switch (ch){
case 1:
printf("\nNo. of free frames: ");
scanf("%d",&N);
printf("No. of frames for the process: ");
scanf("%d",&n);
printf("Enter the referrence string: ");
scanf("%s",ref);
break;
case 2:
headfifo = NULL;
count = 0;
printf("\nFIFO Frame allocations:-\n\n");
printf("Input\tframe \tpage faults");
// For allocating first n frames
for(i=0; i < strlen(ref) && count < n; i++){
if(findFrame(headfifo, ref[i]) == 0){
headfifo = insertNode(headfifo, ref[i]);
printf("\n%c ",ref[i]);
printFrame(headfifo);
count++;
printf(" %d\n",count);
}
}
struct node *ptrfifo = headfifo;
for(i=0; i<strlen(ref); i++){
if(findFrame(headfifo, ref[i]) == 0){
ptrfifo = swapFrame(ptrfifo, ref[i]);
count++;
printf("\n%c ",ref[i]);
printFrame(headfifo);
printf(" %d\n",count);
}
}
printf("\nTotal page faults: %d\n",count);
break;
case 3:
printf("\nOPTIMAL Frame allocations:-\n\n");
printf("Input\tframe \tpage faults");
headopt = NULL;
count = 0;
for(i=0; i < strlen(ref) && count < n; i++){
if(findFrame(headopt, ref[i]) == 0){
headopt = insertNode(headopt, ref[i]);
printf("\n%c\t",ref[i]);
printFrame(headopt);
fif[count]=ref[i];
count++;
printf("\t%d\n",count);
}
}
for(;i < strlen(ref); i++){
    if(findFrame(headopt, ref[i]) == 0){
headopt = swapFrameopt(headopt, ref[i], ref, i, n, fif);
count++;
printf("\n%c\t",ref[i]);
printFrame(headopt);
printf("\t%d\n",count);
}
}
printf("\nTotal page faults: %d\n",count);
break;
case 4:
printf("\nLRU Frame allocations:-\n");
printf("Input\tframe \tpage faults");
headlru = NULL;
count = 0;
for(i=0; i < strlen(ref) && count < n; i++){
if(findFrame(headlru, ref[i]) == 0){
headlru = insertNode(headlru, ref[i]);
printf("\n%c ",ref[i]);
printFrame(headlru);
count++;
printf(" %d\n",count);
}
}
for(; i < strlen(ref); i++){
if(findFrame(headlru, ref[i]) == 0){
headlru = swapFramelru(headlru, ref[i], ref, i, n);
count++;
printf("\n%c ",ref[i]);
printFrame(headlru);
printf(" %d\n",count);
}
}
printf("\nTotal page faults: %d\n",count);
break;
case 5:
printf("\nLFU Frame allocations:-\n");
printf("Input\tframe \tpage faults");
headlfu = NULL;
count = 0;
for(i=0; i < strlen(ref) && count < n; i++){
    if(findFrame(headlfu, ref[i]) == 0){
headlfu = insertNode(headlfu, ref[i]);
printf("\n%c ",ref[i]);
printFrame(headlfu);
count++;
printf(" %d\n",count);
}
}
for(; i < strlen(ref); i++){
if(findFrame(headlfu, ref[i]) == 0){
headlfu = swapFramelru(headlfu, ref[i], ref, i, n);
count++;
printf("\n%c ",ref[i]);
printFrame(headlfu);
printf(" %d\n",count);
}
}
printf("\nTotal page faults: %d\n",count);
break;
case 6:
printf("--Exiting Menu---\n");
exit(1);
break;
default:
printf("Wrong input, enter again!\n");
break;
}
}
}
