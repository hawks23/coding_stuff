    // Linked_List_Poly
    #include<stdio.h>
    #include<stdlib.h>

    struct poly
    {
        int coef;
        int pow;
        struct poly *link;
    }*Phead,*Qhead,*Rhead,*Pstart,*Qstart,*Rstart=NULL,*temp,*R,*P,*Q,*prev;


    void traverseP()
    {
        struct poly *temp1;
        temp1 = Pstart;
        if(Pstart==NULL)
        {
            printf("The Polynomial is Empty");
        }
        else
        {
            while(temp1->link!=NULL)
            {
                printf("%dx^%d\t",temp1->coef,temp1->pow);
                temp1=temp1->link;
            }
        }
    }

    void traverseQ()
    {
        struct poly *temp1;
        temp1 = Qstart;
        if(Qstart==NULL)
        {
            printf("The Polynomial is Empty");
        }
        else
        {
            while(temp1->link!=NULL)
            {
                printf("%dx^%d\t",temp1->coef,temp1->pow);
                temp1=temp1->link;
            }
        }
    }

    void traverseR()
    {
        struct poly *temp1;
        temp1 = Rstart;
        if(Rstart==NULL)
        {
            printf("The Polynomial is Empty");
        }
        else
        {
            while(temp1->link!=NULL)
            {
                printf("%dx^%d\t",temp1->coef,temp1->pow);
                temp1=temp1->link;
            }
        }
    }

    void main()
    {
        int len1,len2;
        int data;      // Degree of the first and second polynomial
        printf("\n------------------------------\nPolynomial Multiplication !\nEnter the Degree of the first polynomial :");
        scanf("%d",&len1);
        printf("\nWorks\n");
        printf("\nEnter the Degree of the second polynomial :\n");
        scanf("%d",&len2);

        // Entering first polynomial
        
        for(int i=len1;i>=0;i--)
        {

            printf("Enter value of the %dth power :",i);
            scanf("%d",&data);
            Phead = (struct poly*)malloc(sizeof(struct poly));
            Phead->coef=data;
            Phead->pow=i;
            if (Pstart==NULL)
            {
                Pstart=Phead;
                Pstart->link=NULL;
                temp=Pstart;
            }
            else
            {
                temp->link=Phead;
                Phead->link=NULL;
                temp=temp->link;
            }
        }
        printf("The first polynomial is :\n\n");
        traverseP();

        // Entering Second Polynomial
        for(int i=len2;i>=0;i--)
        {
            printf("Enter value of the %dth power :",i);
            scanf("%d",&data);
            Qhead = (struct poly*)malloc(sizeof(struct poly));
            Qhead->coef=data;
            Qhead->pow=i;
            if (Qstart==NULL)
            {
                Qstart=Qhead;
                Qstart->link=NULL;
                temp=Qstart;
            }
            else
            {
                temp->link=Qhead;
                Qhead->link=NULL;
                temp=temp->link;
            }
        }
        printf("The second polynomial is :\n\n");
        traverseQ();

        // Multiplication
        P = Pstart;
        while(P!=NULL)
        {
            P = Pstart;
            Q = Qstart;
            while(Q!=NULL)
            {
                Rhead = (struct poly*)malloc(sizeof(struct poly));
                Rhead->coef = P->coef * Q->coef;
                Rhead->pow = P->coef + Q->coef;
                Rhead->link = NULL;
                if(Rstart == NULL)
                {
                    Rstart = Rhead = temp;
                }
                else
                {
                    temp->link = Rhead;
                    Rhead->link = NULL;
                    temp=temp->link;
                }
                Q = Q->link;
            }
            P = P->link;
            Q = Qstart;
        }


        P=Rstart;
        while(R!=NULL)
        {
            prev=P;
            Q=P->link;
            while(Q!=NULL)
            {
                if(P->pow = Q->pow)
                {
                    P->coef = P->coef + Q->coef;
                    prev->link = Q->link;
                    free(Q);
                    Q = prev->link;
                }
                else
                {
                    prev = Q;
                    Q = Q->link;
                }
            }
            P=P->link;
        }
        traverseR();
    }