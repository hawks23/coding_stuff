#include<stdio.h>

int a[100][100],b[100][100],c[100][100],t1[100][3],t2[100][3],t3[100][3];
int p,q,m,n;
int k=1,l=1,s1=1;


void display1()
{
   printf("\nPrinting first Matrix :\n");
    for(int i=0;i<p;i++)
    {
        for(int j=0;j<q;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    } 
}

void display2()
{
   printf("\nPrinting second Matrix :\n");
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",b[i][j]);
        }
        printf("\n");
    } 
}

void read1()
{
    printf("\nReading first Matrix :\n");
    for(int i=0;i<p;i++)
    {
        for(int j=0;j<q;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
}

void read2()
{
    printf("\nReading second Matrix :\n");
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&b[i][j]);
        }
    }
}

void trip1()
{
    for(int i=0;i<p;i++)
    {
        for(int j=0;j<q;j++)
        {
            if(a[i][j]!=0)
            {
                t1[k][0]=i;
                t1[k][1]=j;
                t1[k][2]=a[i][j];
                k++;
            }
        }
    }
    t1[0][0]=p;
    t1[0][1]=q;
    t1[0][2]=k-1;
}

void trip2()
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(b[i][j]!=0)
            {
                t2[l][0]=i;
                t2[l][1]=j;
                t2[l][2]=b[i][j];
                l++;
            }
        }
    }
    t2[0][0]=m;
    t2[0][1]=n;
    t2[0][2]=l-1;
}

void disptrip1()
{
   printf("\nPrinting first Triplet :\n");
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("%d ",t1[i][j]);
        }
        printf("\n");
    } 
}

void disptrip2()
{
   printf("\nPrinting first Triplet :\n");
    for(int i=0;i<l;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("%d ",t2[i][j]);
        }
        printf("\n");
    } 
}

void sum()
{
    if(q==m)
    {
        printf("\nAddition is possible\n");
        int i=0,j=0;
        while(i<k&&j<l)
        {
            if(t1[i][0]>t2[j][0] || t1[i][1]>t2[j][1])
            {
                t3[s1][0]=t2[j][0];
                t3[s1][1]=t2[j][1];
                t3[s1][2]=t2[j][2];
                j++;
                s1++;
            }
            
            else if(t1[i][0]>t2[j][0] || t1[i][1]>t2[j][1])
            {
                t3[s1][0]=t1[i][0];
                t3[s1][1]=t1[i][1];
                t3[s1][2]=t1[i][2];
                i++;
                s1++;
            }
            else if(t1[i][0]==t2[j][0]&&t1[i][1]==t2[j][1])
            {
                t3[s1][0]=t2[j][0];
                t3[s1][1]=t2[j][1];
                t3[s1][2]=t1[i][2] + t2[j][2];
                i++;
                j++;
                s1++;
            }
        }
        while(i<k)
        {
            t3[s1][0]=t1[i][0];
            t3[s1][1]=t1[i][1];
            i++;
            s1++;
        }
        while(j<l)
        {
            t3[s1][0]=t2[j][0];
            t3[s1][1]=t2[j][1];
            j++;
            s1++;
        }

        t3[0][0]=i;
        t3[0][1]=j;
        t3[0][2]=s1-1;
    }
}

void disptrip3()
{
   printf("\nPrinting Added Triplet :\n");
    for(int i=0;i<s1;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("%d ",t3[i][j]);
        }
        printf("\n");
    } 
}

void main()
{
    printf("Enter order of first matrix : ");
    scanf("%d",&p);
    scanf("%d",&q);
    printf("Enter order of second matrix : ");
    scanf("%d",&m);
    scanf("%d",&n);
    read1();
    read2();
    display1();
    display2();
    trip1();
    trip2();
    disptrip1();
    disptrip2();
    sum();
    disptrip3();
}