#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

main()
{
pid_t pid;
pid=fork();
char a[1000];
if(pid<0)
	{printf("fork error");}
if(pid==0)
	{printf("");
	printf("my parent id is %d",getppid());}
if(pid>0)
	{sleep(5);
	wait(a);
	system("ps -axj|more");}
exit(0);
}
