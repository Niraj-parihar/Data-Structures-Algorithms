/**
 * The code creates a max heap, performs a deletion operation, and then displays the resulting heap.
 * 
 * @param A An array of integers representing the heap. The first element (A[0]) is not used, and the
 * heap starts from index 1.
 * @param n The variable `n` represents the number of elements in the array `A`. In this case, `n` is
 * equal to 8.
 */
#include <stdio.h>
#include <iostream>
#include <stdio.h>
using namespace std;
//max heap
void Minsert(int A[],int n)
{ 
    int i=n;
    int temp=A[n];
    while(i>1 && temp>A[i/2])
    {
        A[i]=A[i/2];
        i=i/2;
    }
    A[i]=temp;
}
//min heap
void Mininsert(int A[],int n)
{ 
    int i=n;
    int temp=A[n];
    while(i>1 && temp<A[i/2])
    {
        A[i]=A[i/2];
        i=i/2;
    }
    A[i]=temp;
}
void display(int A[])
{
    for(int i=1;i<8;i++)
    {
        cout<<A[i]<<endl;
    }
}
//deletion in heap
void swap(int *A,int *B)
{
    int temp;
    temp=*A;
    *A=*B;
    *B=temp;
}
void deletion(int A[],int n)
{
    int i,j,x;
    x=A[1];
    A[1]=A[n];
    i=1;
    j=2*i;
    while(j<n-1)
    {
        if(A[j]<A[j+1])
        {
            j=j+1;
        }
        if(A[j]>A[i])
        {
            swap(&A[i],&A[j]);
            i=j;
            j=j*2;
        }
        else 
        {
            break;
        }
        A[n]=x;
    }

}

void create()
{
    int A[]={0,10,20,30,25,5,40,35};
int n=8;
for(int i=2;i<=7;i++)
{
    Minsert(A,i);
}
deletion(A,8);
 display(A);
}



int main()
{
create();

return 0;
}