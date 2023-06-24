#include <stdio.h>
#include <stdlib.h>

struct poly
{
    int coeff;
    int expo;
    struct poly *link;
} *PHead, *QHead, *RHead, *P = NULL, *Q = NULL, *R = NULL, *Head, *Temp1, *Temp2;

// Phead is start, P is temp;

void create_first(int expo, int coeff)
{
    Head = (struct poly *)malloc(sizeof(struct poly));
    Head->coeff = coeff;
    Head->expo = expo;
    if (PHead == NULL)
    {
        PHead = P = Head;
        P->link = NULL;
    }

    else
    {
        P->link = Head;
        P = P->link;
    }
}
void create_second(int expo, int coeff)
{
    Head = (struct poly *)malloc(sizeof(struct poly));
    Head->coeff = coeff;
    Head->expo = expo;
    if (QHead == NULL)
    {
        QHead = Q = Head;
        Q->link = NULL;
    }

    else
    {
        Q->link = Head;
        Q = Q->link;
    }
}

void multi()
{
    P = PHead; // temp=start;
    Q = QHead;
    RHead = NULL;
    while (P != NULL)
    {
        while (Q != NULL)
        {
            Head = (struct poly *)malloc(sizeof(struct poly));
            Head->coeff = P->coeff * Q->coeff;
            Head->expo = P->expo + Q->expo;
            Head->link = NULL;
            if (RHead == NULL)
            {
                RHead = R = Head;
            }
            else
            {
                R->link = Head;
                R = R->link;
            }
            Q = Q->link;
        }
        P = P->link;
        Q = QHead;
    }
    R = RHead; //temp = start;
    while (R != NULL)
    {
        Temp1 = R;
        Temp2 = R->link;
        while (Temp2 != NULL)
        {
            if (R->expo == Temp2->expo)
            {
                R->coeff = R->coeff + Temp2->coeff;
                Temp1->link = Temp2->link;
                free(Temp2);
                Temp2 = Temp1->link;
            }
            else
            {
                Temp1 = Temp2;
                Temp2 = Temp2->link;
            }
        }
        R = R->link;
    }
}

void traverse_first()
{
    P = PHead;
    if (P == NULL)
    {
        printf("Empty List!");
    }
    else
    {
        P = PHead;
        while (P->link != NULL)
        {
            printf("%d^%d + ", P->coeff, P->expo);
            P = P->link;
        }
        printf("%d^%d\n", P->coeff, P->expo);
    }
}
void traverse_second()
{
    Q = QHead;
    if (Q == NULL)
    {
        printf("Empty List!");
    }
    else
    {
        Q = QHead;
        while (Q->link != NULL)
        {
            printf("%d^%d + ", Q->coeff, Q->expo);
            Q = Q->link;
        }
        printf("%d^%d\n", Q->coeff, Q->expo);
    }
}
void traverse_result()

{
    R = RHead;
    if (R == NULL)
    {
        printf("Empty List!");
    }
    else
    {
        R = RHead;
        while (R->link != NULL)
        {
            printf("%d^%d + ", R->coeff, R->expo);
            R = R->link;
        }
        printf("%d^%d\n", R->coeff, R->expo);
    }
}
void main()
{
    int n, item;
    printf("Enter the first polynomial's highest degree: ");
    scanf("%d", &n);
    for (; n >= 0; n--)
    {
        printf("Enter the coefficent of degree %d : ", n);
        scanf("%d", &item);
        create_first(n, item);
    }
    printf("Enter the second polynomial's highest degree: ");
    scanf("%d", &n);
    for (; n >= 0; n--)
    {
        printf("Enter the coefficent of degree %d : ", n);
        scanf("%d", &item);
        create_second(n, item);
    }
    printf("\nThe Two Polynomials and the result are given below: \n");
    traverse_first();
    traverse_second();
    multi();
    traverse_result();
}