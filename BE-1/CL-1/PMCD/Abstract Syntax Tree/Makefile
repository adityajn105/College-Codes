ast	:	lex.yy.c y.tab.c y.tab.h
	gcc lex.yy.c y.tab.c -o ast -lm

lex.yy.c	:	ast.l
	flex ast.l

y.tab.c y.tab.h	:	ast.y
	byacc -d ast.y

clean:
	rm -f lex.yy.c y.tab.c y.tab.h ast