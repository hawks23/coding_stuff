#include <stdio.h>
#include <stdlib.h>
// struct *node makenode(char);
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

struct node *makenode(char d)
{
    node *p;
    p = (struct node *)malloc(sizeof(struct node *));
    p->data = d;
    p->left = NULL;
    p->right = NULL;
    return p;
}
void create_tree(struct node *ptr)
{
    char x;
    if (ptr != NULL)
    {
        printf("\nEnter LCHILD(n for no data) for %c:  ", ptr->data);
        scanf(" %c", &x);
        if (x != 'n')
        {
            ptr->left = makenode(x);
            create_tree(ptr->left);
        }
        printf("\nEnter RCHILD(n for no data) for %c:  ", ptr->data);
        scanf(" %c", &x);
        if (x != 'n')
        {
            ptr->right = makenode(x);
            create_tree(ptr->right);
        }
    }
}

void preorder(node *t) // address of root node is passed in t
{
    if (t != NULL)
    {
        printf("%c\t", t->data); // visit the root
        preorder(t->left);       // preorder traversal on left subtree
        preorder(t->right);      // preorder traversal om right subtree
    }
}

void inorder(node *t) // address of root node is passed in t
{
    if (t != NULL)
    {
        inorder(t->left);        // preorder traversal on left subtree
        printf("%c\t", t->data); // visit the root
        inorder(t->right);       // preorder traversal om right subtree
    }
}
void postorder(node *t) // address of root node is passed in t
{
    if (t != NULL)
    {
        postorder(t->left);      // preorder traversal on left subtree
        postorder(t->right);     // preorder traversal om right subtree
        printf("%c\t", t->data); // visit the root
    }
}
int main()
{
    node *root;
    char data;
    printf("ENTER THE ROOT NODE:");
    scanf("%c", &data);
    root = makenode(data);
    create_tree(root);
    printf("\nThe preorder traversal of tree is:\n");
    preorder(root); // preorder traversal
    printf("\n");
    printf("\nThe preorder traversal of tree is:\n");
    inorder(root); // inorder traversal
    printf("\n");
    printf("\nThe postorder traversal of tree is:\n");
    postorder(root); // postorder traversal
    return 0;
}
