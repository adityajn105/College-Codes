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
{
printf("");
printf("child id is %d",getpid());
}
else
{sleep(2);
system("ps -ajx|more");}
exit(0);
}
