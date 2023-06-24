#include<stdio.h>

struct poly1{
    int expo;
    int coef;
}a[100],b[100],c[100];

int len1,len2,k;

void main()
{
    printf("\nStarting Polynomial Addition\n");
    read1();
    display1();
    read2();
    display2();
    sum();
    display3();
}

void display1()
{
    printf("\nPrinting the First Polynomial :\n");
    for(int i=len1;i>=0;i--)
    {
        printf("x^%d +",a[i].coef);
    }
}

void display2()
{
    printf("\nPrinting the Second Polynomial :\n");
    for(int i=len2;i>=0;i--)
    {
        printf("x^%d +",b[i].coef);
    }
}

void read1()
{
    printf("\nEnter degree of first Polynomial :");
    scanf("%d",&len1);
    for(int i=len1;i>=0;i--)
    {
        printf("\nEnter the coef of x^%d",i);
        scanf("%d",&a[i].coef);
        a[i].expo=i;
    }
}

void read2()
{
    printf("\nEnter degree of second Polynomial :");
    scanf("%d",&len2);
    for(int i=len2;i>=0;i--)
    {
        printf("\nEnter the coef of x^%d",i);
        scanf("%d",&b[i].coef);
        b[i].expo=i;
    }
}

void sum()
{
    int i=0;
    int j=0;
    k=0;
    while(i<=len1 && j<=len2)
    {
        if(a[i].expo==b[i].expo)
        {
            c[k].coef=a[i].coef+b[j].coef;
            c[k].expo=i;
            k++;
            i++;
            j++;
        }
        else if (a[i].expo<b[j].expo)
        {
            c[k].coef=b[j].coef;
            c[k].expo=b[j].expo;
            j++;
            k++;
        }
        else if (a[i].expo>b[j].expo)
        {
            c[k].coef=a[i].coef;
            c[k].expo=a[i].expo;
            i++;
            k++;
        }
    }
    while(i<len1)
    {
        c[k].coef=a[i].coef;
        c[k].expo=a[i].expo;
        i++;
        k++;
    }
    while(j<len2)
    {
        c[k].coef=b[j].coef;
        c[k].expo=b[j].expo;
        j++;
        k++;    
    }
}

void display3()
{
    printf("\nPrinting the Sum Polynomial :\n");
    for(int i=k;i>=0;i--)
    {
        printf("x^%d +",c[k].coef);
    }
}

