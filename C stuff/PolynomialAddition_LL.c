// INCOMPLETE

#include<stdio.h>
#include<stdlib.h>

struct poly
{
    int coef;
    int pow;
    struct poly *link;
}*poly1,*poly2,*result,*p1_start,*p2_start,*temp;
;
void traverse(struct poly *start)
{
    temp=start;
    while(temp!=NULL)
    {
        printf("\n\nPower = %d\nCoef = %d\n\n",temp->pow,temp->coef);
        temp=temp->link;
    }
}

void addition()
{

}


void main()
{
    printf("Hello World");
    int len1,len2;
    int data;      // Degree of the first and second polynomial
    printf("\n------------------------------\nPolynomial Addition !\n");

    // Entering first polynomial
    while(1)
    {
        printf("Enter value of the degree :");
        scanf("%d",&len1);
        if(len1==-1)
        {
            break;
        }
        else
        {
            poly1 = (struct poly*)malloc(sizeof(struct poly));
            printf("Enter the coefficient of %d :",len1);
            scanf("%d",&data);
            poly1->coef=data;
            poly1->pow=len1;
            if (p1_start==NULL)
            {
                p1_start=poly1;
                p1_start->link=NULL;
                temp=p1_start;
            }
            else
            {
                temp->link=poly1;
                poly1->link=NULL;
                temp=temp->link;
            }
        }
        
    }
    printf("\nFirst Polynomial is :\n");
    traverse(p1_start);

    // Entering second polynomial

    while(1)
    {
        printf("Enter value of the degree :");
        scanf("%d",&len2);
        if(len2==-1)
        {
            break;
        }
        else
        {
            poly2 = (struct poly*)malloc(sizeof(struct poly));
            printf("Enter the coefficient of %d :",len2);
            scanf("%d",&data);
            poly2->coef=data;
            poly2->pow=len1;
            if (p2_start==NULL)
            {
                p2_start=poly2;
                p2_start->link=NULL;
                temp=p2_start;
            }
            else
            {
                temp->link=poly2;
                poly2->link=NULL;
                temp=temp->link;
            }
        }
        
    }
    
    printf("\nSecond Polynomial is :\n");
    traverse(p2_start);
    printf("\n\n");

}

