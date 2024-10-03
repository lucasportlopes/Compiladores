ETAPA = etapa1

all: $(ETAPA)

$(ETAPA): lex.yy.c main.c tokens.h
	gcc main.c lex.yy.c -o $(ETAPA)

lex.yy.c: scanner.l
	flex scanner.l

clean:
	rm -f lex.yy.c $(ETAPA) scanner

tar:
	tar cvzf $(ETAPA).tgz main.c tokens.h scanner.l Makefile

.PHONY: all clean tar
