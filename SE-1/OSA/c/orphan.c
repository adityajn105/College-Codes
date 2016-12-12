#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

main()
{
pid_t pid;
pid=fork();
if(pid<0)
	{printf("fork error");}
else if(pid==0)
	{printf("Original parent id is %d\n",getppid());
	sleep(5);
	printf("New parent id is %d\n",getppid());}
else
{
sleep(2);
printf("");
}
exit(0);	
}



