all:
	bison -d parser.y
	flex myscanner.l
	g++ parser.tab.c lex.yy.c -lfl -o parser
	./parser < tests/test1.in
