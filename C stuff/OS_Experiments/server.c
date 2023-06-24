// Experiment 4

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>

int main()
{
    void *shared_memory;
    char buff[100];
    int shmid;
    shmid = shmget((key_t)3000,27,0666|IPC_CREAT);
    printf("Key of shared memory is %d\n",shmid);

    shared_memory=shmat(shmid,NULL,0);
    printf("Process attached at %p\n",shared_memory);
    printf("Enter some data to write into shared memory :");
    read(0,buff,100);
    strcpy(shared_memory,buff);
    printf("You wrote : %s\n",(char*)shared_memory);
}