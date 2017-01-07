#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>

int main(){
	size_t shm_size=50;
	key_t key=5678;
	int *pointer;
	int shmid;
	int a,b;


	if ((shmid = shmget(key, shm_size, 0666)) < 0) {		//getting shared memory
	        perror("Unalbe to get shared memory");
	        exit(1);
	 }

	 //attaching shared memory and getting pointer
	if ((pointer = shmat(shmid, NULL, 0)) == (int *) -1) {
      		perror("Unable to attach shared memory");
       		exit(1);
   	 }

	printf("Please give two numbers to be multiplied  :");
	scanf("%d",&a);					//getting first number
	scanf("%d",&b);					//getting second number
	*pointer++ = a;					//writing first number to memory
	*pointer++= NULL;				//write NULL to separate numbers
	*pointer++= b;					//writing second number to memory
	*pointer = NULL;				//writing Null to memory
	while(*pointer==NULL){}			//waiting for server to write computed result on memory
	
	int sint = *pointer; 			//getting result
	printf("Vedic Multiplication is :  %d \n",sint );	

	return 0;
}
