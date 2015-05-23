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
	g++ parser.tab.c lex.yy.c -lfl -o parser
	echo 
	echo "----------------------------------------------------"
	echo " Executando teste..."
	echo "----------------------------------------------------
	"
	./parser < $x > result.out
	cat result.out
	echo
	echo "----------------------------------------------------"
	rm -f parser
	rm  -f result.out
done
