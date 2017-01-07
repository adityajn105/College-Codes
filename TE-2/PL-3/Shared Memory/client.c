#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>

int main(){
	key_t key = 5678; 
	size_t shm_size=50;
	void *shm,*s;
	int shmid;
	int a,b;


	if ((shmid = shmget(key, SHMSZ, 0666)) < 0) {
	        perror("Unalbe to get shared memory");
	        exit(1);
	 }

	if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
      		perror("Unable to attach shared memory");
       		exit(1);
   	 }

	printf("Please give two numbers to be multiplied");
	scanf("%d %d",a,b);
	
	s=shm;
	*s++ = (char*)a;
	*s++ = '*';
	*s++ = (char*)b;
	
	

	return 0;
}
