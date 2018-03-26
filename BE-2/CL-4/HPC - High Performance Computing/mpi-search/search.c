#include <mpi.h>
#include <stdio.h>
#include<malloc.h>

int main(int argc, char* argv[]) {
	int rank,size,i;
	double start_time, computation_time, end_time;
	int arr[12];
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	int elem;

	char name[100];
	int maxlen = 100;

	MPI_Get_processor_name(name, &maxlen);

	// printf("Process: %d executing on host: %s\n", rank, name);

	MPI_Barrier(MPI_COMM_WORLD);
	int *sub_rand_nums = malloc(sizeof(int) * 3);
	//start_time = MPI_Wtime();
	if(rank==0){
		int arr[12] = {6,9,1,3,5,2,0,3,12,4,17,11};
		printf("Element to be searched : ");
		scanf("%d",&elem);
	}
	MPI_Scatter( arr,12/size,MPI_INT,sub_rand_nums,
			12/size,MPI_INT,0,MPI_COMM_WORLD);
	MPI_BCAST( &elem,1,MPI_INT,0,MPI_COMM_WORLD);

	printf("\nMy rank is %d, My data is ",rank);
	int found;
	for(i=0;i<12/size;i++){
		printf("\t %d",sub_rand_nums[i]);
		if(sub_rand_nums[i]==elem)
			found=(rank*12/size)+i;
		else
			found=-1;
		printf("Found %d",found);
	}

	//MPI_GATHER(&found,1,MPI_INT,)
	return 0;
}
