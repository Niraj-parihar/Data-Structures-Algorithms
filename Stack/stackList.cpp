/**
 * The code defines a stack class and demonstrates its usage by pushing elements onto the stack and
 * displaying them.
 */
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

class node 
{ 
    public:
    int data;
    struct node *next;
};
class stack
{ 
    private:
    node* top;
    public:
    stack()
    {
        top==NULL;
    }
    void push(int x)
    { 
        node *t=new node;
        if(t==NULL)
        {
            cout<<"stack is full "<<endl;
        }
        else 
        {
            t->data=x;
            t->next=top;
            top=t;
        }
    }
    int pop()
    {   
        int x;
        if(top==NULL)
        {
            cout<<"stack is empty "<<endl;
        }
        else 
        {
        node *p=top;
        top=top->next;
        x=p->data;
        free(p);
        }
        return x;
    }
void display()
{
    while(top)
    {
        cout<<top->data<<"->";
        top=top->next;
    }
}
int top()
{
    int x;
     x=top->data;
    return x;
}
    
};





int main()
{
stack stk;
stk.push(10);
stk.push(20);
stk.push(40);
stk.push(50);
stk.display();

}