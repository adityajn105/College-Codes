#include "queue.h"
#include<iostream>
#include<pthread.h>
using namespace std;

queue q1;
void *function1(void *arg){
	q1.open();
	q1.send("Hello");
	q1.send("world");
	cout<<"Message sent by thread1"<<endl;
}

void *function2(void *arg){
	string msg;
	q1.receive(msg);
	cout<<"Message received by thread2 is"<<msg.c_str()<<endl;
}

void *function3(void *arg){
	string msg;
	q1.receive(msg);
	cout<<"Message recieved byt thread 3 is"<<msg.c_str()<<endl;
}

int main(){
	pthread_t thread1,thread2,thread3;
	pthread_create(&thread1,NULL,&function1,NULL);
	pthread_join(thread1,NULL);
	pthread_create(&thread2,NULL,&function2,NULL);
	pthread_join(thread2,NULL);
	pthread_create(&thread3,NULL,&function3,NULL);
	pthread_join(thread3,NULL);
	q1.close();
	q1.remove();
	return 0;		
}
