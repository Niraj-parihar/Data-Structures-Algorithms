/**
 * The above code creates a binary tree, counts the number of nodes in the tree, and prints the
 * preorder traversal of the tree.
 * 
 * @param q The parameter `q` is a structure of type `queue` which is used to implement a queue data
 * structure. It has three fields:
 * @param x The variable `x` is used to store the value of each node in the binary tree.
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct node 
{
    struct node *lchild;
    int data;
    struct node *rchild;
};
struct queue
{
    int size;
    int front;
    int rear;
    struct node  **Q;
};
void equeue(struct queue *q,node* x)
{ 
   
   if(q->rear==q->size-1)
   {
    cout<<"queue is full "<<endl;
   }
   else 
   {
    q->rear++;
q->Q[q->rear]=x;
   }

}
node* dqueue(struct queue *q)
{ 
  struct node *x=NULL;
    if(q->front==q->rear)
    {
        cout<<"queue is empty"<<endl;

    }
    else 
    { 
         q->front++;
        x=q->Q[q->front];
       
    }
    return x;
}
int isempty(struct queue q)
{
        if(q.front==q.rear)
        {
            return true;
        }
        return false;
        
}
struct node *root=NULL;
void create()
{
    struct node *p,*t;
    int x;
    struct queue q;
    q.size=100;
    q.front=q.rear=-1;
    q.Q=(struct node **)malloc(sizeof(struct node*)*q.size);
    printf("entre the root value: ");
    scanf("%d",&x);
    struct node *root=(struct node *)malloc(sizeof(struct node));
    root->data=x;
    root->lchild=NULL;
    root->rchild=NULL;
    equeue(&q,root);
    while(!isempty(q))
    {
        p=dqueue(&q);
        printf("entre the left child of %d: ",p->data);
        scanf("%d",&x);
        if(x!=-1)
        {
          t=(struct node *)malloc(sizeof(struct node *));
          t->data=x;
          t->lchild=t->rchild=NULL;
          p->lchild=t;
          equeue(&q,t);
        }
        printf("entre the right child of %d: ",p->data);
        scanf("%d",&x);
        if(x!=-1)
        {
          t=(struct node *)malloc(sizeof(struct node *));
          t->data=x;
          t->lchild=t->rchild=0;
          p->rchild=t;
          equeue(&q,t);
        }
    }




}
void preorder(struct node *p)
{
   if(p!=NULL)
   {
    printf("%d ",p->data);
    preorder(p->lchild);
    preorder(p->rchild);
   }
}
void inorder(struct node *p)
{
  if(p)
  {
    inorder(p->lchild);
    printf("%d ",p->data);
    inorder(p->rchild);
  }

}
void postorder(struct node *p)
{ 
    if(p)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        printf("%d ",p->data);
    }

}

//counting node of a binary tree

int count(node *p)
{
    int x,y;
    if(p!=NULL)
    {
        x=count(p->lchild);
        y=count(p->rchild);
        return x+y+1;
    }
    else
    {
        return 0;
    }

}

int main()
{
    create();
    //preorder(root);
    int z=count(root);

    
    return 0;
}