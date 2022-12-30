#include<stdio.h>

int MAX_SIZE;
int a[];
int top=-1;

void main()
{
    int n;
    int ch;
    printf("Enter the max size of the stack :");
    scanf("%d",&MAX_SIZE);
    /*printf("Enter the elements size of the stack :\n");
    for(int i=0;i<MAX_SIZE;i++)
    {
        scanf("%d",&a[i]);
    }*/
    
    while(1)
    {   printf("1. Push\n2. Pull\n3. Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            default:
                break;
        }
    }
}

void push()
{  
    int element;
    if(top==MAX_SIZE-1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        printf("Enter the number to input : ");
        scanf("%d",&element);
        a[++top]=element;
    }
}

void pop()
{
    if(top==0 || top==-1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        printf("%d\n",a[top]);
        top--;
    }
}