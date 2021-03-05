a.out: y.tab.cpp lex.yy.c
	g++ lex.yy.c y.tab.cpp
	@echo "Run the program as ./a.out < [input_file]"

y.tab.cpp: yacc.y
	yacc -d yacc.y -o y.tab.cpp

lex.yy.c: lex.l y.tab.hpp
	lex lex.l

clean:
	@rm -rf lex.yy.c y.tab.hpp y.tab.cpp a.out
