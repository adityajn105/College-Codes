%{
	#include <stdio.h>
	#include <math.h>
	#include <stdlib.h>

	void yyerror(char*);
	extern int yylex();

	typedef struct Node Node;
	struct Node{
		char c;
		Node *lptr,*rptr;
	};

	Node* mknode(char,Node*,Node*);
	void preorderDisplay(Node*);
%}
%union{
	char c;
	struct Node* nd;
}
%token <c> ID
%token END
%type <nd> exp
%left '*' '/'
%left '+' '-'
%right '='
%%
stmt 	: exp END	{printf("Preorder Display :"); preorderDisplay($1);printf("\n"); }
		;

exp	:	
		exp '+' exp 	{ $$ = mknode('+',$1,$3); }
		| exp '-' exp 	{ $$ = mknode('-',$1,$3); }
		| exp '*' exp 	{ $$ = mknode('*',$1,$3); }
		| exp '/' exp 	{ $$ = mknode('/',$1,$3); }
		| ID 			{ $$ = mknode($1,NULL,NULL); }
		| exp '=' exp	{ $$ = mknode('=',$1,$3); }
		;
%%

Node* mknode(char a, Node* l, Node* r){
	Node* ans = (Node*)malloc(sizeof(Node));
	ans->c = a;
	ans->lptr = l;
	ans->rptr = r;
	return ans;
}

void preorderDisplay(Node* node){
	if(node!=NULL){
		printf("%c",node->c);
		preorderDisplay(node->lptr);
		preorderDisplay(node->rptr);
	}
}

int main(){
	yyparse();
}

void yyerror(char* c){
	printf("Syntax Error %c \n",*c);
}