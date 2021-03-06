a.out: y.tab.cpp lex.yy.c
	g++ -w lex.yy.c y.tab.cpp
	@echo "Run the program as ./a.out < [input_file]"

y.tab.cpp: yacc.y
	yacc -Wno -v -d -g yacc.y -o y.tab.cpp

lex.yy.c: lex.l y.tab.hpp
	lex lex.l

clean:
	@rm -rf lex.yy.c y.tab.hpp y.tab.cpp a.out gen.o gen

runnasm:
	nasm -f elf64 -o gen.o NASM_FILES/gen.asm
	ld gen.o -o gen
	./gen