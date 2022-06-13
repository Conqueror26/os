#include <stdio.h>
#include <string.h>
int main(void){
int n, m, i, j, k;
while(1){

printf("Enter no. of processes: ");
scanf("%d",&n); 
printf("Enter no. of resources: ");
scanf("%d",&m); 
int alloc[n][m];
printf("\n");
for(int i=0;i<n;i++){
printf("Enter p%d process's allocated resource : ",i);
for(int j=0;j<m;j++){
scanf("%d",&alloc[i][j]);
}
}
int req[n][m];
for(int i=0;i<n;i++){
printf("Enter p%d process's Request resource  : ",i);
for(int j=0;j<m;j++){
scanf("%d",&req[i][j]);
}
}
int avail[m]; 
printf("Enter available resource : ");
for(int i=0;i<m;i++){
scanf("%d",&avail[i]);
}
int f[n], ind = 0;
for (k = 0; k < n; k++) {
f[k] = 0;
}
printf("\nAlloc\tRequest\n");
for (int i=0;i<n;i++){
for(int j=0;j<m;j++){
printf("%d ",alloc[i][j]);
} printf("\t");
for(int j=0;j<m;j++){
printf("%d ",req[i][j]);
} printf("\n");
}
int y = 0, run = 1, done = 0, b;
while(run){
b = 0;
for (i = 0; i < n; i++) {
if (f[i] == 0) {
int flag = 0;
for (j = 0; j < m; j++) {
if (req[i][j] > avail[j]){
flag = 1;
break;
}
}
if (flag == 0 && f[i] == 0) {
for (y = 0; y < m; y++)
avail[y] += alloc[i][y];
f[i] = 1;
b = 1;
}
}
} for(int k=0; k<n; k++){
if(f[k] == 0){
done = 0;
break;
} done =
1;
} 
if(done == 1|| b== 0)
run = 0;
}
int flag = 1;
for(int i=0;i<n;i++){
if(f[i] == 0)
{
flag = 0;
printf("\nThe following system is not safe\nDeadlocked processes are:- \n");
break;
}
}
if(flag == 0){
for(int i=0; i<n; i++){
if(f[i] == 0){
printf("p%d ", i);
}
} printf("\n");
}
else
printf("System is free of deadlock!\n");
char *ch;
printf("Do you want to run again? (y/n): ");
scanf("%s", ch);
if(strcmp(ch,"n") == 0)
break;
printf("\n\n");
}
}