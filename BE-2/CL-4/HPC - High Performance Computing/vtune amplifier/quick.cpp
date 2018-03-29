//quick

#include<iostream>
#include<stdlib.h>
using namespace std;
#include<omp.h>
int k=0;
class sort
{
int *a;
long int n;
public:
void getdata();
void quicksort();
void quicksort(int low,int high);
int partition(int low,int high);
void putdata();
};

void sort :: getdata()
{
srand(time(NULL));
n=1000000;
a=new int[1000000];
for(int i=0;i<1000000;i++)
	{
	a[i]=(rand() % 1000000)+1;
	}
}
void sort::quicksort()
{
quicksort(0,n-1);
}
void sort::quicksort(int low,int high)
{
if(low<high)
{
int partn;
partn=partition(low,high);
	#pragma omp parallel sections
	{	
	#pragma omp section
	{
	quicksort(low,partn-1);
	}
	#pragma omp section
	{
	quicksort(partn+1,high);
	}
	}
}
}

int sort::partition(int low,int high)
{
	int pvt;
	pvt=a[high];
	int i,j;
	i=low-1;
	for(j=low;j<high;j++)
	{
	if(a[j]<=pvt)
		{
		int tem=0;
		tem=a[j];
		a[j]=a[i+1];
		a[i+1]=tem;
		i=i+1;
		}
	}
int te;
te=a[high];
a[high]=a[i+1];
a[i+1]=te;
return i+1;
}

void sort::putdata()
{
for(int i=0;i<n;i++)
cout<<"\t"<<a[i];
}

int main()
{
sort s1;
s1.getdata();
double start=omp_get_wtime();
s1.quicksort();
double end=omp_get_wtime();
s1.putdata();
cout<<"time: "<<end-start;
return 0;
}



