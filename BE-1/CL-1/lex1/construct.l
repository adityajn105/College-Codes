%{
	#include<stdio.h>
%}
main "main()"
header "stdio.h" | "conio.h"
a [\<]
b [\>]
id [a-za-z0-9 | a-zA-z ]
%%
{id}   {printf("\n %s is a variable",yylex);}
"#include"{a}{header}{b} {printf("\n %s - header file",yylex);}
{main} {printf("\n %s - built-in function.",yytext);}
%%
int yywrap()
{
	return 1;
}
int main()
{
	yyin=fopen("code.c","r");
	yylex();
}
