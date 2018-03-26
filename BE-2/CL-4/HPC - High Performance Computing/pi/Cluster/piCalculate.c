/***************************************************************
This exercise presents a simple program to determine the value of pi. The algorithm suggested here is chosen for its simplicity. The method evaluates the integral of 4/(1+x*x) between 0 and 1. The method is simple: the integral is approximated by a sum of n intervals; the approximation to the integral in each interval is (1/n)*4/(1+x*x). The master process (rank 0) asks the user for the number of intervals; the master should then broadcast this number to all of the other processes. Each process then adds up every n'th interval (x = rank/n, rank/n+size/n,...). Finally, the sums computed by each process are added together using a reduction.

You may want to use these MPI routines in your solution:
MPI_Bcast MPI_Reduce 
***************************************************************/

#include "mpi.h"
#include <math.h>
#include <stdio.h>

#define MAX_NAME 80   /* length of characters for naming a process */

int main(argc,argv)
int argc;
char *argv[];
{
    int n,
     rank, /* rank variable to identify the process */
      numprocs, /* number of processes */
       i,
       len; /* variable for storing name of processes */
    double PI25DT = 3.141592653589793238462643; /* 25-digit-PI*/
    double mypi, /* value from each process */
     pi, /* value of PI in total*/
      step, /* the step */
       sum, /* sum of area under the curve */
        x,
         startTime, /* starting time */
          endTime; /* ending time */
    
    char name[MAX_NAME];        /* char array for storing the name of each process */

    /*Initialize MPI execution environment */
    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD,&numprocs);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    
    MPI_Get_processor_name(name, &len);
    while (1)
    {
        MPI_Barrier(MPI_COMM_WORLD);
	if (rank == 0) {
	    printf("Number of processing units: %d\n",numprocs);
	    printf("Enter the number of intervals: (0 quits) ");
	    scanf("%d",&n);
	}
	MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);
	if (n == 0) break;
        
        //Broadcast the number of bins to all processes
        /* This broadcasts an integer which is n, from the master to all processes */
        //Calculating for each core
        startTime = MPI_Wtime();
	step   = 1.0 / (double) n;
	sum = 0.0;
	for (i = rank + 1; i <= n; i += numprocs) {
	    x = step * ((double)i - 0.5);
	    sum += 4.0 / (1.0 + x*x);
	}
	mypi = step * sum;
	
	printf("This is my sum: %.16f from rank: %d name: %s\n", mypi, rank, name);
    
        //Now we can reduce alll those sums to one value which is pi
	MPI_Reduce(&mypi, &pi, 1, MPI_DOUBLE, MPI_SUM, 0,
		   MPI_COMM_WORLD);
    
	if (rank == 0){
	    printf("pi is approximately %.16f, Error is %.16f\n", pi, fabs(pi - PI25DT));
	    endTime = MPI_Wtime();
	    printf("Time of calculation PI is: %f\n", endTime-startTime);
	    
	}
    }
    //Terminate MPI execution environment
    MPI_Finalize();
    return 0;
}

