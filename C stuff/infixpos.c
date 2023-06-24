#include<stdio.h>
#include<stdlib.h>

int stack[100];
int top = -1;
int i = 0;

void push(char c)
{
    top++;
    stack[top]=c;
}

char pop()
{
    char d = stack[top--];
    return d;
}

int priority(char c)
{
    if(c=='(')
        return 0;
    if(c=='*'||c=='/')
        return 2;
    if(c=='+'||c=='-')
        return 1;
    return 0;
}

void main()
{
    char x;
    char exp[100];
    printf("Enter the expression :");
    scanf("%s",&exp);
    
    while(exp[i]!='0')
    {
        if(isalnum(exp[i]))
            printf("%c",exp[i]);
        else if(exp[i]=='(')
        {
            push('(');
        }
        else if(exp[i]==')')
        {
            do
            {
                x = pop();
                printf("%c",x);
            } while (x!='(');
        }
        else
        {
            while(priority(stack[top])>=priority(exp[i]))
            {
                printf("%c",pop());
            }
            push(exp[i]);
        }
        i++;
    }

    while(top!=-1)
    {
        printf("%c",pop());
    }
}