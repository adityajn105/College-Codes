%{
	#include "y.tab.h"
	extern void yyerror(char*);
%}
%%
[a-z0-9]				{ yylval.c = (char)yytext[0]; return ID; }
[ + | - | * | / | = ]	{ return *yytext; }
";"						{ return END; }
. 						;
%%
extern int yywrap(){
	return 1; 
} 
