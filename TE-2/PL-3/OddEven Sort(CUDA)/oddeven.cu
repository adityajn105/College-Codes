#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
__global__ void sort(int* A){
	
	bool even=true;
	__shared__ bool swappedOdd;
	__shared__ bool swappedEven;
	__syncthreads();

	swappedEven=true;
	swappedOdd=true;
	do{
		if(even){
			swappedEven=false;
			__syncthreads();
			if(threadIdx.x<blockDim.x/2){
				if(A[threadIdx.x*2]>A[threadIdx.x*2+1]){
					int temp=A[threadIdx.x*2];
					A[threadIdx.x*2]=A[threadIdx.x*2+1];
					A[threadIdx.x*2+1]=temp;
					swappedEven=true;	
				}	
			}
		}
		else{
			swappedOdd=false;
			__syncthreads();
			if(threadIdx.x<blockDim.x/2){
				if(A[threadIdx.x*2+1]>A[threadIdx.x*2+2]){
					int temp=A[threadIdx.x*2+2];
					A[threadIdx.x*2+2]=A[threadIdx.x*2+1];
					A[threadIdx.x*2+1]=temp;
					swappedOdd=true;	
				}	
			}
		}
		__syncthreads();
		even=!even;
		__syncthreads();
	}
	while(swappedEven || swappedOdd);
}

int main(){
	int *A,*B,*A_d;

	//initialize local mem
	A=(int*)malloc(SIZE*sizeof(int));
	B=(int*)malloc(SIZE*sizeof(int));
	printf("Enter unsorted items :");
	for(int i=0;i<SIZE;i++){
		scanf("%d",&A[i]);
	}

	//initialize device mem
	cudaMalloc(&A_d,SIZE*sizeof(int));
	cudaMemcpy(A_d,A,SIZE*sizeof(int),cudaMemcpyHostToDevice);

	sort <<< 1,SIZE >>>(A_d);

	cudaMemcpy(B,A_d,SIZE*sizeof(int),cudaMemcpyDeviceToHost);
	
	printf("\nSorted Array is :");
	for(int i=0;i<SIZE;i++){
		printf("%d   ",B[i]);
	}

}