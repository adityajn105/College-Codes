#include<iostream>
#include<omp.h>
#include<stdlib.h>
using namespace std;


int partition(int array[],int low,int high)//partition function
{
int pivot=array[high];//assign last element as a pivot element
int temp;
int i=low-1;
for(int j=low; j<high ;j++)
	{

		if(array[j]<pivot)//if array[i] is less than pivot element
		{
			i++;
		//swap array[j] with array[i]
			temp=array[j];
			array[j]=array[i];
			array[i]=temp;
		}
	}
	//swap array[i+1] with array[high]=pivot
	temp=array[high];
	array[high]=array[i+1];
	array[i+1]=temp;
   //return index of pivot element
	return i+1;


}//partition function


void quicksort(int array[],int low,int high)//quicksort function
{

	if(low<high)
	{
		int q=partition(array,low,high);//call to partition function and return pivot element index 
		quicksort(array,low,q-1);//recursive function call to quicksort function 
		quicksort(array,q+1,high);//recursive function call to quicksort function 
		
	}

}//quicksort

int main()
{
	int n,i;
	cout<<"Enter the numner of elements";
	cin>>n;
	int array[n];
	for(i=0;i<n;i++)
	{

		array[i]=rand()%1000;
	}
	cout<<endl;
	double start=omp_get_wtime();
	quicksort(array,0,n-1);//call to quicksort fuction
	double finish=omp_get_wtime();

	cout<<endl;
	cout<<"Execution time:"<<finish-start<<endl;

return 0;
}
