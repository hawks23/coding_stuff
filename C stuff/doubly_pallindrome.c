#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct word
{
    char letter;
    struct word* next;
    struct word* prev;
}*start1,*start2,*temp1,*temp2,*last1,*last2,*head1,*head2;


void traverse()
{
    if(start1==NULL)
    {
        printf("\nEmpty\n");
    }
    else
    {
        temp2=last1;
        temp1=start1;
        while(temp1!=NULL&&temp2!=NULL)
        {
            if(temp1->letter==temp2->letter)
            printf("%c",temp1->letter);
            printf("%c",temp2->letter);
            temp1=temp1->next;
            temp2=temp2->prev;
        }
    }
}

void main()
{
    char str1[100];
    char str2[100];
    printf("\nEnter the first word :");
    gets(str1);
    int len1 = strlen(str1);
    for(int i=0;i<len1;i++)
    {
        head1 = (struct word*)malloc(sizeof(struct word));
        head1->letter=str1[i];
        head1->prev=NULL;
        head1->next=NULL;
        if(start1==NULL)
        {
            start1=head1;
            temp1=start1;
        }
        else
        {
            temp1->next=head1;
            head1->prev=temp1;
            temp1=temp1->next;
            last1=temp1;
        }
    }
    traverse();
}