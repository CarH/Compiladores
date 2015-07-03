#!/bin/bash

while true; do

	echo "Digite o nome do arquivo de entrada (Exemplo: entrada.in) ou digite \"sair\" para sair"
	# read x
	x="/home/sanches/projects/Compiladores/Projeto_3(Analise_sintatica)/tests/test2.in";
	if [ $x == "sair" ]; then
		exit 0;
	fi

	if [ ! -f $x ]; then
		echo "File not found!"
	fi

	echo "Compilando o scanner..."
	bison -d parser.y &> /dev/null
	flex myscanner.l
	echo "Compilando o parser..."
	g++ parser.tab.c lex.yy.c -lfl -o parser -std=c++11 
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
	break;
done
