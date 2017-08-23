Check: lex.yy.c y.tab.c y.tab.h
	gcc -g lex.yy.c y.tab.c -o Check -ll 		# (-l) means to link lex

lex.yy.c: Main.l
	flex Main.l

y.tab.c: Main.y
	byacc -d Main.y

clean:
	rm lex.yy.c y.tab.c y.tab.h Check