#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right
};

struct node* makenode(int d)
{
    struct node *p;
    p = (struct node*)malloc(sizeof(struct node));
    p->data = d;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void preorder(struct node *link)
{
    while(link!=NULL)
    {
        printf("%d",link->data);
        preorder(link->left);
        preorder(link->right);
    }
}

void create_tree(struct node *link)
{
    
    while(link!=NULL)
    {
        int c;
        struct node *x;
        printf("\nEnter Left Child (0 for none) :");
        scanf("%d",&c);
        if(c!=0)
        {
            printf("Making left");
            link->left = makenode(c);
            create_tree(link->left);    
        }

        printf("Enter Right Child (0 for none) :");
        scanf("%d",&c);
        if(c!=0)
        {
            printf("Making right");
            link->right = makenode(c);
            create_tree(link->right);
        }
    }
}

void main()
{
    printf("Enter root node :");
    int d;
    struct node *root;
    scanf("%d",&d);
    root = makenode(d);
    create_tree(root);

    printf("\nTree Created\n");
    preorder(root);
}

