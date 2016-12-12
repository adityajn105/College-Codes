#include<stdio.h>
#include<stdlib.h>
#include<sys/resource.h>
#include<unistd.h>
int main()
{	
	int rc,nc;
	int ch;
	while(1)
	{
	system("ps axl");
	printf("current process is is : %d \n Its priority is:  %d",getpid(),getpriority(PRIO_PROCESS,0));
printf("\nEnter new nice value");
scanf("%d",&nc);
rc=setpriority(PRIO_PROCESS,0,nc);
if(0!=rc)
{
perror("could not set priority");
}
sleep(2);
printf("current process is is : %d \n Its priority is:  %d",getpid(),getpriority(PRIO_PROCESS,0));
printf("\n do you want to continue(1 for no)");
scanf("%d",&ch);
if(ch=='1')
exit(0);
}
return 0;
}
