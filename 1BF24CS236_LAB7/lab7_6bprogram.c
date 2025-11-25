#include<stdio.h>
#include<stdlib.h>
struct Node{
   int data;
   struct Node *next;
};
struct Node*top=NULL;
struct Node*front=NULL;
struct Node*rear=NULL;
struct Node* createNode(int val)
{
  struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
  newNode->data=val;
  newNode->next=NULL;
  return newNode;
}
void push(int val)
{
    struct Node*newNode=createNode(val);
    newNode->next=top;
    top=newNode;
    printf("pushed val onto the stack\n");
}
void pop()
{
    struct Node*temp=top;
    if(top==NULL){
        printf("stack is empty\n");
        return;
    }
    printf("removed element is %d\n",top->data);
    top=top->next;
    free(temp);
}
void displayStack()
{
    struct Node*temp=top;
    if(top==NULL){
        printf("stack is empty\n");
        return;
    }
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
}

void enqueue(int val)
{
     struct Node*newNode=createNode(val);
     if(rear==NULL){
        front=rear=newNode;
     }
     else{
        rear->next=newNode;
        rear=newNode;
     }
     printf("enqueued the element in queue\n");
}
void dequeue()
{
    struct Node*temp;
    if(front==NULL){
        printf("queue is empty\n");
        return;
    }
    temp=front;
    printf("removed element is %d\n",front->data);
    front=front->next;
    if(front==NULL){
        rear=NULL;
    }
    free(temp);
}
void displayQueue()
{
    struct Node*temp=front;
    if(front==NULL){
        printf("queue is empty\n");
        return;
    }
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
}
void main()
{
    int choice,val,ch;
    printf("1.stack operations,2.queue operations\n");
    do{
        printf("enter operation choice:\n");
        scanf("%d",&choice);
        switch(choice)
        {
          case 1:
              {
                  printf("1.push,2.pop,3.display\n");
                  do{
                    printf("enter choice:\n");
                    scanf("%d",ch);
                    switch(ch)
                    {
                        case 1:{printf("enter value to push:\n");
                           scanf("%d",&val);
                           push(val);
                           break;}
                        case 2:{pop();
                           break;}
                        case 3:{displayStack();
                           break;}
                        default:printf("invalid choice\n");
                    }
                  }while(ch!=0);
                  break;}
                        case 2:
                            {
                                 printf("1.enqueue,2.dequeue,3.display\n");
                  do{
                    printf("enter choice:\n");
                    scanf("%d",ch);
                    switch(ch)
                    {
                        case 1:{printf("enter value to enqueue:\n");
                           scanf("%d",&val);
                           enqueue(val);
                           break;}
                        case 2:{dequeue();
                           break;}
                        case 3:{displayQueue();
                           break;}
                        default:printf("invalid choice\n");
                    }
                  }while(ch!=0);
                  break;
                            }
                        default:printf("invalid choice\n");
        }
    }while(choice!=0);
    return 0;
}
