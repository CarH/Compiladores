all: compile run

compile:
	bison -d parser.y
	flex myscanner.l
	g++ parser.tab.c lex.yy.c -lfl -o parser 

run:
	./parser < tests/test1.in
