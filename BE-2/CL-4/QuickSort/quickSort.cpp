#include<iostream>
#include <omp.h>
#include <stdlib.h> 
using namespace std;

class QuickSorter{
	private: double* arr;
	private: long N;
	
	public: bool verify(){
		for(long i=0;i<this->N-1;i++){
			if(arr[i]>arr[i+1]) return false;
		}
		return true;			
	}	
	
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
			long partn=partition(low,high);			
			#pragma omp task
			{quickSortPar(low,partn-1);}
			#pragma omp task
			{quickSortPar(partn+1,high);}
		}
	}
	
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
		for(long i=low;i<high;i++){
			if(this->arr[i]<pivot){
				double temp=this->arr[i];
				this->arr[i]=this->arr[last];
				this->arr[last]=temp;
				last++;
			}
		}
		double temp=this->arr[last];
		this->arr[last]=pivot;
		this->arr[high]=temp;
		return last;
	}
	
	public: double* getArray(){
		return arr;
	}
	
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
	for(long i=0;i<N;i++) { 
		arrs[i]=rand()%10000000;
		arrp[i]=arrs[i];	
	}	
	QuickSorter quicks(arrp,N);
	double start = omp_get_wtime(); 
	quicks.sortSequential();
	double end = omp_get_wtime();
	if(quicks.verify()) cout<<"Sequential Sort Done"<<endl;	
	cout<<"Time taken for Sequential Execution :"<<end-start<<endl;
	QuickSorter quickp(arrs,N);	
	start = omp_get_wtime();
	#pragma omp parallel num_threads(28)
	{
		#pragma omp single nowait
		{		
			quickp.sortParallel();
		}
	}
	end = omp_get_wtime();
	if(quickp.verify()) cout<<"Parallel Sort Done"<<endl;	
	cout<<"Time taken for Parallel Execution :"<<end-start<<endl;
	/*double* ptr = quick.getArray();
	cout<<"Sorted Array is : ";
	for(int i=0;i<N;i++) 
		cout<<ptr[i]<<" "; 
	cout<<endl;*/
}
