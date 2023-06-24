#include <stdio.h>
#include <stdlib.h>
int c;
struct node
{
    int data;
    struct node *link;
}*start,*temp,*head,*last;


void create()
{
    printf("Creating the Linked List.\n\n");
    int j=0;
    start=NULL; 
    while(j<5)
    {
        int item;
        head = (struct node*)malloc(sizeof(struct node));
        printf("Enter element :");
        scanf("%d",&item);
        head->data=item;

        if(start==NULL)
        {
            start=head;
            temp=head;
            last=head;
            head->link=start;
        }
        else
        {
            temp->link=head;
            temp=head;
            head->link=start;
            last=head;
        }
        j++;
        c++;
    }
}

void traverse()
{
    printf("\nTraversing\n");
    if(start==NULL)
    {
        printf("LinkedList is empty");
    }
    else
    {   
        temp=start;
        printf("%d\n",temp->data);
        while(temp!=last)
        {
            temp=temp->link;
            printf("%d\n",temp->data);
        }
    }
}

void insert_beg()
{
    int item;
    head = (struct node*)malloc(sizeof(struct node));
    printf("Enter element to add at beginning :");
    scanf("%d",&item);
    head->data=item;
    temp=start;
    start=head;
    head->link=temp;
    last->link=start;
}

void insert_pos()
{
    int item;
    head = (struct node*)malloc(sizeof(struct node));
    printf("Enter element to add at position :");
    scanf("%d",&item);
    head->data=item;
    int pos;
    printf("Enter Position :");
    scanf("%d",&pos);
    temp=start;
    if(pos==1)
    {
        insert_beg();
        return;
    }
    else if(pos==c)
    {
        insert_end();
        return;
    }
    else
    {
        for(int i=0;i<pos-2;i++)
        {
            temp=temp->link;
        }
        head->link=temp->link;
        temp->link=head;
    }
}

void insert_end()
{
    int item;
    head = (struct node*)malloc(sizeof(struct node));
    printf("Enter element to add at end :");
    scanf("%d",&item);
    head->data=item;
	head->link=start;
    printf("INSERTING");
    last->link=head;
    last=head;
}

void delete_beg()
{
    printf("\nDeleting First Element\n");
    temp=start;
    start=temp->link;
    free(temp);
    temp=start;
    while(temp->link!=NULL)
    {
        temp=temp->link;
    }
    temp->link=start;
}

void delete_end()
{
    struct node *t;
    printf("\nDeleting last Element\n");
    temp=start;
    while(temp->link!=NULL)
    {
        t=temp;
        temp=temp->link;
    }
    temp=temp->link;
    free(temp);
    t->link=start;
}

void delete_pos()
{
	struct node *t;
    printf("Deleting Position to delete :");
    int pos;
    scanf("%d",&pos);
	temp=start;
    for(int i=0;i<pos-1;i++)
	{
		t=temp;
		temp=temp->link;
	}
	t->link=temp->link;
	free(temp);
}

void main()
{
    create();
    int ch;
    int x=0;
    while(1)
    {
        printf("\n\n1. Insert to beginning\n2. Insert to end\n3. Insert in a position\n4. Delete from beginning\n5. Delete from end\n6. Delete from position\n7. Traverse\n8. Exit\n\n");
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
                delete_beg();
                break;
            case 5:
                delete_end();
                break;
            case 6:
                delete_pos();
                break;
            case 7:
                traverse();
                break;
            case 8:
                x=1;
                break;
            default:
                break;
        }
        if(x==1)
        {
            exit(0);
        }
    }
}