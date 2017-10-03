a.out : lex.yy.c
	gcc lex.yy.c

lex.yy.c : construct.l
	flex construct.l

delete :
	rm a.out lex.yy.c