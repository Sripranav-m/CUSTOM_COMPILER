a.out: y.tab.cpp lex.yy.c
	g++ -w lex.yy.c y.tab.cpp main.cpp registers.cpp
	@echo "Run the Test Codes as : ./a.out < [TEST/testx]"
	@echo "And then, to run asm code, do : make runnasm"

y.tab.cpp: yacc.y
	yacc -Wno -v -d -g yacc.y -o y.tab.cpp

lex.yy.c: lex.l y.tab.hpp
	lex lex.l

clean:
	@rm -rf lex.yy.c y.tab.hpp y.tab.cpp a.out gen.o gen.lst gen y.dot y.output gen.asm
	@echo "rm -rf lex.yy.c y.tab.hpp y.tab.cpp a.out gen.o gen.lst gen y.dot y.output gen.asm"

runnasm:
	nasm -f elf64 -l gen.lst gen.asm
	gcc -m64 -o gen gen.o -no-pie
	./gen