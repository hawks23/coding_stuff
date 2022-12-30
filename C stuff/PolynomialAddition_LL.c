// INCOMPLETE

#include<stdio.h>;
#include<stdlib.h>;

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
    printf("\n------------------------------\nPolynomial Addition !\nEnter the power of the first polynomial :");
    scanf("%d,&len1");
    printf("\nEnter the power of the second polynomial :\n");
    scanf("%d,&len2");

    // Entering first polynomial
    for(int i=len1;i>=0;i--)
    {

        printf("Enter value of the %dth power :",i);
        scanf("%d,&data");
        poly1 = (struct poly*)malloc(sizeof(struct poly));
        poly1->coef=data;
        poly1->pow=i;
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
    printf("\nFirst Polynomial is :\n");
    traverse(p1_start);
    printf("\nSecond Polynomial is :\n");
    traverse(p2_start);
    printf("\n\n");

    // Entering second polynomial

    for(int i=len1;i>=0;i--)
    {

        printf("Enter value of the %dth power :",i);
        scanf("%d,&data");
        poly2 = (struct poly*)malloc(sizeof(struct poly));
        poly2->coef=data;
        poly2->pow=i;
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

    printf("\nFirst Polynomial is :\n");
    traverse(p1_start);
    printf("\nSecond Polynomial is :\n");
    traverse(p2_start);
    printf("\n\n");

}

