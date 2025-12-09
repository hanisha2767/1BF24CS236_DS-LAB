#include<stdio.h>
#include<stdlib.h>
struct Node{
  int data;
  struct Node *left;
  struct Node *right;
};

struct Node*createNode(struct Node*root,int val)
{
    struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=val;
    newNode->left=newNode->right=NULL;
    return newNode;
};

struct Node*insert(struct Node*root,int val)
{
    if(root==NULL){
        return createNode(root,val);
    }
    if(root->data > val)
        root->left=insert(root->left,val);
    else if(root->data < val)
        root->right=insert(root->right,val);
    return root;
};

void inorder(struct Node*root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

void preorder(struct Node*root)
{
    if(root==NULL)
        return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct Node*root)
{
    if(root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}

void display(struct Node*root)
{
    printf("----BST----\n");
    inorder(root);
    printf("\n");
}

void main()
{
    struct Node*root=NULL;
    int val,ch;
    printf("\n 1.insert into BST, 2. inorder traverse, 3. preorder traverse, 4.postorder traverse, 5.display, 6.exit\n");
    while(1){
        printf("enter choice:\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("enter value:\n");
                   scanf("%d",&val);
                   root=insert(root,val);
                   break;
            case 2:inorder(root);
                   break;
            case 3:preorder(root);
                   break;
            case 4:postorder(root);
                   break;
            case 5:display(root);
                   break;
            case 6:exit(0);
            default:printf("invalid choice\n");
        }
    }
    return 0;
}
