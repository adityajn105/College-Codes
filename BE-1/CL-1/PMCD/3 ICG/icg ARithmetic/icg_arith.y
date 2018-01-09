%{
#include<math.h>
#include<stdio.h>
#include<string.h>
extern int yylex();
extern int yyerror( char * e);

void displayquad();
char addquad(char,char,char,char);

int flag=0;
char temp='A';
int i=0;

struct quad{
char op;
char arg1;
char arg2;
char res;
}q[10];

%}

%union{ char a;}
%type<a> exp
%token END
%token<a> ID
%left '+','-'
%left '*','/'

%%

s : exp '=' exp END {addquad('=',(char)$3,'_',(char)$1);displayquad();}
  ;
exp : exp '+' exp {$$=addquad('+',(char)$1,(char)$3,temp);}
    |exp '*' exp {$$=addquad('*',(char)$1,(char)$3,temp);}
    |exp '-' exp {$$=addquad('-',(char)$1,(char)$3,temp);}
    |exp '/' exp {$$=addquad('/',(char)$1,(char)$3,temp);}
    |ID { $$=(char)$1;}
    |'('exp')' {$$=(char)$2;}
     ;

%%
char addquad(char a,char b,char c,char d)
{
	q[i].op=a;
	q[i].arg1=b;
	q[i].arg2=c;
	q[i].res=d;
	i++;
	return temp++	;
}
void displayquad()
{
int j=0;
printf("\top");
printf("\targ1");
printf("\targ2");
printf("\tresult");
printf("\n");
while(j<=i)
{
printf("\t%c",q[j].op);
printf("\t%c",q[j].arg1);
printf("\t%c",q[j].arg2);
printf("\t%c",q[j].res);
printf("\n");
j++;
}
}
int main()
{
yyparse();
return 0;
}

extern int yyerror(char *e)
{
	printf("Error\n",e);
	flag=1;
}
