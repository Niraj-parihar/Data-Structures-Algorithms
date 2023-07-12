/**
 * This program implements a stack data structure using an array in C++.
 * 
 * @param stk This is a structure variable of type "stack" which represents the stack data structure.
 * It has the following attributes:
 * @param x The variable `x` is used to store the value that is being pushed or popped from the stack.
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
//stack implementation using array
struct stack
{
    int size;
    int top;
    int *S;
};
void push(struct stack *stk,int x)
{
   if(stk->top==stk->size-1)
   {
    cout<<"stack overflow"<<endl;
   }
   else 
   {
    stk->top++;
    stk->S[stk->top]=x;
   }
}
int pop(struct stack *stk)

{
    int x;
    if(stk->top==-1)
    {
        cout<<"stack is empty "<<endl;
    }
    else 
    {
        x=stk->S[stk->top];
        stk->top--;
    }
    return x;
}
int stacktop(struct stack stk)
{
    int x;
    x=stk.S[stk.top];
    return x;
}
bool isempty(struct stack stk)
{
    if(stk.top==-1)
    {
       return true;
    
    }
    return false;
}
bool isfull(struct stack stk)
{
    if(stk.top==stk.size-1)
    {
       return true;
  
    }
    return false;
}
int peek(struct stack stk,int index)
{ 
    int x;
    if(stk.top-index+1<0)
    { 
        cout<<"index is no valid "<<endl;
    }
    else 
    {
        x=stk.S[stk.top-index+1];
    }
    return x;
}


int main()
{
    struct stack stk;
   stk.size=10;
    stk.top=-1;
    stk.S=new int[stk.size];
  for(int i=0;i<stk.size;i++)
  {
    push(&stk,i);
  }
 cout<<peek(stk,4);
  


}