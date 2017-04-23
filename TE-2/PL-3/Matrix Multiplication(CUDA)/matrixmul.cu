#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 16

__global__ void multiply(float *A, float *B, float* C, int rc){
	
	int col=gridDim.x*blockIdx.x + threadIdx.x; 
	int row=gridDim.y*blockIdx.y + threadIdx.y;

	float sum=0;
	for(int i=0;i<rc;i++){
		sum+=A[(row*rc)+i]*B[(rc*i)+col];
		if(row==0 && col==0){
			printf("%f %f %d %d\n",A[(row*rc)+i],B[(rc*i)+col],(row*rc)+i,(rc*i)+col);
		}
	}
	
	C[(row*rc)+col]=sum;
}


int main(){
	float *a,*b,*c;
	float *a_d,*b_d,*c_d;
	int rc=(int)sqrt(SIZE);
	//initialize local mem
	a=(float*)malloc(SIZE*sizeof(float));
	b=(float*)malloc(SIZE*sizeof(float));
	c=(float*)malloc(SIZE*sizeof(float));
	printf("Enter First Matrix(%d x %d) :\n",rc,rc);
	for(int i=0;i<rc;i++){
		for(int j=0;j<rc;j++){
			scanf("%f",&a[i*rc+j]);
		}
		printf("\n");
	}
	printf("Enter Second Matrix(%d x %d) :\n",rc,rc);
	for(int i=0;i<rc;i++){
		for(int j=0;j<rc;j++){
			scanf("%f",&b[i*rc+j]);
		}
		printf("\n");
	}

	//initialize cuda memory
	cudaMalloc(&a_d,SIZE*sizeof(float));	
	cudaMalloc(&b_d,SIZE*sizeof(float));
	cudaMalloc(&c_d,SIZE*sizeof(float));

	cudaMemcpy(a_d,a,SIZE*sizeof(float),cudaMemcpyHostToDevice);
	cudaMemcpy(b_d,b,SIZE*sizeof(float),cudaMemcpyHostToDevice);

	dim3 gridSize(2,2);
	dim3 blockSize(2,2);

	multiply <<<gridSize,blockSize>>> (a_d,b_d,c_d,rc);

	cudaMemcpy(c,c_d,SIZE*sizeof(float),cudaMemcpyDeviceToHost);

	printf("Product Matrix(%d x %d) :\n",rc,rc);
	for(int i=0;i<rc;i++){
		for(int j=0;j<rc;j++){
			printf("%f\t",c[i*rc+j]);
		}
		printf("\n");
	}


	free(a);free(b);free(c);
	cudaFree(a_d);cudaFree(b_d);cudaFree(c_d);
	return 0;
}