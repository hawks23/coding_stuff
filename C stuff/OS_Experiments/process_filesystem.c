// Experiment 3.2

#include<stdio.h>
#include<sys/stat.h>

int main()
{
    char path[] = "prioQ.c";
    struct stat file_stat;
    if(stat(path,&file_stat)<0)
    {
        perror("Error :");
        return -1;
    }
    printf("File Size : %ld",(long long)file_stat.st_size);
    printf("File Owner : %d\n",file_stat.st_uid);
    printf("File Permissions : %o\n",file_stat.st_mode&0777);
    return 0;
}