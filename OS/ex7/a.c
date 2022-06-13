#include <stdio.h>
#include <string.h>
int main(void)
{
int n, m, i, j, k;
while(1){

printf("Enter no. of processes: ");
scanf("%d",&n);
printf("Enter no. of resources: ");
scanf("%d",&m); 
int alloc[n][m];
printf("\n");
for(int i=0;i<n;i++){
printf("Enter p%d process's allocated resource  : ",i);
for(int j=0;j<m;j++){
scanf("%d",&alloc[i][j]);
}
}
int max[n][m];
for(int i=0;i<n;i++){
printf("Enter p%d process's max resource  : ",i);
for(int j=0;j<m;j++){
scanf("%d",&max[i][j]);
}
}
int avail[m]; 
printf("Enter available resource  : ");
for(int i=0;i<m;i++){
scanf("%d",&avail[i]);
}
int f[n], ans[n], ind = 0;
for (k = 0; k < n; k++) {
f[k] = 0;
}
int need[n][m];
for (i = 0; i < n; i++) {
for (j = 0; j < m; j++)
need[i][j] = max[i][j] - alloc[i][j];
}
printf("\nAlloc\tMax\tNeed\n");
for (int i=0;i<n;i++){
for(int j=0;j<m;j++){
printf("%d ",alloc[i][j]);
} printf("\t");
for(int j=0;j<m;j++){
printf("%d ",max[i][j]);
} printf("\t");
for(int j=0;j<m;j++){
printf("%d ",need[i][j]);
} printf("\n");
}
int y = 0, run = 1, done = 0, b;
while(run){
b = 0;
for (i = 0; i < n; i++) {
if (f[i] == 0) {
int flag = 0;
for (j = 0; j < m; j++) {
if (need[i][j] > avail[j]){
flag = 1;
break;
}
}
if (flag == 0 && f[i] == 0) {
ans[ind++] = i;
for (y = 0; y < m; y++)
avail[y] += alloc[i][y];
f[i] = 1;
b = 1;
}
}
} 
for(int k=0; k<n; k++)
{
if(f[k] == 0){
done = 0;
break;
} done =
1;
} if(done == 1
|| b
== 0)
run = 0;
} int flag =
1;
for(int i=0;i<n;i++){
if(f[i]==0)
{ flag=0;
printf("The following system is not safe\n");
break;
}
}
if(flag==1)
{
printf("Following is the SAFE Sequence\n");
for (i = 0; i < n - 1; i++)
printf(" P%d ->", ans [i]);
printf(" P%d\n", ans[n - 1]);
}
int pid;
printf("\nEnter p[_]ID for which request is needed: ");
scanf("%d",&pid);
int req[m];
printf("Enter request for process: ");
for(int i=0;i<m;i++){
scanf("%d",&req[i]);
}
printf("Enter available resource  : ");
for(int i=0;i<m;i++){
scanf("%d",&avail[i]);
}
int chk=0;
for(int i=0; i<m; i++){
if(req[i] <= need[pid][i]){
chk++;
}
if(req[i] <= avail[i]){
chk++;
}
}
if(chk == m*2){
for(int i=0; i<m; i++){
alloc[pid][i] += req[i];
avail[i] -= req[i];
need[pid][i] -= req[i];
}
printf("\nAlloc\t\tMax\t\tNeed\n");
for (int i=0;i<n;i++){
for(int j=0;j<m;j++){
printf("%d ",alloc[i][j]);
} printf("\t");
for(int j=0;j<m;j++){
printf("%d ",max[i][j]);
} printf("\t");
for(int j=0;j<m;j++){
printf("%d ",need[i][j]);
} printf("\n");
} 
for (k = 0; k < n; k++)
f[k] = 0;
int y = 0, run = 1, done = 0, b;
ind = 0;
while(run)
{
b = 0;
for (i = 0; i < n; i++)
{
if (f[i] == 0)
{
int flag = 0;
for (j = 0; j < m; j++)
{
if (need[i][j] > avail[j])
{
flag = 1;
break;
}
}
if (flag == 0 && f[i] == 0)
{
ans[ind++] = i;
for (y = 0; y < m; y++)
avail[y] += alloc[i][y];
f[i] = 1;
b = 1;
}
}} 
for(int k=0; k<n; k++){
if(f[k] == 0){
done = 0;
break;
} done =
1;
} if(done == 1|| b== 0)
run = 0;
}
int flag = 1;
for(int i=0;i<n;i++)
{
if(f[i]==0)
{
flag=0;
printf("\nThe following system is not safe!\n");
break;
}
}
if(flag == 1)
{
printf("\nFollowing is the SAFE Sequence: \n");
for (i = 0; i < n - 1; i++)
printf(" P%d ->", ans[i]);
printf(" P%d\n", ans[n - 1]);
}
} 
else{
printf("\nAvailable resources not enough, request can't be granted!\n");
}
char *ch;
printf("Do you want to run again? (y/n): ");
scanf("%s", ch);
if(strcmp(ch,"n") == 0)
break;
printf("\n\n");
}
}