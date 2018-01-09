%{
	#include<stdio.h>
	#include "y.tab.h"
%}
LETTER [a-zA-Z]+
%%
{LETTER} {yylval.a=(char)yytext[0];return ID;}
[ \t];
\n return 0;
. {return yytext[0];}
%%
 int yywrap()
{
	return 1;
}
