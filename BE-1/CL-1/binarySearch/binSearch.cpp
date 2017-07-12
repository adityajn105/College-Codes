#include<iostream>
using namespace std;

int recursiveBinarySearch(double*,int,double);
int iterativeBinarySearch(double*,int,double);
int main(){
	int N,temp;
	double* array= new double[N];
	double query;
	cout<<"Enter no of elements :";cin>>N;
	cout<<"Enter sorted elements seperated by space - "<<endl;
	for(int i =0;i<N;i++) cin>>array[i];
	while(true){
		cout<<"Enter element you wishes to Search : ";cin>>query;
		int res=iterativeBinarySearch(array,N,query);
		if(res==-1) cout<<"Element not found :("<<endl;
		else cout<<"Element found at position :"<<res+1<<endl;
	}
	return 0;
}
int iterativeBinarySearch(double* array,int N,double query){
	int low=0,high=N-1,res=-1,mid=0;
	while(low<=high){
		mid=(low+high)/2;
		if(array[mid]==query) return mid;
		else if(array[mid]>query) high=mid-1;
		else low=mid+1;
	}
	return res;
}
int recursiveBinarySearch(double* array,int N,double query){
	if( N==0 ) return -1;
	else if(array[N/2]==query) return (N/2);
	else if(array[N/2]<query){
		int res=recursiveBinarySearch(&array[N/2+1],N-N/2-1,query);
		return res==-1?res:res+N/2+1;
	}
	else return recursiveBinarySearch(&array[0],N/2,query);
}