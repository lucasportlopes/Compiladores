ETAPA = etapa6

$(ETAPA): main.o lex.yy.o parser.tab.o asd.c symbol_table.c symbol_stack.c code_generation.c
	gcc -o $(ETAPA) main.o lex.yy.o parser.tab.o asd.c symbol_table.c symbol_stack.c code_generation.c

asd: asd.h asd.c main.c
	gcc -fsanitize=address -g -Werror -o asd asd.c main.c

symbol_stack: symbol_stack.h symbol_stack.c main.c
	gcc -fsanitize=address -g -Werror -o symbol_stack symbol_stack.c main.c

symbol_table: symbol_table.h symbol_table.c main.c
	gcc -fsanitize=address -g -Werror -o symbol_table symbol_table.c main.c

code_generation: code_generation.h code_generation.c main.c
	gcc -fsanitize=address -g -Werror -o code_generation code_generation.c main.c

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

graph: saida.dot
	dot -Tpng saida.dot -o result.png

runi:
	make clean
	make
	./etapa6 < teste.z > what.txt

run: 
	make clean
	make
	./etapa6 < teste.z > saida.s
	gcc saida.s -o programa
	./programa
	echo $?

tar:
	tar cvzf $(ETAPA).tgz main.c scanner.l parser.y asd.c asd.h types.h symbol_stack.c symbol_stack.h symbol_table.c symbol_table.h code_generation.c code_generation.h instructions.h Makefile

.PHONY: clean

clean:
	rm -f *.o lex.yy.c $(ETAPA) parser.tab.* scanner.lex.c saida.dot result.png saida saida.txt