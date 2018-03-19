#include <mpi.h>
#include <stdio.h>
#include <math.h>

#define N 1E8
#define d 1E-8
#define d2 1E-16

int main(int argc, char *argv[])
{
	
	int rank, size, i;

	double pi = 0.0, result = 0.0, sum = 0.0, begin = 0.0, end = 0.0, x2;

	double start_time, end_time, computation_time;

	// Initialize MPI
	MPI_Init(&argc, &argv);

	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	char name[100];
	int maxlen = 100;

	MPI_Get_processor_name(name, &maxlen);

	printf("Process: %d executing on host: %s\n", rank, name);

	MPI_Barrier(MPI_COMM_WORLD);

	start_time = MPI_Wtime();

	for(i = rank; i < N; i += size) {
		x2 = d2 * i * i;
		result += 1.0 / (1.0 + x2);
	}

	MPI_Reduce(&result, &sum, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

	end_time = MPI_Wtime();

	if(rank == 0) { // Print results in process 0
		pi = 4 * d * sum;
		printf("Pi Value = %lf\n", pi);
		printf("Time taken = %lf\n", (end_time - start_time));
	}

	MPI_Finalize();

	return 0;
}