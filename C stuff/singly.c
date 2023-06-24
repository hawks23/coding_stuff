#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
}*start,*temp;


void add()
{
    struct node *head;
    head = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter data :");
    scanf("%d",&head->data);
    head->link=NULL;
    if(start==NULL)
    {
        start = head;
        temp = head;
    }
    else
    {
        temp->link = head;
        temp=temp->link;
    }
}

void traverse()
{
    if(start==NULL)
    {
        printf("\nEmpty List\n");
        return;
    }
    else
    {
        temp = start;
        while(temp->link!=NULL)
        {
            if(temp->data%2==0)
            {
                printf("%d",temp->data);
            }
            temp=temp->link;
        }
    }
}

void delete()
{
    if(start==NULL)
    {
        printf("\nEmpty List\n");
        return;
    }
    else
    {
        struct node *t;
        temp = start;
        while(temp->link!=NULL)
        {
            t=temp;
            temp=temp->link;
        }
        t->link=NULL;
        free(temp);
    }
}

void main()
{
    int ch;
    while(1)
    {
        printf("\n1. Add element\n2. Remove last element\n3. Print even nums\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                add();
                break;
            case 2:
                delete();
                break;
            case 3:
                traverse();
                break;
        }
    }
}