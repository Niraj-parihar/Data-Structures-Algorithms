/**
 * The code creates a circular linked list, inserts a node at a given position, and displays the
 * elements of the linked list.
 * 
 * @param A An array of integers containing the elements to be inserted into the circular linked list.
 * @param n The variable `n` represents the number of elements in the array `A`. In this case, `n` is
 * equal to 5.
 */
#include<iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
struct node 
{
    int data;
    struct node *next;
}*head=NULL;


void create(int A[],int n)
{
    struct node *t,*last;
    head=new node;
    head->data=A[0];
    head->next=NULL;
    last=head;
    for(int i=1;i<n;i++)
    {
        t=new node;
        t->data=A[i];
        t->next=last->next;
        last->next=t;
        last=t;

    }
}
void insert(int pos,int x)
{ 
    struct node *t=new node;
    struct node *p=head;
    t->data=x;
    if(pos==0)
    {
         head=t;
        head->next=head;

    }
    else if(pos>0)
    {
        for(int i=0;i<pos-1;i++)
        {
            p=p->next;
        }
       p->next=t;
       t->next=head;
       head=t;
       


    }
}
int Delete(struct node *p,int pos)
{
    int x;
    struct node *q;
    for(int i=0;i<pos-2;i++)
    {
       p=p->next;
    }
    q=p->next;
    p->next=q->next;
    x=q->data;
    free(q);

}
int delfirstnode(struct node *p)
{
    int x;

    while(p!=head)
    {
        p=p->next;

    }
    p->next=head->next;
    x=head->data;
    free(head);
    head=p->next;
    return x;

}
void display(struct node *p)
{
    do
    {
        cout<<p->data<<" ";
        p=p->next;
    }while(p->next!=head);

}

int main()
{

int A[]={10,20,30,40,50};
int n=5;
create(A,n);
insert(6,60);
display(head);

    return 0;
}