all:
	bison -d parser.y
	flex myscanner.l
	g++ parser.tab.c lex.yy.c -std=c++11 -lfl -o parser 
	./parser < tests/test1.in
