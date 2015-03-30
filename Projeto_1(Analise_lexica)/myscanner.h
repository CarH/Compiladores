#ifndef SCANNER_H
#define SCANNER_H value
// Defines :

#define ERRO 1 					// Erro -> tá muito genérico, tem que ser mais claro.
#define IDENT 2					// NOME DO PROGRAMA, POR EXEMPLO
#define SEMICOLON 3				// ;
#define ENDPOINT 4				// .
#define ATTRIBUTION 5			// :=
#define CONST_IDENT 7 			// SERÁ QUE É O MESMO DE IDENT ? PQ EU ACHO Q A REGRA DISSO = REGRA DO IDENT
#define COLON 9					// :
#define TYPE 10					// integer/real
#define COMMA 11				// ,
#define PROCEDURE_IDENT 12		// NOME DO PROCEDIMENTO
#define OPEN_PAR 13				// (
#define CLOSE_PAR 14			// )
#define EQUAL 15				// =
#define DIF 16					// <>
#define GREATER_EQUAL 17		// >=
#define LESSER_EQUAL 18			// <=
#define GREATER 19 				// >
#define LESSER 20				// <
#define PLUS 21					// +
#define MINUS 22				// -
#define MULT 23					// *
#define DIV 24					// /
#define INTEGER_NUMBER 25		// NUMERO INTEIRO
#define REAL_NUMBER 26			// NUMERO REAL DIFERENTE DE INTEIRO
#define UNEXPECTED_CHAR 27		// Unexpected character

/// Palavras Reservadas: HashCode de acordo com a função hash em 'myscanner.c'
#define PROGRAM 681
#define BEGIN 179
#define END 388
#define VAR 108
#define REAL 533
#define INTEGER 766
#define PROCEDURE 588
#define IF 504
#define ELSE 1012
#define READ 525
#define WRITE 341
#define WHILE 99
#define DO 348
#define THEN 254


#endif