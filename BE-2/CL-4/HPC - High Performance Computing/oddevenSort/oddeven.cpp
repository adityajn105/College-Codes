#include<omp.h>
#include<iostream>
using namespace std;
int n,a[100];

void display()
{
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<"\t";
	}
}

void oem(int lo,int hi,int r)
{
	//cout<<"\nin oem: "<<lo<<"\t"<<hi<<"\t"<<r<<"\n";
	int m=r*2;
	if(m<hi)
	{
		#pragma omp parallel sections
		{
			#pragma omp section
			{
				oem(lo,hi,m);
			}
			#pragma omp section
			{
				oem(lo+r,hi,m);
			}
		}
		for(int i=lo+r;i+r<lo+hi;i=i+m)
		{
			if(a[i]>a[i+r])
			{
				int t=a[i];
				a[i]=a[i+r];
				a[i+r]=t;
			}
		}
	}
	else
	{
		if(a[lo]>a[lo+r])
		{
			int t=a[lo];
			a[lo]=a[lo+r];
			a[lo+r]=t;
		}

	}
}


void oems(int lo,int n)
{
	//cout<<"\nin oems: "<<lo<<"\t"<<n<<"\n";
	if(n>1)
	{
		int m=n/2;
		oems(lo,m);
		oems(lo+m,m);
		oem(lo,n,1);
	}
}


int main()
{
	
	cout<<"\nEnter no of elements to be sorted:";
	cin>>n;
	cout<<"\nEnter elements:";
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	oems(0,n);
	cout<<"\nSorted elements are:\t";
	display();
	cout<<"\n\n";
}
