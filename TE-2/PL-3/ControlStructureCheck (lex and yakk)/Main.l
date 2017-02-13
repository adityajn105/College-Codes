%{
#include "y.tab.h"
extern int yyerror(char *e);
extern int yyval;
%}
%%
"if" { return IF; }
"then" { return THEN; }
"else" { return ELSE; }
"while" { return WHILE; }
"do" { return DO; }
"endif" { return ENDIF; }
"for" { return FOR; }
[0-9]+ { return NUM; }
[a-zA-Z]([a-zA-Z]|[0-9])* { return ID; }
[\+\*\/\-\<\>] { return OP; }
"&&" { return OP; }
"||" { return OP; }
"==" { return OP; }
"<=" { return OP; }
">=" { return OP; }
= { return ASSGN; }
"{" { return OB; }
"}" { return CB; }
"(" { return OPR; }
")" { return CPR; }
";" { return SC; }
%%
extern int yywrap() {
	return 1;
}