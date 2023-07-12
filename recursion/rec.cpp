/**
 * The code includes functions to calculate the value of e raised to the power of x using Taylor series
 * and Horner's rule, as well as a function to calculate the nth Fibonacci number.
 * 
 * @param x The variable "x" is used as the base value in the Taylor series calculations. It represents
 * the value for which the series is being evaluated.
 * @param n The parameter `n` is used in the functions `e` and `e2` to determine the number of terms in
 * the Taylor series. In the `fib` function, `n` is used to determine the nth Fibonacci number to be
 * calculated.
 * 
 * @return The program is returning the 7th Fibonacci number.
 */
#include <bits/stdc++.h>
using namespace std;

//taylor series
int e(int x,int n)
{
  static int p=1,f=1;
  int r;
  if(n==0)
  {
    return 1;
  }
  else 
  {
    r=e(x,n-1);
    p=p*x;
    f=f*n;
    return r+p/f;
  }
}

//taylor series using horner rules
int e2(int x,int n)
{
    static int s=1;
    if(n==0)
    {
        return 1;
    }
    s=1+(x/n)*s;
    return e2(x,n-1);
}

//fibonaaci
int fib(int n)
{
    if(n<=1)
    {
    return n;
    }
    else 
    {
        return fib(n-2)+fib(n-1);
    }
}
int main()
{
    printf("%d",fib(7));
    return 0;
}