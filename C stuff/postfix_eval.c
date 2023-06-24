/*Evaluation of postfix expression*/
#include<stdio.h>
#include<string.h>

char exp[100];
int fix[100];
int top=-1;

void push(int c)
{
    fix[++top] = c;
}

int pop()
{
    return(fix[top--]);
}

void main()
{
    char s;
    int num;
    printf("Enter the postfix expression :");
    scanf("%s",&exp);
    int i=0;
    while(exp[i]!='\0')
    {
        if(isdigit(exp[i]))
        {
            num = exp[i]-48;
            push(num);
        }
        else
        {
            if(exp[i]=='+')
            {
                int t1 = pop();
                int t2 = pop();
                push((t2+t1));
            }
            else if(exp[i]=='-')
            {
                int t1 = pop();
                int t2 = pop();
                push((t2-t1));
            }
            else if(exp[i]=='*')
            {
                int t1 = pop();
                int t2 = pop();
                push((t2*t1));
            }
            else if(exp[i]=='+')
            {
                int t1 = pop();
                int t2 = pop();
                push((t2/t1));
            }
        }
        i++;

    }
    printf("%d ",pop());
}