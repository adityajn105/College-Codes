%{
	#include "y.tab.h"
	extern int yylval;
	extern int yyerror(char*);
	extern int yylex();
%}
op "+"|"-"|"*"|"/"|""
%%
[0-9]+	{yylval=atoi(yytext);return NUM;}
[+ | '\n']	{return *yytext;}
%%
extern int yywrap(){
	return 1;
}

