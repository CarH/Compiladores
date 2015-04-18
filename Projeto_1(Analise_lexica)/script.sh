echo "Digite o nome do arquivo de entrada (Exemplo: bla.c)"
read x;

echo "Compilando o compiler"
lex myscanner.l
gcc lex.yy.c myscanner.c -o scanner -g

echo "Rodando analise"
./scanner < $x > result.out

cat result.out

rm -rf myscanner
rm -rf result.out
