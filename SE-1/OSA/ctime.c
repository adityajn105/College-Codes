#include<stdio.h>
#include<utmp.h> 
#include<time.h>
int main()
{

struct utmp *n;
time_t a;
int i;
setutent();
n=getutent();

while(n!=NULL)
{

if(n->ut_type==7||n->ut_type==9||n->ut_type==6)
{
printf("%10s",n->ut_user);
printf("%10s",n->ut_line);
printf("%10s",n->ut_host);
printf("%10s",n->ut_id);
printf("%10d",n->ut_pid);
printf("%10d",n->ut_type);
printf("%15d",n->ut_session);
a=(time_t)n->ut_tv.tv_sec;
printf("%20s",ctime(&a));


printf("\n");

}
n=getutent();
}

}
