#include <stdio.h>
#define N 5
int stack[N];
int top=-1;
void push()
{
    int x;
    printf("enter data\n");
    scanf("%d",&x);
    if(top==N-1)
    {
        printf("stack overflow\n");
    }
    else{
        top++;
        stack[top]=x;
    }
}
void pop()
{
    int item;
    if(top==-1){
        printf("stack is empty\n");
    }
    else{
        item=stack[top];
        top--;
        printf("removed number:%d\n",item);
    }
}
void peek()
{
    if(top==-1){
        printf("stack underflow\n");
    }
    else{
        printf("%d\n",stack[top]);
    }
}
void display()
{
    if(top==-1){
        printf("stack underflow\n");
    }
    else{
        for(int i=top; i>-1; i--){
            printf("%d\n",stack[i]);
        }
    }
}
void main()
{
    int ch;
    do{
        printf("enter choice:1.Push 2.Pop 3.Peek 4.Display\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:{
                push();
                break;
            }
            case 2:{
                pop();
                break;
            }
            case 3:{
                peek();
                break;
            }
            case 4:{
                display();
                break;
            }
            default:{
                printf("Invalid choice\n");
            }
        }
    }while (ch!=0);
}
