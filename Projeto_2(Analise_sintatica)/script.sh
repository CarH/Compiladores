#!/bin/bash

while true; do

	echo "Digite o nome do arquivo de entrada (Exemplo: entrada.in) ou digite \"sair\" para sair"
	read x
	
	if [ $x == "sair" ]; then
		exit 0;
	fi

	if [ ! -f $x ]; then
		echo "File not found!"
	fi

	echo "Compilando o scanner..."
	bison -d parser.y
	flex myscanner.l
	echo "Compilando o parser..."
	g++ parser.tab.c lex.yy.c -std=c++11 -lfl -o parser
	echo "Executando teste...
	----------------------------------------------------
	"
	./parser < $x > result.out
	cat result.out
	echo "
	----------------------------------------------------"
	rm 	parser
	rm  result.out
done
