#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define MAX 10
char stack[MAX];
int top=-1;
void push(char c)
{
    if(top==MAX-1)
    {
        printf("stack overflow\n");
    }
    else
    {
        top++;
        stack[top]=c;
    }
}
char pop()
{
    if(top==-1)
    {
        printf("stack underflow\n");
        return '\0';
    }
    else
    {
        printf("removed data=%c\n",stack[top]);
        char a=stack[top];
        top--;
        return a;
    }
}
char peek()
{
    if(top==-1)
    {
        printf("stack underflow\n");
        return '\0';
    }
    else
    {
        return stack[top];
    }
}
int precedence(char op)
{
    switch(op)
    {
    case'+':
    case'-':
        return 1;
    case'*':
    case'/':
        return 2;
    case'^':
        return 3;
    case'(':
        return 0;
    }
    return -1;
}
int associativity(char op)
{
    while(op=='^')
        return 1; //r-l
    return 0; //l-r
}
void infixToPostfix(char infix[],char postfix[])
{
    int j=0;
    char c;
    for(int i=0;infix[i]!='\0';i++)
    {
        c=infix[i];
        if(isalnum(c))
            postfix[j++]=c;
        else if(c=='(')
                    push(c);
        else if(c==')')
        {
            while(peek()!='(')
                    postfix[j++]=pop();
            pop(); // peek()='('
        }
        else
        {
            while(top!=-1 && (precedence(peek()) > precedence(c)||(precedence(peek())==precedence(c)&& associativity(c)==0)))
                                postfix[j++]=pop();
            push(c); // others
        }
    }
     while(top!=-1)  //pop all data
            postfix[j++]=pop();
        postfix[j]='\0';
}
int main()
{
    char infix[MAX],postfix[MAX];
    printf("enter the infix expression:\n");
    scanf("%s",infix);
    infixToPostfix(infix,postfix);
    printf("postfix expression:%s\n",postfix);
    return 0;
}

