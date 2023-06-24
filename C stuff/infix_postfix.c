/*Conversion of Infix to Postfix*/
#include<stdio.h>
#include<string.h>

int top;
char exp[100];
char stack[100];

void push(char c)
{
    top++;
    stack[top]=c;
}

char pop()
{
    if(top==-1)
        return -1;
    else
        return(stack[top--]);
}

int priority(char x)
{
    if(x == '(')
        return 0;
    else if(x == '+' || x == '-')
        return 1;
    else if(x == '*' || x == '/')
        return 2;
}

void main()
{
    char s;
    printf("Enter the infix expression :");
    scanf("%s",&exp);
    int i=0;
    while(exp[i]!='\0')
    {
        if(exp[i]=='(')
        {
            push('(');
        }
        else if(isalnum(exp[i]))
        {
            printf("%c ",exp[i]);
        }
        else if(exp[i]==')')
        {
            while(s = pop()!='(')
            {
                printf("%c ",s);
            }
        }
        else
        {
            while((priority(exp[i])) <= priority(stack[top]))
            {
                char d = pop();
                printf("%c ",d);
            }
            push(exp[i]);
        }
        i++;
    }

    while(top!=-1)
    {
        char d = pop();
        printf("%c ",d);
    }
}