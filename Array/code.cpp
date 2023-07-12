/**
 * The code demonstrates static and dynamic array allocation in C++, as well as increasing the size of
 * an array in the heap and returning an array from a function.
 * 
 * @param n The parameter `n` is an integer that represents the size of the array to be created.
 * 
 * @return In the given code, the function `fun` returns a pointer to an integer array.
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int * fun(int n)
{
    int *p=new int[n];
    return  p;
}

//inside main function
int main()
{
  //static array allocation
  int A[10]={2,4,6,8,10};
  for(int i=0;i<10;i++)
  {
    cout<<A[i]<<" ";

  }
  cout<<endl;

  //dynamic array allocation
  int *p=(int *)malloc(sizeof(int)*5);
  p[0]=1;
  p[1]=2;
  p[2]=4;
  p[3]=10;
  p[4]=20;
  free(p);
  
  //how to increase the size of an array only in heap
 
  int *q=new int[6];
  for(int j=0;j<5;j++)
  {
    q[j]=p[j];
  }
  delete []p;
  q=p;
  q=NULL;
  for(int k=0;k<7;k++)
  {
    cout<<q[k]<<" ";

  }
  //returning an array 
int *z=fun(5);
 return 0;
}
