#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<string.h>
#include<dirent.h>

int main(int argc, char **argv)
{
    DIR*fol;
    struct dirent *entry;
    fol=opendir(argv[1]);
    if(fol==NULL)
    {
        return 0;
    }
    while(entry=readdir(fol))
    {
        printf("%ld %d %d %s\n",entry->d_ino,entry->d_reclen,entry->d_type,entry->d_name);
        
      
    }
    closedir(fol);
}