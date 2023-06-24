// Experiment 3.3

#include<stdio.h>
#include<dirent.h>

int main()
{
    DIR *dir;
    struct dirent *dir_entry;
    dir = opendir(".");
    if (dir==NULL)
    {
        perror("Error :");
        return -1;
    }
    else
    {
        while((dir_entry=readdir(dir))!=NULL)
        {
            printf("%s\n",dir_entry->d_name);
        }
        closedir(dir);
    }
    return 0;
}