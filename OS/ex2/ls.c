#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>
#include<time.h>
void fn(DIR * fd,char *c){
if(fd!=NULL)
{
int k=0;
char *str[100];
struct dirent * ptr;
printf("\n%s:\n",c); 
while((ptr=readdir(fd))!=NULL) 
{
if(strcmp(ptr->d_name,".")!=0 && strcmp(ptr->d_name,"..")!=0){
printf("%s\t",ptr->d_name); 
str[k++]=ptr->d_name; 
}
}
int i=0;
strcat(c,"/");
while(i<k){
char new[100];
strcpy(new,c);
fn(opendir(strcat(new,str[i])),new); 
i++;
}
}
return;
}
int main(int argc,char *argv[]){
if(argc==2){
DIR * fd=opendir(argv[1]); 
struct dirent * ptr;
if(fd==NULL)
printf("Directory does not exist");

else{
while((ptr=readdir(fd))!=NULL) //reading directory
printf("%s\n",ptr->d_name);
}
closedir(fd);
}
else if(argc==3){
DIR * fd=opendir(argv[2]); //opening directory
struct dirent * ptr;
if(fd==NULL)
printf("Directory does not exist");
/*else if(ptr==NULL)
printf("Reading directory was not succesful");*/
else{
if(strcmp(argv[1],"-l")==0){
while((ptr=readdir(fd))!=NULL) //reading directory
{
struct stat sbuf;
stat(ptr->d_name,&sbuf); //creating buffer to print details
if(sbuf.st_mode & S_IREAD)
printf("r");
if(sbuf.st_mode & S_IWRITE)
printf("w");
if(sbuf.st_mode & S_IEXEC)
printf("x");
printf("\t%ld",sbuf.st_nlink);
printf("\t%ld\t",sbuf.st_size);
printf("%s\t",ptr->d_name);
printf("%s",ctime(&sbuf.st_ctime));
}
}
else if(strcmp(argv[1],"-R")==0){
fn(opendir(argv[2]),argv[2]); //calling function to print recursively
}
}
closedir(fd);
}
return 0;
}


