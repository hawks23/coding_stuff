#include<stdio.h>
int MAX_SIZE;
int front=-1;
int rear=-1;
int a[];

void main()
{
    int n;
    int ch;
    printf("Enter the max size of the circular queue :");
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
    if(front==(rear+1)%MAX_SIZE)
    {
        printf("Circular Queue is full\n");
    }
    else
    {
        int element;
        printf("Enter element to enqueue :");
        scanf("%d",&element);
        rear = (rear+1)%MAX_SIZE;
        a[rear]=element;
    }
    if(front==-1)
    {
        front=0;
    }
}

void dequeue()
{
    if(rear==(front+1)%MAX_SIZE)
    {
        printf("Circular queue is empty\n");
    }
    else
    {
        printf("%d is dequeued\n",a[front]);
        front = (front+1)%MAX_SIZE;
    }
    if(rear==front)
    {
        rear=-1;
        front=-1;
    }
}
