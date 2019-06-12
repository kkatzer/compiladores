$DEPURA=1

compilador: lex.yy.c y.tab.c main.o main.h
	gcc lex.yy.c parser.tab.c main.o -o main -ll -ly -lc

lex.yy.c: tokens.l main.h
	flex tokens.l

y.tab.c: parser.y main.h
	bison parser.y -d -v

main.o : main.h main.c
	gcc -c main.c -o main.o

clean :
	rm -f parser.tab.* lex.yy.c parser.output main.o main
