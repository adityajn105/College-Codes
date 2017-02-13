lex.yy.c: Main.l
	flex Main.l

y.tab.c: Main.y
	byacc -d Main.y

Check: lex.yy.c y.tab.c y.tab.h
	g++ -g lex.yy.c y.tab.c -o Check -ll

clean:
	rm lex.yy.c y.tab.c y.tab.h Check