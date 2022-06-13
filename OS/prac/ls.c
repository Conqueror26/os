#include<stdio.h>
#include<dirent.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
if(argc!=2)
{
    printf("Enter 2 parameters! Terminating!");
    return 0;
}

DIR *folder;
struct dirent *entry;
folder=opendir(argv[1]);
if(folder==NULL)
{
    printf("Unable to open directory");
    return 0;
}

while(entry=readdir(folder))
{
    printf("%s ",entry->d_name);
}
    printf("\n");
    closedir(folder);
    return 0;
}