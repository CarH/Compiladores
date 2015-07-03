all: compile run

compile:
	bison -d parser.y
	flex myscanner.l
	g++ parser.tab.c lex.yy.c -std=c++11 -lfl -o parser 

run:
	./parser < tests/test2.in
