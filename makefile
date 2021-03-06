a.out: y.tab.cpp lex.yy.c
	g++ -O3 lex.yy.c y.tab.cpp
	@echo "Run the program as ./a.out < [input_file]"

y.tab.cpp: yacc.y
	yacc -d yacc.y -o y.tab.cpp

lex.yy.c: lex.l y.tab.hpp
	lex lex.l

clean:
	@rm -rf lex.yy.c y.tab.hpp y.tab.cpp a.out gen.o gen

makenasm1:
	./a.out < TEST_FILES/test1

makenasm2:
	./a.out < TEST_FILES/test2

makenasm3:
	./a.out < TEST_FILES/test3

makenasm4:
	./a.out < TEST_FILES/test4

makenasm5:
	./a.out < TEST_FILES/test5

makenasm6:
	./a.out < TEST_FILES/test6

runnasm:
	nasm -f elf64 -o gen.o NASM_FILES/gen.asm
	ld gen.o -o gen
	./gen