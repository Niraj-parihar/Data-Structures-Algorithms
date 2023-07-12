/**
 * The above code creates a linked list, performs various operations on the linked list such as
 * counting the number of nodes, finding the sum and maximum value of the nodes, inserting and deleting
 * nodes, checking if the list is sorted, removing duplicates, reversing the list, and checking if
 * there is a loop in the list.
 * 
 * @param A An array of integers containing the elements of the linked list.
 * @param size The size parameter in the create function is the size of the array A[]. It represents
 * the number of elements in the array. In the given code, the size is 5.
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
}*head=NULL;

void create(int A[],int size)
{ 
    struct Node *last;
    head=new Node;
    struct Node *t;
    head->data=A[0];
    head->next=NULL;
    last=head;

    for(int i=1;i<size;i++)
    {
        t=new Node;
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;

    }

    
}
int count(struct Node *p)
{
    int count=0;
    while(p)
    { 
         count++;
        p=p->next;
       
    }
    return count;
}
int sum(struct Node *p)
{
    int sum=0;
    while(p)
    {
        sum+=p->data;
        p=p->next;
    }
    return sum;
}
int max(struct Node *p)
{
    int max=INT32_MIN;
    while(p)
    {
        if(max<p->data)
        {
            max=p->data;
             p=p->next;
        }
       
    }
    return max;
}
void display(struct Node *p)
{
    while(p)
    {
       cout<<p->data<<" ";
        p=p->next;
    }
}
void insert(Node *p,int pos,int x)
{
    struct Node *t;
    if(pos==0)
    { 
        t=new Node;
        t->data=x;
        t->next=head;
        head=t;

    }
    else if(pos>0)
    {
        for(int i=0;i<pos-1;i++)
        {
            p=p->next;
        }
        if(p)
        {
        t=new Node;
        t->data=x;
        t->next=p->next;
        p->next=t;
        }
     
    }
}
int Delete(int pos)
{ 
    struct Node *q=NULL;
    struct Node *p=head;
    int x=-1;
    if(pos==1)
    {
         head=head->next;
      x=p->data;
       free(p);
    }
    else if(pos>0)
    {
        for(int i=0;i<pos-1;i++)
        { 
            q=p;
            p=p->next;
        }
        q->next=p->next;
        x=p->data;
        free(p);
    }
    return x;
}
bool issorted(struct Node *p)
{
struct Node *q;
q=p->next;
while(q)
{
    if(p->data>q->data)
    {
    return false;
    }
    else 
    {
          p=p->next;
        q=q->next;
    }
     
}
return true;
}

void removedup(struct Node *p)
{  
    int x;
      struct Node *q;
    q=p->next;
    while(p)
    {
    if(p->data!=q->data)
    {
       q=p;
        p=p->next;
    }
    else 
    {
        x=q->data;
        p->next=q->next;
        free(q);
        q=p->next;
    }
    }
   
}
void reverse1(struct Node *p)
{
    int *q=new int[10];
    int i=0;
    while(p)
    {
        q[i++]=p->data;
        p=p->next;
    }
    p=head,i--;
    while(p)
    {
        p->data=q[i];
        i--;
        p=p->next;
    }
}
void reverse2(struct Node *p)
{
    struct Node *q,*r;
    q=NULL;
    r=NULL;
    while(p!=NULL)
    {
       r=q;
       q=p;
       p=p->next;
       q->next=r;

    }
    head=r;



}
bool isloop(struct Node *p)
{
    struct Node *q=p;
    do
    {
        q=q->next;
        p=p->next;
      q=q?q->next:q;

    }while(p && q && p!=q);
    if(p==q)
    {
        return true;
    }
    else 
    {
        return false;
    }
    

}
int main()
{
    int A[]={10,20,30,40,50};
    int n=5;
    Node *t1,*t2;
    t1=head->next->next;
    t2=head->next->next->next->next;
    t2->next=t1;
    create(A,n);
    cout<<isloop(head);
    return 0;

}