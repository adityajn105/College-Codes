%{
	#include "y.tab.h"
	extern int yyerror(char*);
	extern int yylex();
%}
num [0-9]+"."?[0-9]*
%%
{num} 					{yylval.dval=atof(yytext);return NUM;}
[+ | - | / | * | '\n']	return *yytext;
"^"						return *yytext;
"("						return OB;
")"						return CB;
"sin"					return SINE;
"cos"					return COS;
"tan"					return TAN;
%%
extern int yywrap(){
	return 1;
}