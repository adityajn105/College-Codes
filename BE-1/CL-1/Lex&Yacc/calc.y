%{
	#include <stdio.h>
	#include <math.h>
	void yyerror(char*);
	int yylex(void);
%}
%union{
	double dval;
	char *ptr;
}
%token <dval> NUM
%token OP
%token SINE
%token COS
%token OB
%token CB
%token TAN
%type <dval> E
%%
S:
	S E '\n'	{ printf("Result: %lf\n",$2); }
	|
	;
E:	
	E '+' E 	{$$ = $1 + $3;}
	| E '-' E 	{$$ = $1 - $3;}
	| E '*'	E 	{$$ = $1 * $3;}
	| E '/' E 	{$$ = $1 / $3;}
	| NUM	{ $$ = $1; }
	| SINE OB E CB	{$$=sin($3*3.14/180);}
	| COS OB E CB	{$$=cos($3*3.14/180);}
	| TAN OB E CB	{$$=tan($3*3.14/180);}
	;
%%
int main(){
	yyparse();
	return 0;
}
void yyerror(char* e){
	printf("Invalid Code\n");
}
