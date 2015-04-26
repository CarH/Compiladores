 # MAKEFILE 
all: clean compile

compile: myscanner.l 
	lex myscanner.l
	gcc lex.yy.c myscanner.c -o scanner
	
run:
	# TESTE 1 :
	####
	@./scanner < tests/test1.in
	##############################################
	# TESTE 2 :
	####
	@./scanner < tests/test2.in
	##############################################
	# TESTE 3 :
	####
	@./scanner < tests/test3.in

clean:
	@rm -rf myscanner

backup:
	mkdir -p backup
	zip ./"backup/"proj1_backup_`date +"%d-%m-%Y_%H:%M"` ./Makefile ./*.c *.l *.in