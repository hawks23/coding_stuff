/*Creation and traversal of binary tree*/
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *makenode(char d)
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = d;
    p->left = NULL;
    p->right = NULL;
    return(p);
}

void create_tree(struct node *ptr)
{
    char x;
    while(ptr!=NULL)
    {
        printf("Enter LChild (n for NULL) :\n");
        scanf("%c",&x);
        if(x!='n')
        {
            ptr->left = makenode(x);
            create_tree(ptr->left);
        }

        printf("Enter RChild (n for NULL) :\n");
        scanf("%c",&x);
        if(x!='n')
        {
            ptr->right = makenode(x);
            create_tree(ptr->right);
        }
    }
}

void preorder(struct node *q)
{
    while(q!=NULL)
    {
        printf("%c\t",q->data);
        preorder(q->left);
        preorder(q->right);
    }
}

void main()
{
    struct node *root;
    char n;
    printf("Enter the Root node :");
    scanf("%c",&n);
    root = makenode(n);
    create_tree(root);
    printf("\nPrinting the binary tree in preorder\n");
    preorder(root);
}