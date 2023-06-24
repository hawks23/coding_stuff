#include<stdio.h>;

int MAX_SIZE = 7;
int front = -1;
int rear = -1;

struct pQ
{
    int data;
    int priority;
}Q[100];

void main()
{
    int ch;
    while(1)
    {
        printf("\n1. Enqueue\n2 Dequeue\n3 .Traverse\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                traverse();
                break;
        }
    }
}

void enqueue()
{
    if(rear==MAX_SIZE)
    {
        printf("Queue is full");
        return;
    }
    else
    {
        if(front == -1)
        {
            front = 0;
        }
        rear++;
        printf("\nEnter data :");
        scanf("%d",&Q[rear].data);
        printf("\nEnter priority :");
        scanf("%d",&Q[rear].priority);
        printf("\nValue Inserted\n");
    }
    traverse();
}

void dequeue()
{
    if(front == -1)
    {
        printf("\nQueue is empty\n");
        return;
    }
    else
    {
        bubblesort();
        if(front==rear)
        {
            printf("\nDequeueing %d of priority %d\n",Q[front].data,Q[front].priority);
            front = -1;
            rear = -1;
        }
        else
        {
            printf("\nDequeueing %d of priority %d\n",Q[front].data,Q[front].priority);
            front++;
        }
    }
    traverse();
}

void bubblesort()
{
    for(int i=front;i<=rear;i++)
    {
        for(int j=front;j<rear-i-1;j++)
        {
            if(Q[j].priority > Q[j+1].priority)
            {
                struct pQ temp = Q[j];
                Q[j]=Q[j+1];
                Q[j+1]=temp;
            }
        }
    }
    printf("\nSorted\n");
    traverse();
}

void traverse()
{
    printf("\nTraversing\n");
    if(front == - 1)
    {
        printf("\nQueue is empty\n");
        return;
    }
    else
    {
        for(int i=front;i<=rear;i++)
        {
            printf("\n%d is data and %d is priority\n",Q[i].data,Q[i].priority);
        }
    }
    
}