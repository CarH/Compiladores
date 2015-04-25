#!/bin/bash

while true; do

	echo "Digite o nome do arquivo de entrada (Exemplo: entrada.in) ou digite \"sair\" (aspas para clareza) para sair"
	read x
	
	if [ $x == "sair" ]; then
		exit 0;
	fi

	if [ ! -f $x ]; then
		echo "File not found!"
	fi

	echo "Compilando o compiler..."
	lex myscanner.l
	gcc lex.yy.c myscanner.c -o scanner -g

	echo "Rodando analise..."
	./scanner < $x > result.out

	cat result.out

	rm -rf myscanner
	rm -rf result.out
done
