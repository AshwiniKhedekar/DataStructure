
None selected

Skip to content
Using Gmail with screen readers
from:(surabhign1999@gmail.com) to:(ashwinikhedekar30@gmail.com) subject:fib

#include <iostream>
using namespace std;
void linear()
{ int key,a[10],i,flag;
    cout<<"linear search"<<endl;
            cout<<"enter element in array";
            for ( i=0;i<=9;i++)
            {

                cin>>a[i];

            }
            cout<<"enter key element which you want to search";
            cin>>key;

    for(i=0;i<=9;i++)
    {
        if(a[i]==key)
        {
            flag =1;
        break;
        }
        else
        {
            flag =0;
    }}
    if(flag==1)
    {
        cout<<"key is present";
    }
        else
        {
        cout<<"key is not present";
        }
}
void sentinel()
{
    cout<<"Sentinel search";
    int b[10],n,j=0,in,i,key;
    cout<<"enter no of elements";
    cin>>n;
    cout<<"enter array elements";
            for(i=0;i<(n-1);i++)
            {

                cin>>b[i];
            }
    cout<<"enter key elements to search";
    cin>>key;
    b[n-1]=key;
    for(i=0;i<n;i++)
        cout<<b[i]<<endl;
    for(j=0;j<n;j++)
    {
    if(b[j]==key)
    {
        in=j;
        break;
        j++;

    }
        }
    if(in!=(n-1))
        cout<<"key is  present"<<endl;
        else
        cout<<"key is not  present"<<endl;
    
    
}
void binary()
{
  int count,num,first,last,a[30],mid;

  cout<<"enter no of elements";
  cin>>count;
  int i;
  cout<<"enter array elements";
  for(i=0;i<count;i++)
  {
    cin>>a[i];
  }
  first=0;
  last=count-1;
  mid=(first+last)/2;
  cout<<"enter the number you want to find";
  cin>>num;
  while(first<=last)
  {
    if(a[mid]<num)
    {
      first=mid+1;
    }
    else if(a[mid]==num)
    {
      cout<<"no is found"<<num;
            break;
    }
    else
    {
      last=mid-1;
    }
    mid=(first+last)/2;

  }
  if(first>last)
  {

    cout<<"no is not found"<<num;
  }
}
int min(int x,int y)
{
    return (x<y)?x:y;
}
int fib()
{
    int n=5,a[5],fibm1,fibm2,fib,x;
    cout<<"enter array elements";
    for(int i=0;i<n;i++)
    {
    cin>>a[i];
    }
     fibm2 = 0;   // (m-2)'th Fibonacci No. 
     fibm1 = 1;   // (m-1)'th Fibonacci No. 
     fib = fibm2 + fibm1;  // m'th Fibonacci 
    while (fib < n) 
    { 
        fibm2 = fibm1; 
        fibm1 = fib; 
        fib  = fibm2 + fibm1; 
    }  
    cout<<"enter no you want to search";
    cin>>x;
     int offset = -1; 
     while(fib>1)
     {
         int i=min(offset+fibm2,n-1);
         
         if(a[i]<x)
         {
             fib=fibm1;
             fibm1=fibm2;
             fibm2=fib-fibm1;
             offset=i;
         }
         else if(a[i]>x)
         {
             fib=fibm2;
             fibm1=fibm1-fibm2;
             fibm2=fib-fibm1;
         }
         else
         return i;
         
     }
     
     if(fibm1 && a[offset+1]==x)
     return offset+1; 
     else
     return 0;
}
int main()
{
    int ch;
    do
    {
    cout<<"enter choice:\n1.linear search\n2.sentinel search\n3.binary search\n4.fibonacci search\n5.exit";
    cin>>ch;
    switch(ch)
    {   case 1:
        linear();
        break;
       case 2:
        sentinel();
        break;
        case 3:
        binary();
        break;
        case 4:
        {
        int y=fib();
        if(y==0)
        {
            cout<<"element not found";
        }
            else
            {
            cout<<"element found at location"<<y;
        }
        break;
        }
        default:
        cout<<"wrong choice";
    }
    }
    while(ch!=5);
    {
        cout<<"done";
    }
  return 0;
}
