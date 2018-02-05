#include<iostream>
#include <omp.h>
#include <stdlib.h> 
using namespace std;

/* 
	This is a concurrent QuickSort program which takes pivot as last element.
*/
class QuickSorter{
	private: double* arr;
	private: long N;
	
	// Helper function to verify sorted data
	public: bool verify(){
		for(long i=0;i<this->N-1;i++){
			//return false if not sorted
			if(arr[i]>arr[i+1]) return false;
		}
		return true;			
	}	
	
	//Constructor accepting data
	public: QuickSorter(double* p,long n){
		this->arr=new double[n];
		this->N=n;
		for(long i=0;i<n;i++){
			this->arr[i]=p[i];
		}
	}
	
	public: void sortParallel(){
		quickSortPar(0,N-1);
	}

	public: void sortSequential(){
		quickSortSeq(0,N-1);
	}
	
	private: void quickSortPar(long low,long high){
		if(low<high){
			//get partition 
			long partn=partition(low,high);			
			
			//When for and sections are too cumbersome, the task construct can be used. 
			//This is only supported in OpenMP 3.0 and later.
			#pragma omp task
			{
				quickSortPar(low,partn-1);
			}
			#pragma omp task
			{
				quickSortPar(partn+1,high);
			}
		}
	}
	
	//sequential quick Sort
	private: void quickSortSeq(long low,long high){
		if(low<high){
			long partn=partition(low,high);
			quickSortSeq(low,partn-1);
			quickSortSeq(partn+1,high);
		}
	}

	private: long partition(long low,long high){
		double pivot=this->arr[high];
		long last=low;

		//putting element smaller than pivot in front
		for(long i=low;i<high;i++){
			if(this->arr[i]<pivot){
				double temp=this->arr[i];
				this->arr[i]=this->arr[last];
				this->arr[last]=temp;
				last++;
			}
		}
		//replacing element after last replaced element with pivot
		double temp=this->arr[last];
		this->arr[last]=pivot;
		this->arr[high]=temp;
		return last;
	}
	
	// function returns pointer to array
	public: double* getArray(){
		return arr;
	}
	
	// function to print array
	public: void printArray(){
		for(long i=0;i<N;i++) cout<<this->arr[i]<<" "; 
		cout<<endl;
	}
};

int main(){
	long N;
	cout<<"Enter number of elements :";cin>>N;
	double* arrs=new double[N];
	double* arrp=new double[N];

	//creating random numbers
	for(long i=0;i<N;i++) { 
		arrs[i]=rand()%10000000;
		arrp[i]=arrs[i];	
	}

	// creating QuickSorter object to perform Sorting Sequentially 	
	QuickSorter quicks(arrp,N);
	
	double start = omp_get_wtime();
	// actual sorting is being done 
	quicks.sortSequential();	
	double end = omp_get_wtime();
	
	if(quicks.verify()) cout<<"Sequential Sort Done"<<endl;	//verifying sorted data	
	cout<<"Time taken for Sequential Execution :"<<end-start<<endl;
	
	//creating QuickSorter object to perform concurrent Sorting
	QuickSorter quickp(arrs,N);	

	start = omp_get_wtime(); 

	// allow upto 28 threads
	#pragma omp parallel num_threads(28)
	{
		//The omp single directive identifies a section of code that must be run by a single available thread.
		#pragma omp single nowait
		{		
			quickp.sortParallel();
		}
	}
	end = omp_get_wtime();
	
	//verifying sorted data
	if(quickp.verify()) cout<<"Parallel Sort Done"<<endl;	
	cout<<"Time taken for Parallel Execution :"<<end-start<<endl;
	
	// For printing Array !!Warning!! Do not print for large datasets 
	/*
		double* ptr = quick.getArray();
		cout<<"Sorted Array is : ";
		for(int i=0;i<N;i++) 
			cout<<ptr[i]<<" "; 
		cout<<endl;
	*/
}
