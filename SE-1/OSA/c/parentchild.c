#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

pid_t num_pid;
main()
{
num_pid=fork();
if(num_pid==0)
	{printf("this si  a child process id %d\n",getpid());}
if(num_pid>0)
	{printf("this is parent id %d\n",getpid());}
exit(1);
}

