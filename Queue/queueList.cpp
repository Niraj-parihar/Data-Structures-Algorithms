/**
 * The code defines a queue data structure using a linked list and performs enqueue and dequeue
 * operations on it.
 * 
 * @return The main function returns 0.
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>


using namespace std;
class node 
{ 
    public:
    int data;
    struct node *next;
};
class queue 
{
 private:
 node *front;
 node *rear;
 public:
 queue(){ front=rear=NULL;}
 void equeue(int x)
 {
     node *t=new node;
     t->data=x;
        t->next=NULL;

    if(rear==NULL)
    {
        front=rear=t;
        return;
    }
        rear->next=t;
        rear=t;
 }
 int dqueue()
 { 
     int x=-1;
     if(front==NULL)
     {
         cout<<"queue is empty"<<endl;
     }
     else 
     { 
         node *p=front;
          front=front->next;
         x=p->data;
         free(p);
        
     }
     return x;
 }
 void display()
 {
    while(front!=rear)
    {
      printf("%d",front->data);
        front=front->next;
    }
 }
 
 
};

int main()
{ 
    queue q;
q.equeue(10);
q.equeue(20);
q.equeue(30);
q.display();
    return 0;
}