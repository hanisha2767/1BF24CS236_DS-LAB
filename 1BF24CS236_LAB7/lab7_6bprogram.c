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
int main() {
    int choice, value;
    printf("\n===== MENU =====\n");
        printf("1. Stack PUSH\n");
        printf("2. Stack POP\n");
        printf("3. Display Stack\n");
        printf("4. Queue ENQUEUE\n");
        printf("5. Queue DEQUEUE\n");
        printf("6. Display Queue\n");
        printf("7. Exit\n");
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to PUSH: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                displayStack();
                break;

            case 4:
                printf("Enter value to ENQUEUE: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 5:
                dequeue();
                break;

            case 6:
                displayQueue();
                break;

            case 7:
                exit(0);

            default:
                printf("\nInvalid choice! Try again.\n");
        }
    }
    return 0;
}
