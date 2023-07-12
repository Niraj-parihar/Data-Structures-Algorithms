/**
 * The code creates a doubly linked list and displays its elements.
 * 
 * @param A An array of integers containing the elements of the doubly linked list.
 * @param n The variable `n` represents the number of elements in the array `A`. In this case, `n` is
 * equal to 5.
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct node 
{
    struct node *prev;
    int data;
    struct node *next;
}*head;
void create(int A[],int n)
{
    struct node *t,*last;
    head->prev=NULL;
    head->data=A[0];
    head->next=NULL;
    last=head;
    for(int i=1;i<n;i++)
    {
        t=new node;
        t->data=A[i];
        t->next=NULL;
        t->prev=last->next;
        last->next=t->prev;
        last=t;

    }

}
void display(struct node *p)
{
    while(p)
    {
        cout<<p->data<<"-><-";
        p=p->next;
    }
}
int main()
{
    int A[]={10,20,60,78,100};
    int n=5;
    create(A,n);
    display(head);
}