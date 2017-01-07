#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
int main(){
	int shmid;
	key_t key=5678;
	size_t shm_size= 50;
	void *shm,*s;
	int a,b,pos=0;

	shmid=shmget(key,shm_size,IPC_CREAT|0666);
	if(shmid<0){
		 perror("Unable to create shared Memory");
		 return -1;
	}

	shm = shmat(shmid,NULL,0);
	if(shm==(void*)-1){
		perror("unable to attach memory");
		return -1;
	}
	else printf("Memory attached");

	s=shm;
	char k=*(char*)s;
	printf("%s",&k);
	while(s != NULL){
		int s2 = *(int*)s; 
		char s3 = *(char*)s;
		if(s3!='*'){
			if(pos==0) a= s2;
			else b=s2;
			s++;
		}
		else{
			pos=1;
			s++;
		}
	}
	

	return 0;
}
