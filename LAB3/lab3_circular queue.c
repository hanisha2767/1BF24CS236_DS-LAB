#include <stdio.h>
#define N 5
int front=-1;
int rear=-1;
int queue[N];
void enqueue(int x)
{
    if(front==-1&&rear==-1){
        front=rear=0;
        queue[rear]=x;
    }
    else if((rear+1)%N==front){
        printf("queue overflow\n");
    }
    else{
        rear=(rear+1)%N;
        queue[rear]=x;
    }
}
void dequeue()
{
    if(front==-1&&rear==-1){
        printf("queue is empty\n");
    }
    else if(front==rear){
        front=rear=-1;
    }
    else{
        printf("removed value:%d\n",queue[front]);
        front=(front+1)%N;
    }
}
void display()
{
    if(front==-1&&rear==-1)
    {
        printf("queue is empty\n");
    }
    else if(front<=rear)
    {
        for(int i=front;i<=rear;i++)
            printf("%d\n",queue[i]);
    }
    else{
        for(int i=front;i<N;i++)
            printf("%d\n",queue[i]);
        for(int j=0;j<=rear;j++)
            printf("%d\n",queue[j]);
    }
}
void main()
{
    int ch,a;
    do{
        printf("enter choice:1.enqueue 2.dequeue 3.display\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:{printf("enter the number:\n");
                scanf("%d",&a);
                enqueue(a);
                break;}
        case 2:{dequeue();
                break;}
        case 3:{display();
                break;}
        default:printf("invalid choice");
        }
    }while(ch!=0);
}
