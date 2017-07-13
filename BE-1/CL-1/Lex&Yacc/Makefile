calc: lex.yy.c y.tab.c y.tab.h
	g++ -g lex.yy.c y.tab.c -o calc -ll
	
lex.yy.c: calc.l
	flex calc.l

y.tab.c: calc.y
	byacc -d calc.y
clean:
	rm lex.yy.c y.tab.c y.tab.h calc
