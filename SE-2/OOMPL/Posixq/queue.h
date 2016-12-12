#define QUEUE_NAME "/myqueue"
#define MAX_SIZE 100
#include<iostream>
#include<mqueue.h>
#include<string.h>
#include<sys/stat.h>
using namespace std;

class queue{
	mqd_t mq;
	struct mq_attr attr;
public:
	queue();
	void open();
	void send(string msg);
	void receive(string &msg);
	void close();
	void remove();
};

queue::queue(){
	attr.mq_flags=0;
	attr.mq_maxmsg=10;
	attr.mq_msgsize=MAX_SIZE;
	attr.mq_curmsgs=0;
}

void queue::open(){
	mq=mq_open(QUEUE_NAME,O_RDWR|O_CREAT|O_EXCL,0644,&attr);
}

void queue::send(string msg){
	mq_send(mq,msg.c_str(),msg.size(),0);
}

void queue::receive(string &msg){
	ssize_t bytes_read;
	char qbuffer[attr.mq_msgsize];
	memset(qbuffer,0,MAX_SIZE);
	bytes_read=mq_receive(mq,qbuffer,attr.mq_msgsize,0);
	string XMessage(qbuffer,attr.mq_msgsize);
	msg=XMessage;
}

void queue::close(){
	mq_close(mq);
}

void queue::remove(){
	mq_unlink(QUEUE_NAME);
}
