all:
	bison -vdy parser.y -o parser.c
	lex -o tokens.c tokens.l
	gcc -g -Wall -o compiler parser.c tokens.c main.c

clean:
	rm -rf \
	parser.c \
	parser.h \
	parser.output \
	tokens.c \
	compiler

test:
	make
	./test.sh
