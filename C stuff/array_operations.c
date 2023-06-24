/*Program to initialize an Array and perform insertion, deletion and traversal*/

#include<stdio.h>;
int a[100];
int len =0;

void traverse()
{
    for(int i=0;i<len;i++)
    {
        printf("%d ",a[i]);
    }
}

void insert()
{
    int pos,ele;
    printf("Enter position to insert to : ");
    scanf("%d",&pos);
    printf("Enter element to insert : ");
    scanf("%d",&ele);
    for(int i=len;i>=pos;i--)
    {
        a[i]=a[i-1];
    }
    a[pos-1]=ele;
    len++;
    traverse();
}

void delete()
{
    int temp;
    int ele;
    printf("Enter element to delete : ");
    scanf("%d",&ele);
    int flag=-1;
    for(int i=0;i<len;i++)
    {
        if(a[i]==ele)
        {
            temp=a[i];
            a[i]=a[i+1];
            a[i+1]=temp;
            flag=0;
        }
    }
    if(flag==0)
    {
        len--;
        printf("\nElement deleted\n");
    }
    else
    {
        printf("\nElement not found\n");
    }
}

int main()
{
    int n;
    printf("\nEnter the number of elements in Array : ");
    scanf("%d",&n);
    printf("Enter elements :\n");
    len = n;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    traverse();
    int ch;
    while(1)
    {
        printf("\n1. Insert an element\n2. Delete an element\n3. Traverse\n");
        printf("\nEnter Choice :");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                traverse();
                break;
            default:
                return;
        }
    }
    return;
}