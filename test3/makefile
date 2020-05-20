test: y.tab.h lex.yy.c
	gcc lex.yy.c y.tab.c -o test
y.tab.h: test.y
	yacc -d test.y
lex.yy.c: test.l y.tab.h
	lex  test.l
