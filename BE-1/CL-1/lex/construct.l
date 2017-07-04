%{
	#include<stdio.h>
	#include<string.h>	
	struct data{
		char key[10];
		char value[30];
		struct data* next;
	};
	struct data* head=NULL;

	void insert(char* key,char* value){
		struct data* curr = head;
		while(curr!=NULL){curr=curr->next;}
		curr = (struct data *)malloc(sizeof(struct data));
		/*
			strcpy(curr->key,key);
			strcpy(curr->value,value);
			curr->next = NULL;
		*/
		char c[10];
		strcpy(curr->key,key);
		strcpy(c,value);
		printf("key %s\n",curr->key);
	}
%}
header "stdio.h"|"conio.h"
a "<"
b ">"
KW "main"|"getch"|"printf"|"scanf"
dt "int"|"float"
op "+"|"-"|"*"|"/"|""
id [a-zA-Z][a-zA-Z0-9]*
%%
"#include"{a}{header}{b} {char temp[10]="header";insert(&temp,&yytext); }
{KW}\(.*\)	{char temp[10]="BuiltinFun";insert(&temp,&yytext);}
{id}\(.*\)	{char temp[10]="UserDefFun";insert(&temp,&yytext);}	
{id}	{char temp[10]="Variable";insert(&temp,&yytext);}
{op}	{char temp[10]="Operator";insert(&temp,&yytext);}
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

