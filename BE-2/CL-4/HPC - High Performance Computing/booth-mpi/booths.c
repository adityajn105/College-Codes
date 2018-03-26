/*Create a computing facility grid using networks for Booth�s multiplication (64-bit) using
sign-extension method. Where bit multiplication, additions and merging of the addition
results for final processing. The computing grid is created using Advanced wireless network
with few computing resources are separated by the router and identified by the NAT. The
network controlling node will be submitted with files having total distributed storage of 1000
numbers as a SAN queued for the execution in sorted manner on the lesser cost due to length
of the multiplier and display the results along with the network tracking report for the
dynamic allocation of multiplier and addition nodes along with the sleeping/ inactive/
un-utilized nodes in the network. */
#include<time.h>
#include<stdlib.h>
#include <stdio.h>
#include <math.h>
#include<mpi.h>

#define MAX 24

int a = 0,b = 0, c = 0, a1 = 0, b1 = 0, com[5] = { 1, 0, 0, 0, 0};
int anum[5] = {0}, anumcp[5] = {0}, bnum[5] = {0};
int acomp[5] = {0}, bcomp[5] = {0}, pro[5] = {0}, res[5] = {0};
int numberArray[MAX];
int numberArraySubset[MAX];
int elements_per_proc;
    int world_size;
    int world_rank;
    char processor_name[MPI_MAX_PROCESSOR_NAME];
    int name_len;

void binary(){
     a1 = fabs(a);
     b1 = fabs(b);
     int r, r2, i, temp;
     for (i = 0; i < 5; i++){
           r = a1 % 2;
           a1 = a1 / 2;
           r2 = b1 % 2;
           b1 = b1 / 2;
           anum[i] = r;
           anumcp[i] = r;
           bnum[i] = r2;
           if(r2 == 0){
                bcomp[i] = 1;
           }
           if(r == 0){
                acomp[i] =1;
           }
     }
   //part for two's complementing
   c = 0;
   for ( i = 0; i < 5; i++){
           res[i] = com[i]+ bcomp[i] + c;
           if(res[i] >= 2){
                c = 1;
           }
           else
                c = 0;
           res[i] = res[i] % 2;
     }
   for (i = 4; i >= 0; i--){
     bcomp[i] = res[i];
   }
   //in case of negative inputs
   if (a < 0){
      c = 0;
     for (i = 4; i >= 0; i--){
           res[i] = 0;
     }
     for ( i = 0; i < 5; i++){
           res[i] = com[i] + acomp[i] + c;
           if (res[i] >= 2){
                c = 1;
           }
           else
                c = 0;
           res[i] = res[i]%2;
     }
     for (i = 4; i >= 0; i--){
           anum[i] = res[i];
           anumcp[i] = res[i];
     }

   }
   if(b < 0){
     for (i = 0; i < 5; i++){
           temp = bnum[i];
           bnum[i] = bcomp[i];
           bcomp[i] = temp;
     }
   }
}
void add(int num[]){
    int i;
    c = 0;
    for ( i = 0; i < 5; i++){
           res[i] = pro[i] + num[i] + c;
           if (res[i] >= 2){
                c = 1;
           }
           else{
                c = 0;
           }
           res[i] = res[i]%2;
     }
     for (i = 4; i >= 0; i--){
         pro[i] = res[i];
         printf("%d",pro[i]);
     }
   printf(":");
   for (i = 4; i >= 0; i--){
           printf("%d", anumcp[i]);
     }
}
void arshift(){//for arithmetic shift right
    int temp = pro[4], temp2 = pro[0], i;
    for (i = 1; i < 5  ; i++){//shift the MSB of product
       pro[i-1] = pro[i];
    }
    pro[4] = temp;
    for (i = 1; i < 5  ; i++){//shift the LSB of product
        anumcp[i-1] = anumcp[i];
    }
    anumcp[4] = temp2;
    printf("\nAR-SHIFT: ");//display together
    for (i = 4; i >= 0; i--){
        printf("%d",pro[i]);
    }
    printf(":");
    for(i = 4; i >= 0; i--){
        printf("%d", anumcp[i]);
    }
}
void readfile(FILE *myFile)
{

	    myFile = fopen("input.txt", "r");

	    //read file into array
	    int i;

	    for (i = 0; i < MAX; i++)
	    {
	        fscanf(myFile, " %d", &numberArray[i]);

	      }

	    for (i = 0; i < MAX; i++)
	    {
	        printf("Number is %d : %d\n\n",i, numberArray[i]);
	    }



}
void boothsMultiply(int llimit, int ulimit)
{
	FILE *output;
	char name[20];
sprintf(name,"%d.txt",world_rank);

	output=fopen(name,"w+");
	int q = 0,i;
	int index=llimit;
	for(index=llimit;index<ulimit;index+=2)
		    	    {
		q=0;
		c = 0; a1 = 0; b1 = 0;
		for(i=0;i<5;i++)
		{
		com[i]=0;
		anum[i] =anumcp[i] = bnum[i] = 0;
		acomp[i] = bcomp[i] = pro[i] = res[i] = 0;
		}
		com[0]=1;

		    	    	a=numberArraySubset[index];
		    	    	b=numberArraySubset[index+1];

		    	        fprintf(output," %d %c %d = %d [",a,'x',b,(a*b));

		    	    	binary();
		    	    	printf("\n\nBinary Equivalents are: ");
		    	    	    printf("\nA = ");
		    	    	    for (i = 4; i >= 0; i--){
		    	    	        printf("%d", anum[i]);
		    	    	    }
		    	    	    printf("\nB = ");
		    	    	    for (i = 4; i >= 0; i--){
		    	    	        printf("%d", bnum[i]);
		    	    	    }
		    	    	    printf("\nB'+ 1 = ");
		    	    	    for (i = 4; i >= 0; i--){
		    	    	        printf("%d", bcomp[i]);
		    	    	    }
		    	    	    printf("\n\n");
		    	    	    for (i = 0;i < 5; i++){
		    	    	           if (anum[i] == q){//just shift for 00 or 11
		    	    	               printf("\n-->");
		    	    	               arshift();
		    	    	               q = anum[i];
		    	    	           }
		    	    	           else if(anum[i] == 1 && q == 0){//subtract and shift for 10
		    	    	              printf("\n-->");
		    	    	              printf("\nSUB B: ");
		    	    	              add(bcomp);//add two's complement to implement subtraction
		    	    	              arshift();
		    	    	              q = anum[i];
		    	    	           }
		    	    	           else{//add ans shift for 01
		    	    	              printf("\n-->");
		    	    	              printf("\nADD B: ");
		    	    	              add(bnum);
		    	    	              arshift();
		    	    	              q = anum[i];
		    	    	           }
		    	    	     }

		    	    	     printf("\nProduct is = ");
		    	    	     for (i = 4; i >= 0; i--){
		    	    	           printf("%d", pro[i]);
		    	    		        fprintf(output,"%d",pro[i]);
		    	    	     }
		    	    	     for (i = 4; i >= 0; i--){
		    	    	           printf("%d", anumcp[i]);

		    	    	           		 fprintf(output,"%d",anumcp[i]);

		    	    	          }
		    	    		 fprintf(output,"]\n");



		    	    }



}

