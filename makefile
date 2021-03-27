a.out: y.tab.cpp lex.yy.c
	g++ -w lex.yy.c y.tab.cpp
	@echo "Run the Test Codes as : ./a.out < [TEST_FILES/testx]"
	@echo "And then, to run asm code, do : make runnasm"

y.tab.cpp: yacc.y
	yacc -Wno -v -d -g yacc.y -o y.tab.cpp

lex.yy.c: lex.l y.tab.hpp
	lex lex.l

clean:
	@rm -rf lex.yy.c y.tab.hpp y.tab.cpp a.out gen.o gen y.dot y.output gen.asm
	@echo "rm -rf lex.yy.c y.tab.hpp y.tab.cpp a.out gen.o gen y.dot y.output gen.asm"

runnasm:
	nasm -f elf64 -o gen.o gen.asm
	ld gen.o -o gen
	./gen