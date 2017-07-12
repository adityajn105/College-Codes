%{
	#include<stdio.h>
	struct data{
		char key[10];
		char value[30];
		struct data *next;
	};
	typedef struct data Node;

	Node* head=0;

	void insert(char key[],char value[]){
		Node* curr = head;
		while(curr->next!=0){
			curr=curr->next;
		}
		curr->next = (Node*)malloc(sizeof(Node));
		curr=curr->next;
		strcpy(curr->value,value);
		strcpy(curr->key,key);
		curr->next=0;
	}

	void showTable(){
		Node* curr = head;
		curr=curr->next;
		printf("Symbol\t\t\ttype\n");
		printf("------\t\t\t----\n");
		while(curr!=NULL){
		printf("%s\t\t\t%s\n",curr->value,curr->key);
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
ignore ";"|"="|","|"{"|"}"
%%
"#include"{a}{header}{b} {insert("Header",yytext); }
{KW}\(.*\)	{insert("BuiltinFun",yytext);}
{id}\(.*\)	{insert("UserDefFun",yytext);}	
{dt} {insert("DataType",yytext);}
{id}["["]\(.*\)	{insert("Array",yytext);}
{id}	{insert("Variable",yytext);}
{op}	{insert("Operator",yytext);}
{ignore}		{}
%%
int yywrap()
{
	return 1;
}
int main()
{
	head=(Node*)malloc(sizeof(Node));
	head->next=NULL;
	yyin=fopen("code.c","r");
	yylex();
	showTable();
}