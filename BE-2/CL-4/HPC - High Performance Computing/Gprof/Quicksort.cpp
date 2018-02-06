#include<iostream>
#include<omp.h>
#include<stdlib.h>
using namespace std;

int partition(int array[],int low,int high){
	int pivot=array[high];//assign last element as a pivot element
	int temp;
	int i=low-1;
	for(int j=low; j<high ;j++){
		if(array[j]<pivot){
			i++;
			temp=array[j];
			array[j]=array[i];
			array[i]=temp;
		}
	}
	temp=array[high];
	array[high]=array[i+1];
	array[i+1]=temp;
	return i+1;
}


void quicksort(int array[],int low,int high){
	if(low<high){
		int q=partition(array,low,high);//call to partition function and return pivot element index 
		quicksort(array,low,q-1);//recursive function call to quicksort function 
		quicksort(array,q+1,high);//recursive function call to quicksort function 
		
	}
}

int main(){
	int no;
	cout<<"Enter the numner of elements";cin>>no;
	int array[no];
	for(int i=0;i<no;i++){
		array[i]=rand()%1000;
	}
	cout<<endl;
	double start=omp_get_wtime();
	quicksort(array,0,no-1);//call to quicksort fuction
	double finish=omp_get_wtime();
	cout<<endl;
	cout<<"Execution time:"<<finish-start<<endl;
	return 0;
}
