/**
 * The code defines various functions for manipulating arrays, such as appending, inserting, deleting,
 * searching, shifting, sorting, merging, and more.
 * 
 * @param arr1 An array with elements {1, 3, 5, 7, 9, 11, 13, 15, 17, 19}, size 20, and length 10.
 */
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;
struct Array
{ 
    int A[20];
    int size;
    int length;
};
//display function
void display(struct Array arr1)
{
   for(int i=0;i<arr1.length;i++)
   {
printf("%d ",arr1.A[i]);
   }
}

//append function
void append(struct Array *arr2,int x)
{
    if(arr2->length==arr2->size-1)
    {
        cout<<"no space availabe"<<endl;
    }
    else 
    { 
       
       arr2->A[arr2->length]=x;
        arr2->length++;
    }
}
//insert function
void insert(struct Array *arr3,int index,int x)
{
    if(arr3->length==arr3->size-1)
    {
        cout<<"no space available"<<endl;
    }
    else
    {
        for(int i=arr3->length;i>index;i--)
        {
            arr3->A[i]=arr3->A[i-1];
        }
        arr3->A[index]=x;
        arr3->length++;
    }
}
//delete 
int Delete(struct Array *arr4,int index)
{
    int x;
    x=arr4->A[index];
    for(int i=index;i<arr4->length-1;i++)
    {
        arr4->A[i]=arr4->A[i+1];
    }
    arr4->length--;
    return x;
}
//linear search

int Lsearch(struct Array *arr5,int key)
{
    for(int i=0;i<arr5->length;i++)
    {
        if(key==arr5->A[i])
        {
          return 1;
         
        }
    }
  return -1;
}
//binary search
int Binarysearch(struct Array arr6,int key)
{
    int l,h,mid;
    l=0;
    h=arr6.length-1;
    while(l<=h)
    {
        mid=(l+h)/2;
        if(arr6.A[mid]==key)
        {
           return mid;
        }
        else if(arr6.A[mid]<key)
        {
            l=mid+1;
        }
        else 
        {
            h=mid-1;
        }
    }
    return -1;

}
//get function
int get(struct Array arr7,int index)
{
    int x;
    x=arr7.A[index];
    return x;
}
//set function
void set(struct Array *arr8,int index,int key)
{
    arr8->A[index]=key;
}
//max function
int max(struct Array arr9)
{
    int max=arr9.A[0];
    int i=1;
    while(i<arr9.length)
    {
        if(max<arr9.A[i])
        {
            max=arr9.A[i];
            
        }
        i++;
    }
    return max;
}
//rotation  of an array(method 1)
void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void method1(struct Array *arr10)
{
    int i,j;
    i=0;
    j=arr10->length-1;
    while(i<j)
    {
        swap(&arr10->A[i],&arr10->A[j]);
        i++,j--;
    }

}
//method 2
void method2(struct Array *arr11)
{
    int *b=(int *)malloc(sizeof(int)*arr11->length);
    int i=arr11->length-1;
    int j=0;
    while(i>=0)
    {
        b[j]=arr11->A[i];
        i--,j++;
    }
    for(int k=0;k<arr11->length;k++)
    {
        arr11->A[k]=b[k];
    }
}
//left shift
void Lshift(struct Array *arr12)
{
    int x=arr12->A[0];
    for(int i=0;i<arr12->length;i++)
    {
        arr12->A[i]=arr12->A[i+1];
    }
    arr12->A[arr12->length-1]=x;
}
//right shift
void Rshift(struct Array *arr13)
{
    int x;
    x=arr13->A[arr13->length-1];
    int i=arr13->length-1;
    while(i>=0)
    {
        arr13->A[i]=arr13->A[i-1];
        i--;

    }
    arr13->A[0]=x;
}
//array is sorted
bool issorted(struct Array arr)
{
 for(int i=0;i<arr.length-1;i++)
 {
    if(arr.A[i]>arr.A[i+1])
    {
        return false;
    }
   
 }
  return true;
}
//inserting in a sorted array
void sortinsert(struct Array *arr,int x)
{
 int i=arr->length-1;
 while(arr->A[i]>x)
 {
    arr->A[i+1]=arr->A[i];
    i--;
 }
 arr->A[i+1]=x;
 arr->length++;
}
//-ve on left side
void rearrange(struct Array *arr)
{
    int i=0;
    int j=arr->length-1;
    while(i<j)
    {
        while(arr->A[i]<0){i++;}
        while(arr->A[j]>=0){j--;}
        if(i<j)
        {
swap(&arr->A[i],&arr->A[j]);
        }
    }
}
//merging 2 sorted array
struct Array* merge(struct Array *arr1,struct Array *arr2)
{
    struct Array*arr3=(struct Array *)malloc(sizeof(struct Array));
   
    int i=0;
    int j=0;
    int k=0;
    int m=arr1->length;
    int n=arr2->length;
    while(i<m && j<n)
    {
        if(arr1->A[i]<arr2->A[j])
        {
            arr3->A[k++]=arr1->A[i++];

        }
        else 
        {
            arr3->A[k++]=arr2->A[j++];
        }
    }
    for(;i<m;i++)
    {
        arr3->A[k++]=arr1->A[i];
    }
   for(;j<n;j++)
   {
    arr3->A[k++]=arr2->A[j];
   }
    arr3->size=20;
    arr3->length=arr1->length+arr2->length;
   return arr3;


}
int main()
{
      struct Array arr1={{1,3,5,7,9,11,13,15,17,19},20,10};
      struct Array arr2={{0,2,4,6,8,10,12,14,16,18},20,10};
      struct Array *arr3=merge(&arr1,&arr2);
      display(*arr3);

   
return 0;

}
