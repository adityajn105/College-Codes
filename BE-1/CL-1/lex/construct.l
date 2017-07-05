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
		while(curr!=NULL){
			curr=curr->next;
		}
		curr = (struct data *)malloc(sizeof(struct data));
		strcpy(curr->value,value);
		strcpy(curr->key,key);
		printf("%s %s\n",curr->key,curr->value);
		curr->next=NULL;
	}
	void showTable(){
		struct data* curr = head;
		printf("Symbol\t\ttype\n");
		while(curr!=NULL){
			printf("%s\t%s\n",curr->value,curr->key);
			curr=curr->next;
		}
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
"#include"{a}{header}{b} {char temp[10]="Header";insert(&temp,yytext); }
{KW}\(.*\)	{char temp[10]="BuiltinFun";insert(&temp,yytext);}
{id}\(.*\)	{char temp[10]="UserDefFun";insert(&temp,yytext);}	
{id}	{char temp[10]="var";insert(&temp,yytext);}
{op}	{char temp[10]="Operator";insert(&temp,yytext);}
"}"		{showTable();}
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

