#include<stdlib.h>
#include <stdio.h>
#include<string.h>

typedef struct files{
	char fname[100],add[200];
}files;

typedef struct userfiledir{
	char dname[100];
	files f[100];
	int sz;
}ufd;

typedef struct mastfiledir{
	char mname[100];
	ufd dir[100];
	int sz;
}mfd;

int main()
{
  printf("1.Single Level Directory\n2.Hierarchical Structure\n");
  do{
	int choice;
	printf("Enter Choice:");
	scanf("%d",&choice);
	if(choice==1){
  	files f[100];
  	printf("1.Create File\n2.Display Table\n");
  	int op,cnt=0;
  	do{
    	printf("op:");
    	scanf("%d",&op);
    	if(op==1){
      	int flag=0;
      	files t;
      	printf("Enter filename and address:");
      	scanf("%s %s",t.fname,t.add);
      	for(int i=0;i<cnt;i++){
        	if(!strcmp(f[i].fname,t.fname) && !strcmp(f[i].add,t.add)){
          	printf("File Already Exists!!!\n");
          	flag=1;
          	break;
        	}
      	}
      	if(flag==0 || cnt==0){
        	strcpy(f[cnt].fname,t.fname);
        	strcpy(f[cnt].add,t.add);
        	cnt++;
      	}
    	}else{
      	printf("File\tAddress\n");
      	for(int i=0;i<cnt;i++){
        	printf("%s\t%s\n",f[i].fname,f[i].add);
      	}
    	}
    	int x;
    	printf("Continue?(S)");
    	scanf("%d",&x);
    	if(x==0)break;
  	}while(1);
	}else{
  	mfd master;
  	master.sz=0;
  	printf("Enter Master Directory Name:");
  	scanf("%s",master.mname);
  	printf("1.Create File\n2.Create Directory\n3.Search File\n");
  	do{  
    	int op;
    	printf("op:");
    	scanf("%d",&op);
    	if(op==1){
      	ufd tmp;
      	files t;
      	printf("Enter Directory and Filename:");
      	scanf("%s %s",tmp.dname,t.fname);
      	int uf=-1;
      	for(int i=0;i<master.sz;i++){
        	if(!strcmp(master.dir[i].dname,tmp.dname)){
          	uf=i;
          	break;
        	}
      	}
      	if(uf!=-1){
        	char addr[200];
        	strcat(addr,master.mname);
        	strcat(addr,"/");
        	strcat(addr,master.dir[uf].dname);
        	printf("Address:%s\n",addr);
        	int flag=0;
        	for(int i=0;i<master.dir[uf].sz;i++){
          	if(!strcmp(master.dir[uf].f[i].fname,t.fname)){
            	flag=1;
            	printf("File Already Exists!!!\n");
            	break;
          	}
        	}
        	if(flag==0){
          	strcpy(master.dir[uf].f[master.dir[uf].sz].fname,t.fname);
          	strcpy(master.dir[uf].f[master.dir[uf].sz].add,addr);
          	master.dir[uf].sz++;
        	}
      	}else{
        	printf("Directory Doesn't Exist!!!\n");
      	}
    	}else if(op==2){
      	ufd tmp;
      	printf("Enter Directory Name:");
      	scanf("%s",tmp.dname);
      	tmp.sz=0;
      	int flag=0;
      	for(int i=0;i<master.sz;i++){
        	if(!strcmp(master.dir[i].dname,tmp.dname)){
          	flag=1;
          	printf("Directory Already Exists\n");
          	break;
        	}
      	}
      	if(flag==0){
        	strcpy(master.dir[master.sz].dname,tmp.dname);
        	master.dir[master.sz].sz = 0;
        	master.sz++;  
      	}
    	}else{
      	printf("Enter Filename:");
      	char file[100];
      	scanf("%s",file);
      	int flag=0;
      	for(int i=0;i<master.sz;i++){
        	for(int j=0;j<master.dir[i].sz;j++){
          	if(!strcmp(master.dir[i].f[j].fname,file)){
            	printf("%s\n",master.dir[i].f[j].add);
            	flag=1;
          	}
        	}
      	}
      	if(flag==0)printf("File Doesn't Exist!!!\n");
    	}
    	int z;
    	printf("Continue?");
    	scanf("%d",&z);
    	if(z==0)break;
  	}while(1);
	}
	int y;
	printf("Continue?(S/H)");
	scanf("%d",&y);
	if(y==0)break;
  }while(1);
  return 0;
}
