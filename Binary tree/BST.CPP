// The code is implementing a binary search tree (BST) in C++. It defines a struct called "node" which represents a node in the BST. Each node has a left child, 
// a data value, and a right child. The main function creates a BST by inserting nodes using the recursive "rinsert" function. 
// It then performs an inorder traversal of the BST using the "inorder" function.

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct node 
{
    struct node *left;
    int data;
    struct node *right;
}*root=NULL;

void itrinsert(int val)
{
    struct node*p=p,*r=NULL;
    while(p!=NULL)
    {
    
    }
   p=(struct node*)malloc(sizeof(struct node));
   p->data=val;
   p->left=p->right=NULL;
   if(p->data<r->data){
    r->left=p;
   }
   else 
   {
    r->right=p;
   }

}
//recursive inserting in binary search tree
struct node* rinsert(struct node *p,int key)
{       
    struct node *t=NULL;
    if(p==NULL)
    {
        t=(struct node *)malloc(sizeof(struct node ));
        t->right=t->left=NULL;
        return t;
    }
    if(key<p->data)
    {
        //this function will return the address of the node
        p->left=rinsert(p->left,key);
    }
    else if(key>p->data)
    {
        p->right=rinsert(p->right,key);
    }
    return p;
}

//SEARCHING IN AN BINARY SEARCH TREE
bool searchBST(struct node *p,int key)
{
    if(p==NULL) return false;
    if(key==p->data)return true;
    else if(key<p->data)return searchBST(p->left,key);
    else {return searchBST(p->left,key);};
}
//deleting function
int height(struct node *p)
{
    int x,y;
    if(p!=NULL)
    {
        x=height(p->left);
       y=height(p->right);
    }
    if(x>y)
    return x+1;
    else 
    return y+1;

}
struct node *inpre(struct node *p)
{
    while(p && p->right!=NULL)
    {
        p=p->right;
    }
    return p;
}
struct node *insucc(struct node *p)
{
    while(p && p->left!=NULL)
    {
        p=p->left;
    }
    return p;
}
struct node* Delete(struct node *p,int key)
{  
    struct node *q;
    if(p==NULL)
    {
        return NULL;
    }
    if(p->left==NULL && p->right==NULL)
    {
        if(root)
        {
            root=NULL;
        }
        free(p);
        return NULL;
    }
   if(key<p->data)
   {
    p->left=Delete(p->left,key);
   }
    else if(key>p->data)
   {
    p->left=Delete(p->left,key);
   }
   //based on height going to decide which one should be
   //inorder predessor or inorder successor
   else{
   if(height(p->left)>height(p->right))
   {
    q=inpre(p->left);
    p->data=q->data;
    p->left=Delete(p->left,q->data);
   }
   else 
   {
       q=insucc(p->right);
    p->data=q->data;
    p->right=Delete(p->right,q->data);
   }
   }
   return p;
}
void inorder(struct node *p)
{
  if(p)
  {
    inorder(p->left);
    printf("%d ",p->data);
    inorder(p->right);
  }

}

int main()
{ 
    root=rinsert(root,10);
    rinsert(root,20);
    rinsert(root,30);
    rinsert(root,40);
    rinsert(root,50);
    inorder(root);
   
   return 0;
}