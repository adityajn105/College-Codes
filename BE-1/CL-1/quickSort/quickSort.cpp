#include<iostream>
#include <omp.h>
using namespace std;

class QuickSorter{
	private: double* arr;
	private: int N;
	
	public: QuickSorter(double* p,int n){
		this->arr=new double[n];
		this->N=n;
		for(int i=0;i<n;i++){
			this->arr[i]=p[i];
		}
	}
	
	public: void sort(){
		quickSort(0,N-1);
	}
	
	private: void quickSort(int low,int high){
		if(low<high){
			int partn=partition(low,high);
			quickSort(low,partn-1);
			quickSort(partn+1,high);
		}
	}
	
	private: int partition(int low,int high){
		double pivot=this->arr[high];
		int last=low;
		for(int i=low;i<high;i++){
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
		for(int i=0;i<N;i++) cout<<this->arr[i]<<" "; 
		cout<<endl;
	}
};

int main(){
	int N;
	cout<<"Enter number of elements :";cin>>N;
	double* arr=new double[N];
	cout<<"Enter elements sperated by space :";
	for(int i=0;i<N;i++) cin>>arr[i];
	QuickSorter* quick=new QuickSorter(arr,N);
	quick->sort();
	double* ptr = quick->getArray();
	cout<<"Sorted Array is : ";
	for(int i=0;i<N;i++) 
		cout<<ptr[i]<<" "; 
	cout<<endl;
}