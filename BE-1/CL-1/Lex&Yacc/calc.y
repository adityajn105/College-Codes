%{
	#include <stdio.h>
	void yyerror(char*);
	int yylex(void);
%}
%token NUM
%token OP
%%
S:
	S E '\n'	{ printf("Result: %d\n",$2); }
	|
	;
E:	
	E '+' E 	{ $$ = $1 + $3; }
	| NUM	{ $$ = $1; }
	;
%%
int main(){
	yyparse();
	return 0;
}

void yyerror(char* e){
	printf("Invalid Code\n");
}