void generateFile(	FILE *fp )
{

    int i, noofr=MAX, j ;

	    fp = fopen ( "input.txt", "w+" ) ;
	if ( fp == NULL )
	    {
	        printf ( "Unable to create file." ) ;

	        exit ( 0 ) ;
	    }


	    for ( i = 0 ; i < noofr ; i++ )
	    {
	        j = rand()%15;
	        fprintf(fp," %d",j);
	        printf ( "%d\n", j ) ;
	    }

	    fclose ( fp ) ;




}
int main(){
 MPI_Init(NULL, NULL);

    // Get the number of processes

    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    // Get the rank of the process

    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    // Get the name of the processor
    MPI_Get_processor_name(processor_name, &name_len);

    clock_t begin = clock();

    /* here, do your time-consuming job */
   FILE *fp=NULL;
if(world_rank==0)
{
   generateFile(fp);
   readfile(fp);

}
elements_per_proc=MAX/world_size;
printf("\nEPP%d",elements_per_proc);
MPI_Scatter(numberArray, elements_per_proc, MPI_INT, numberArraySubset,elements_per_proc, MPI_INT, 0, MPI_COMM_WORLD);
MPI_Barrier(MPI_COMM_WORLD);
   
if(world_rank!=-1)
{


   int sizesubarray=MAX/world_size;
   boothsMultiply(0,sizesubarray);

}
   clock_t end = clock();
     double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
     printf("\n\nTime Spent= %f",time_spent);


 // Finalize the MPI environment.
    MPI_Finalize();
}

