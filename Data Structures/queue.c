#include<stdio.h>

int a[];
int MAX_SIZE;
front=-1;
rear=-1;

void main()
{
    int n;
    int ch;
    printf("Enter the max size of the pull :");
    scanf("%d",&MAX_SIZE);
    /*printf("Enter the elements size of the stack :\n");
    for(int i=0;i<MAX_SIZE;i++)
    {
        scanf("%d",&a[i]);
    }*/
    
    while(1)
    {   printf("1. Enqueue\n2. Dequeue\n3. Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            default:
                break;
        }
    }
}

void enqueue()
{
    if(rear==MAX_SIZE-1)
    {
        printf("Queue is full\n");
    }
    else
    {
        int element;
        printf("Enter the number to enqueue : ");
        scanf("%d",&element);
        rear++;
        a[rear]=element;
        if(front==-1)
        {
            front++;
        }
    }
}

void dequeue()
{
    if(front==-1)
    {
        printf("Queue is empty");
    }
    else
    {
        printf("&d\n",a[front]);
        front++;
    }
    if(rear==front)
    {
        rear=-1;
        front=-1;
    }
}