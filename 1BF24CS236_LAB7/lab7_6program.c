#include<stdio.h>
#include<stdlib.h>
struct Node{
   int data;
   struct Node *next;
};
struct Node *head1 = NULL;
struct Node *head2 = NULL;
struct Node* createList(int n){
   struct Node *newNode,*temp,*head=NULL;
   int data;
   if(n<=0){
    printf("number of nodes should be greater than 0\n");
    return;
   }
   for(int i=1;i<=n;i++){
    newNode=(struct Node*)malloc(sizeof(struct Node));
    if(newNode==NULL){
        printf("memory allocation fail\n");
        return;
    }
    printf("enter data :\n");
    scanf("%d",&data);
    newNode->data=data;
    newNode->next=NULL;
    if(head==NULL){
        head=newNode;
    }
    else{
        temp->next=newNode;
    }
    temp=newNode;
   }
   printf("created linked list\n");
   return head;
}
void displayList(struct Node*head)
{
    struct Node*temp=head;
    if(head==NULL){
        printf("list is empty\n");
        return;
    }
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
}
void sortList(struct Node*head)
{
    struct Node*i,*j;
    int tempData;
    if(head==NULL){
        printf("list is empty\n");
        return;
    }
    for(i=head;i->next!=NULL;i=i->next){
        for(j=i->next;j!=NULL;j=j->next){
            if(i->data > j->data){
                tempData=i->data;
                i->data=j->data;
                j->data=tempData;
            }
        }
    }
    printf("sorted the linked list\n");
}
struct Node* reverseList(struct Node*head)
{
    struct Node*prev=NULL,*curr=head,*next=NULL;
    if(head==NULL){
        printf("list is empty\n");
        return;
    }
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    printf("linked list reversed\n");
    return prev;
}
struct Node* concatList(struct Node*head1,struct Node*head2)
{
    struct Node*temp;
    if(head1==NULL)return head2;
    if(head2==NULL)return head1;
    temp=head1;
    while(head1->next!=NULL){
        temp=temp->next;
    }
    temp->next=head2;
    printf("two lists got concatenated\n");
    return head1;
}
void main()
{
    int n1,n2,ch;
    printf("1.create first list,2.create second list,3.display list1,4.display list2,5.sort list1,6.reverse list1,7.concat list1 &list2,8.display concat list\n");
    do{
        printf("enter choice:\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:{printf("enter number of nodes:");
              scanf("%d",&n1);
              head1=createList(n1);
              break;}
            case 2:{printf("enter number of nodes:");
              scanf("%d",&n2);
              head2=createList(n2);
              break;}
            case 3:{displayList(head1);
              break;}
            case 4:{displayList(head2);
              break;}
            case 5:{sortList(head1);
              break;}
            case 6:{head1=reverseList(head1);
              break;}
            case 7:{head1=concatList(head1,head2);
              head2=NULL;
              break;}
            case 8:{displayList(head1);
              break;}
            default:printf("invalid choice\n");
        }
    }while(ch!=0);
    return 0;
}
