#include <sys/shm.h>
#include <stdio.h>

int vedicMultiply(int a, int b);
int main(){
	int shmid;
	key_t key=5678;			//integer key assigned to shared memory
	size_t shm_size= 50;  	//size is the size of the requested shared memory.
	int *pointer;			//integer pointer to initial address of shared memory buffer
	int a,b,pos=1;			

	//get shared memory. IPC_CREATE - means create shared memory, returns id of shared memory
	shmid=shmget(key,shm_size,IPC_CREAT|0666);	//0666- specifies permissions for user,group and others
	if(shmid<0){
		 perror("Unable to create shared Memory");	
		 return -1;
	}

	//attach shared memory to process address space return pointer to initial address
	pointer = shmat(shmid,NULL,0);	//shmid- unique id for this shared memory
									//if shmadd=NULL means system choose suitable address to attach memory 
									//else we can specify
	if(pointer==(int*)-1){	
		perror("unable to attach memory");
		return -1;
	}
	else printf("Memory attached\n");

	//if poiner is int type it is increamented by 4 byte, char by 1 byte
	*pointer = NULL;		//write NULL to initial address
	while(*pointer==NULL){}	//wait till client gives numbers

	while(1){
		if (pos==3) {*pointer--;break;}	//when both nums are recieved
		int sint = *pointer; 	//get integer from current address
		if(*pointer!=NULL){
			if(pos==1)  a=sint;
			else b=sint;
			*pointer++;
		}
		else{
			pos++;	//when a NULL is found
			*pointer++;
		}
	}
	printf("Input Recieved are %d and %d.\n",a,b);
	int ans=vedicMultiply(a,b);
	*pointer=ans;		//write computed ans over previous NULL Value
	printf("Computation Done. Sending Result : %d \n",ans);
	
	return 0;
}


int vedicMultiply(int a,int b){		//logic for vedic multiplication
	int a0= a%10,b0=b%10;
	int a1=a/10,b1=b/10;

	int term1=a1*b1;
	int term2=a1*b0+a0*b1;
	int term3=a0*b0;
	return term1*100+term2*10+term3;
}