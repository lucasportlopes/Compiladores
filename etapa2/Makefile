ETAPA = etapa2

$(ETAPA): main.o lex.yy.o parser.tab.o
	gcc -o $(ETAPA) main.o lex.yy.o parser.tab.o 

parser.tab.h: parser.y
	bison -d parser.y

lex.yy.c: scanner.l
	flex scanner.l

main.o: main.c parser.tab.h
	gcc -c main.c

lex.yy.o: lex.yy.c
	gcc -c lex.yy.c

parser.tab.o: parser.tab.c
	gcc -c parser.tab.c

.PHONY: clean

clean:
	rm -f *.o lex.yy.c $(ETAPA) parser.tab.*