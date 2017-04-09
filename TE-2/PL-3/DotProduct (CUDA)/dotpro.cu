#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#define SIZE 20
using namespace std;

__global__ void compute(int* a,int* b, int* c){

	__shared__ int  temp[SIZE];
	int index=blockIdx.x*SIZE+threadIdx.x;	
	temp[index]=a[index]*b[index];

	__syncthreads();

	for(int i =0;i<SIZE/2;i++){
		c[i]=temp[i]+temp[i+SIZE/2];
	}

}


int main(){
	//declare variables
	int *A,*B,*C;
	int n= SIZE * sizeof(int);
	int *A_d,*B_d,*C_d;

	//initialize local variables
	A=(int*)malloc(n);
	B=(int*)malloc(n);
	C=(int*)malloc(n/2);
	for(int i=0;i<2*SIZE;i++){
		A[i]=rand()%10;
		B[i]=rand()%10;
	}
	for(int i=0;i<10;i++){
		cout<<A[i]<<"  "<<A[10+i]<<"      "<<B[i]<<"  "<<B[i+10]<<endl;
	}

	//initialize GPU memory
	cudaMalloc(&A_d,n);				//cudaMalloc(**ptr,SIZE);
	cudaMalloc(&B_d,n);
	cudaMalloc(&C_d,n/2);
	cudaMemcpy(A_d,A,SIZE*sizeof(int),cudaMemcpyHostToDevice);					//cudaMemcpy( *dst,*source, size, type);
	cudaMemcpy(B_d,B,SIZE*sizeof(int),cudaMemcpyHostToDevice);

	compute<<<1,20>>>(A_d,B_d,C_d);

	cudaMemcpy(C,C_d,SIZE*sizeof(int)/2,cudaMemcpyDeviceToHost);

	for(int i=0;i<10;i++){
			cout<<"     "<<C[i]<<sendl;
	}	

	free(A);free(B);free(C);
//	cudaFree(A_d);cudaFree(B_d);cudaFree(C_d);
	return 0;
}