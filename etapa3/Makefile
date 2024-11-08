ETAPA = etapa3

$(ETAPA): main.o lex.yy.o parser.tab.o asd.c
	gcc -o $(ETAPA) main.o lex.yy.o parser.tab.o asd.c

asd: asd.h asd.c main.c
	gcc -fsanitize=address -g -Werror -o asd asd.c main.c

parser.tab.h: parser.y
	bison -d -Wcounterexamples parser.y

lex.yy.c: scanner.l
	flex scanner.l

main.o: main.c parser.tab.h
	gcc -c main.c

lex.yy.o: lex.yy.c
	gcc -c lex.yy.c

parser.tab.o: parser.tab.c
	gcc -c parser.tab.c

tar:
	tar cvzf $(ETAPA).tgz main.c scanner.l parser.y asd.c asd.h Makefile

.PHONY: clean

clean:
	rm -f *.o lex.yy.c $(ETAPA) parser.tab.* scanner.lex.c saida.dot