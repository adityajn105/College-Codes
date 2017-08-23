%{
#include <stdio.h>
extern int yyparse();
extern int yylex();
extern int yyerror(char *e);
%}
%token IF
%token ELSE
%token THEN
%token NUM
%token ID
%token OP
%token ASSGN
%token WHILE
%token ENDIF
%token OB CB
%token DO
%token FOR
%token OPR CPR SC
%start s
%%
s : stmt { printf("Valid.\n"); exit(0); };

VAR : ID
	| NUM
	;

expr : VAR
	 | VAR OP VAR
	 | VAR ASSGN VAR
	 ;

stmt : IF expr THEN stmt ENDIF
	 | IF expr THEN stmt ELSE stmt ENDIF
	 | WHILE expr OB stmt CB
	 | DO OB stmt CB WHILE expr
	 | FOR OPR expr SC expr SC expr CPR OB stmt CB
	 | ID ASSGN expr
 	 ;
%%
int main() {
	yyparse();
}
extern int yyerror(char *e) {
	printf("Syntax Error.\n");
}