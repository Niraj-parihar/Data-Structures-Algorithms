/**
 * The code defines two types of queues - a regular queue using an array and a circular queue.
 * 
 * @param q The parameter `q` is a structure of type `queue` which represents the queue data structure.
 * It has the following members:
 * @param x The parameter `x` is an integer value that represents the element to be enqueued or
 * dequeued from the queue.
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

//queue using array

struct queue
{
    int size;
    int front;
    int rear;
    int *Q;
};
void equeue(struct queue *q,int x)
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
int dqueue(struct queue *q)
{ 
    int x=0;
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
int first(struct queue q)
{
    return q.Q[q.front];
}
int last(struct queue q)
{
    return q.Q[q.rear];
}

int isempty(struct queue q)
{
        if(q.front==q.rear)
        {
            return true;
        }
        return false;
        
}
int isfull(struct queue q)
{
    if(q.rear==q.size-1)
    {
        return true;
    }
    return false;
}

// circular queue
void enqueue(struct queue *q,int x)
{
    if((q->rear+1)%q->size==q->front)
    {
        cout<<"queue is full "<<endl;
    }
    else 
    {
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear]=x;
    }
}
int dequeue(struct queue *q)
{
    int x=-1;
    if(q->rear==q->front)
    {
        cout<<"queue is empty "<<endl;
    }
    else 
    {
        q->front=(q->front+1)%q->size;
        x=q->Q[q->front];
    }
    return x;
}

int main()
{
    struct queue q;
    q.size=10;
    q.front=-1;
    q.rear=-1;
    q.Q=new int[q.size];
   
   return 0;

}

