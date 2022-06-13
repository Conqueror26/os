#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int nb, sb, nf, fs[100], choice;
char name[500][20];
struct block {
int no, status;
struct block *next_disk, *next_file, *index;
};
struct block arr[500];
struct dir {
char filename[50][20];
int start[50], end[50],index[50][50], crntptr;
};
void printdir(struct dir *ptr, int ch)
{
if(ch==0)
{
printf("\nDirectory\n\tFilename\tStart\tend");
for(int i=0;i<ptr->crntptr;i++)
printf("\n\t%7s\t%5d\t%5d\n",ptr->filename[i],ptr->start[i],ptr->end[i]);
}
else if(ch==1)
{
printf("\nDirectory\n\tFilename\tIndex Block");
for(int i=0;i<ptr->crntptr;i++)
printf("\n\t%7s\t%5d\n",ptr->filename[i],ptr->index[i][0]);
}
}
void printFileList(struct dir *dptr)
{
printf("\nIndividual File listing\n");
for(int k=0;k<dptr->crntptr;k++)
{
printf("\n%s\t",dptr->filename[k]);
struct block *ptr=&arr[dptr->start[k]];
while(ptr)
{
printf("Data Block-%d ",ptr->no);
ptr=ptr->next_file;
}
}
printf("\n");
}
void printIndex( struct dir *dptr)
{
printf("\nIndex table for all the files\n");
for(int k=0;k<dptr->crntptr;k++)
{
printf("\n%s\t",dptr->filename[k]);
for(int i=0;i<=fs[k]/sb;i++)
printf("Data Block-%d ",dptr->index[k][i]);
}
printf("\n");
}
void contiguous()
{
for (int i = 0; i < nb; i++) {
arr[i].no = i;
arr[i].status = 0; // 0 - free , 1 - occupied
arr[i - 1].next_disk = &arr[i];
if (i == nb - 1)
arr[i].next_disk = NULL;
arr[i].next_file = NULL;
arr[i].index = NULL;
}
struct dir *dptr = (struct dir *)malloc(sizeof(struct dir));
dptr->crntptr = 0;
int flag=0,tot=0;
for(int i=0;i<nf;i++)
tot+=fs[i]/sb;
for (int k = 0; k < nf; k++)
{
while (1)
{
int free = rand() % (nb+1);
struct block *ptr = &arr[free];
int c = 1;
if (ptr->status == 0) {
while (ptr->next_disk != NULL ) {
if (ptr->next_disk->status == 0) {
c++;
ptr = ptr->next_disk;
}
else
break;
}
}
if (c>=fs[k]/sb) {
int j = 0;
ptr = &arr[free];
strcpy(dptr->filename[dptr->crntptr], name[k]);
dptr->start[dptr->crntptr] = ptr->no;
while (j < fs[k]/sb) {
ptr->status = 1;
ptr = ptr->next_disk;
j++;
}
dptr->end[dptr->crntptr] = ptr->no-1;
dptr->crntptr++;
flag+=fs[k]/sb;
if(k!=nf-1)
break;
}
if(flag==tot)
{
printdir(dptr,0);
break;
}
}
}
}
void linkedlist()
{
for (int i = 0; i < nb; i++) {
arr[i].no = i;
arr[i].status = 0; // 0 - free , 1 - occupied
arr[i - 1].next_disk = &arr[i];
if (i == nb - 1)
arr[i].next_disk = NULL;
arr[i].next_file = NULL;
arr[i].index = NULL;
}
struct dir *dptr = (struct dir *)malloc(sizeof(struct dir));
dptr->crntptr = 0;
for(int k=0;k<nf;k++)
{
while(1)
{
int free=rand()%(nb+1);
struct block *ptr=&arr[free];
if(ptr->status==0)
{
ptr->status=1;
strcpy(dptr->filename[dptr->crntptr],name[k]);
dptr->start[k]=ptr->no;
int c=1;
while(c<fs[k]/sb)
{
int nextfree=rand()%(nb+1);
struct block *nptr=&arr[nextfree];
if(nptr->status==0)
{
nptr->status=1;
ptr->next_file=nptr;
ptr=nptr;
c++;
}
}
dptr->end[k]=ptr->no;
dptr->crntptr++;
break;
}
}
}
printdir(dptr,0);
printFileList(dptr);
}
void indexed()
{
for (int i = 0; i < nb; i++) {
arr[i].no = i;
arr[i].status = 0; // 0 - free , 1 - occupied
arr[i - 1].next_disk = &arr[i];
if (i == nb - 1)
arr[i].next_disk = NULL;
arr[i].next_file = NULL;
arr[i].index = NULL;
}
struct dir *dptr = (struct dir *)malloc(sizeof(struct dir));
dptr->crntptr = 0;
for(int k=0;k<nf;k++)
{
while(1)
{
int free=rand()%(nb+1);
struct block *ptr=&arr[free];
if(ptr->status==0)
{
ptr->status=1;
strcpy(dptr->filename[k],name[k]);
dptr->index[k][0]=ptr->no;
int c=0;
while(c<=fs[k]/sb)
{
int nextfree=rand()%(nb+1);
struct block *nptr=&arr[nextfree];
if(nptr->status==0)
{
nptr->status=1;
nptr->index=ptr;
dptr->index[k][k+c+1]=nptr->no;
c++;
}
}
dptr->crntptr++;
break;
}
}
}
printdir(dptr,1);
printIndex(dptr);
}
int main() {
printf("Size of each block in the disk: ");
scanf("%d", &sb);
printf("Number of disk blocks: ");
scanf("%d", &nb);
printf("Number of files to be allocated: ");
scanf("%d", &nf);
for (int i = 0; i < nf; i++) {
printf("Name of the File%d : ", i + 1);
scanf("%s", name[i]);
printf("Size of the File%d : ", i + 1);
scanf("%d", &fs[i]);
}
while (1) {
printf("\nFile Allocation Techniques\n1.Contiguous\n2.Linked "
"List\n3.Indexed\n4.Exit\nChoose the Allocation scheme:");
scanf("%d", &choice);
switch (choice) {
case 1:
contiguous();
break;
case 2:
linkedlist();
break;
case 3:
indexed();
break;
default:
return 0;
}
}
}
