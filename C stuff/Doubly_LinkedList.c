// Doubly Linked List
#include<stdio.h>
#include<stdlib.h>
// Declaration

struct node{
    int data;
    struct node *next;
    struct node *prev;
}*head,*temp,*start;

create()
{
    int item;
    int i=0;
    while(i<5)
    {
        head = (struct node*)malloc(sizeof(struct node));
        printf("Enter element : ");
        scanf("%d",&item);
        head->data=item;
        head->next=NULL;

        if(start==NULL)
        {
            start = head;
            head->next=NULL;
        }

        else
        {
            temp = start;
            while(temp->next!=NULL)
            {
                temp = temp->next;  
            }
            temp->next=head;
            head->prev=temp;
        }
    i++;
    }
}

void insert_beg()
{
    int item;
    printf("\nINSERTING AT BEGINNING\n");
    head = (struct node*)malloc(sizeof(struct node));
    printf("Enter element : ");
    scanf("%d",&item);
    head->data=item;
    temp=start;
    start = head;
    head->next=temp;
}

void insert_end()
{
    int item;
    printf("\nINSERTING AT BEGINNING\n");
    head = (struct node*)malloc(sizeof(struct node));
    printf("Enter element : ");
    scanf("%d",&item);
    head->data=item;
    head->next=NULL;
    temp=start;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=head;
    head->prev=temp;
}

insert_pos()
{
    int item,pos;
    printf("\nINSERTING AT POSITION\n");
    head = (struct node*)malloc(sizeof(struct node));
    printf("Enter Element : ");
    scanf("%d",&item);
    head->data=item;
    printf("Enter Position : ");
    scanf("%d",&pos);
    temp=start;
    for(int i=0;i<pos-2;i++)
    {
        temp=temp->next;
    }
    head->next=temp->next;
    head->prev=temp;
    temp->next=head;

}

traverse()
{
    if(start==NULL)
    {
        printf("\nThe Linked List is Empty\n");
    }
    else
    {
        temp=start;
        printf("\n%d\n",temp->data);
        while(temp->next!=NULL)
        {
            temp=temp->next;
            printf("\n%d\n",temp->data);
        }

    }
}

void delete_beg()
{
    printf("\nDeleting from Beginning\n");
    if(start==NULL)
    {
        printf("\nLinked List is empty\n");
    }
    else
    {
        temp=start;
        start=temp->next;
        free(temp);
    }
}

void delete_end()
{
    printf("\nDeleting from End\n");
    if(start==NULL)
    {
        printf("\nLinked List is empty\n");
    }
    else
    {
        struct node *temporary;
        temp=start;
        while(temp->next!=NULL)
        {
            temporary=temp;
            temp=temp->next;
        }
        temp=temp->next;
        free(temp);
        temporary->next=NULL;
    }
}

void delete_pos()
{
	struct node *t;
    struct node *s;
    printf("Deleting Position to Delete :");
    int pos;
    scanf("%d",&pos);
	temp=start;
    for(int i=0;i<pos-1;i++)
	{
		t=temp;
		temp=temp->next;
	}
	t->next=temp->next;
    s=temp;
    temp=temp->next;
    temp->prev=t;
    free(s);
}

void main()
{
    create();
    int ch;
    while(1)
    {
        printf("\n\n1. Insert to beginning\n2. Insert to end\n3. Insert in a position\n4. Traverse\n5. Delete from Beginning\n6. Delete from End\n7. Delete from Position\n8. Exit\n");
        printf("Enter your choice :");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                insert_beg();
                break;
            case 2:
                insert_end();
                break;
            case 3:
                insert_pos();
                break;
            case 4:
                traverse();
                break;
            case 5:
                delete_beg();
                break;
            case 6:
                delete_end();
                break;
            case 7:
                delete_pos();
                break;

            default:
                exit(1);
        }
    }
}
