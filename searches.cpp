//============================================================================
// Name        : search.cpp
// Author      : Ashwini Khedekar
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#define MAX 5
class search
{
	int arr[MAX];
public:
	void init()
	{
		cout<<"\nEnter sorted of array:";
		for(int i=0;i<MAX;i++)
		{
			cin>>arr[i];
		}
	}
	void print()
		{
			cout<<"\nElements of array:";
			for(int i=0;i<MAX;i++)
			{
				cout<<"\t"<<arr[i];
			}
		}
	int linear(int key)
	{
		for(int i=0;i<MAX;i++)
		{
			if(arr[i]==key)
				return (i);
		}
		return -1;
	}
	int binary(int key)
	{
		int mid,high,low;
		high=MAX-1;
		low=0;
		mid=(low+high)/2;
		while(arr[mid]!=key&&low<=high)
		{
			if(arr[mid]<key)
				low=mid+1;
			else
				high=mid-1;
			mid=(high+low)/2;
		}
		if(arr[mid]==key)
		{
				return mid;
		}
		else
			return -1;
	}
	int fibsearch(int key,int mid,int p,int q)
	{

	    if(key==arr[mid-1])
            return mid;
        if(key>arr[mid-1])
        {
            if(p==1)
                return -1;
            mid=mid+q;
            p=p-q;
            q=q-p;
            return(fibsearch(key,mid,p,q));
        }
        else
        {
            if(q==0)
                return -1;
            mid=mid-q;
            int t;
            t=p-q;
            p=q;
            q=t;
            return(fibsearch(key,mid,p,q));
        }
	}
	int fib(int n)
	{
	    if(n==0)
            return 0;
        if(n==1)
            return 1;
        return(fib(n-1)+fib(n-2));
	}

	int sentinel(int key)
	{
		arr[MAX]=key;
		for(int i=0;i<=MAX;i++)
			if(arr[i]==key)
				return i;
		return -1;
	}
};
int main() {
	search s;
	s.init();
	s.print();
	int ch,x,loc;
	do
	{
		cout<<"\n1.Linear Search\n2.Binary search\n3.Fibonacci\n4.Sentinel Search\n5.Quit";
		cin>>ch;
		switch(ch)
		{
		case 1:
			cout<<"Enter element to search :";
		    cin>>x;
			loc=s.linear(x);
			if(loc==-1)
			cout<<"\nElement not found";
			else
	     	cout<<"\nElement found at "<<loc+1<<" location";
			break;
		case 2:
			cout<<"Enter element to search :";
			cin>>x;
			loc=s.binary(x);
				if(loc==-1)
					cout<<"\nElement not found";
				else
					cout<<"\nElement found at "<<loc+1<<" location";
			break;
		case 3:
		    int m,a,b,k;
			cout<<"Enter element to search :";
			cin>>x;
			for(k=1;s.fib(k)<=MAX;k++);
			a=s.fib(k-2);
			b=s.fib(k-3);
			m=MAX-a+1;
			loc=s.fibsearch(x,m,a,b);
			if(loc==-1)
				cout<<"\nElement not found";
		    else
				cout<<"\nElement found at "<<loc<<" location";
			break;
		case 4:
			cout<<"Enter element to search :";
			cin>>x;
			loc=s.sentinel(x);
			if(loc==MAX)
				cout<<"\nElement not found";
			else
				cout<<"\nElement found at "<<loc+1<<" location";
			break;
		default:
			cout<<"\nInvalid choice...";
		}
	}while(ch!=5);

	return 0;
}

