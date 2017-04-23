#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define BLOCKS 3
#define THREADS 10
#define SIZE 30


__global__ void compute(int* a,int* b, int* c){
	__shared__ int temp[SIZE];
	int x = blockIdx.x*blockDim.x + threadIdx.x;
	temp[x] = a[x] * b[x];
	c[threadIdx.x]=0;
	__syncthreads();
	atomicAdd(&c[threadIdx.x],temp[x]);
}

int main(){
	
	int i;
	//declare local variables
	int *a,*b,*c;
	//declare device variables
	int *a_d,*b_d,*c_d;
	clock_t stime,ftime;

	//initialize local variables
	a = (int*) malloc(SIZE*sizeof(int));
	b = (int*) malloc(SIZE*sizeof(int));
	c = (int*) malloc(THREADS*sizeof(int));
	for(i=0;i<SIZE;i++){
		a[i]=rand()%10;
		b[i]=rand()%10;
	}
	//print inputs arrays
	printf("\tA\t\t\tB\t\n");
	for(i=0;i<THREADS;i++){
		printf("%di + %dj + %dk \t\t\t%di + %dj +%dk\n",a[i],a[i+10],a[i+20],b[i],b[i+10],b[i+20]);
	}

	//initialize device variables
	cudaMalloc(&a_d,SIZE*sizeof(int));
	cudaMalloc(&b_d,SIZE*sizeof(int));
	cudaMalloc(&c_d,THREADS*sizeof(int));
	cudaMemcpy(a_d,a,SIZE*sizeof(int),cudaMemcpyHostToDevice);
	cudaMemcpy(b_d,b,SIZE*sizeof(int),cudaMemcpyHostToDevice);
	
	//start kernel
	stime=clock();
	compute<<<BLOCKS,THREADS>>>(a_d,b_d,c_d);
	ftime=clock();
	//get results
	cudaMemcpy(c,c_d,THREADS*sizeof(int),cudaMemcpyDeviceToHost);

	printf("\t\tC\n");
	for(i=0;i<THREADS;i++){
		printf("\t\t%d\n",c[i]);
	}
	printf("Execution Time %e :",((double)ftime-stime));
	return 0;
}