#include<stdio.h>
int len;
int a[100];

void main()
{
    
    int len,key;
    printf("Enter length of array :");
    scanf("%d",&len);
    printf("Enter elements :\n");
    for(int i=0;i<len;i++)
    {
        scanf("%d",&a[i]);
    }
    traverse();
    bubblesort();
    printf("Enter Element to search : ");
    scanf("%d",&key);
    int mid;
    int l=0,h=(len-1);
    int flag =-1;
    while(l<=h)
    {
        mid=((l+h)/2);
        if(key==mid)
        {
            flag=1;
            break;
        }
        else if(key<a[mid])
        {
            h=(mid-1);
        }
        else if(key>a[mid])
        {
            l=(mid+1);
        }
    }
    if(flag==1)
    {
        printf("Element found\n");
    }
    else
    {
        printf("Not found\n");
    }
    traverse();
}

void bubblesort()
{
    printf("\n\n");
    int temp;
    for(int i=0;i<len;i++)
    {
        for(int j=0;j<len;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
            }
        }
    }
    printf("\n\n");
}

void traverse()
{
    for(int i=0;i<len;i++)
    {
        printf("%d ",a[i]);
    }
}