# myparser: y.tab.c lex.yy.c y.tab.h
# 	gcc y.tab.c lex.yy.c -g -ll -o myparser
# lex.yy.c: lex.l
# 	lex lex.l
# y.tab.c: yacc.y
# 	yacc -v -d -g yacc.y
# clean:
# 	rm -f myparser y.tab.c lex.yy.c y.tab.h y.output y.dot a.out
# execute1:
# 	./myparser TEST_FILES/test1


a.out: y.tab.cpp lex.yy.c
	g++ lex.yy.c y.tab.cpp
	@echo "Run the program as ./a.out < [input_file]"

y.tab.cpp: yacc.y
	yacc -d yacc.y -o y.tab.cpp

lex.yy.c: lex.l y.tab.hpp
	lex lex.l

clean:
	@rm -rf lex.yy.c y.tab.hpp y.tab.cpp a.out