%{
	#include<stdio.h>
	int decimal=0,vowels=0,cons=0,line=0,word=0,t=0,c=0,fraction=0;
%}
VOWELS [aeiouAEIOU]
WORD [ ]
CON [a-zA-Z]
ALPHA [a-zA-Z]
LINE [\n]
POINT [.]
NUM [0-9]
FRAC [/]

%%
{VOWELS} {vowels++;printf("\n%s is a vowel",yytext);}
{CON} {cons++;printf("\n%s is a consonant",yytext);}
{WORD} {word++;}
{CON}{WORD}{ALPHA} {printf("\n%s is a word",yytext);}
{LINE} {line++;}
{NUM}{POINT}{NUM} {decimal++;printf("\n%s is a decimal number",yytext);}
{NUM}{FRAC}{NUM} {fraction++;printf("\n%s is a fractional representation",yytext);}
%%
int yywrap()
{
	return 1;
}
int main()
{
	yyin=fopen("a","r");
	yylex();
	t=word+line;
	c=cons+vowels;
	printf("\nNo. of vowels -->>%d\nNo. of consonant -->>%d\nNo. of characters -->>%d\nNo. of words -->>%d\nNo. of Lines in the file -->>%d\nTotal Decimal numbers -->>%d\nTotal Fraction numbers -->>%d\n",vowels,cons,c,t,line,decimal,fraction);

}
