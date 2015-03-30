 # MAKEFILE 
all: clean compile run

compile: myscanner.l 
	lex myscanner.l
	gcc lex.yy.c myscanner.c -o scanner

run:
	./scanner < in.in

clean:
	@rm -rf myscanner
	@rm -rf result.out

showresults:
	cat ./result.out

clonegithub:
	git clone https://github.com/

gitupload: gitpull gitadd gitcommit gitpush

gitpull:
	git pull

gitadd: 
	git add myscanner.l

gitcommit:
	git commit

gitpush:
	git push

backup:
	mkdir -p backup
	zip ./"backup/"proj1_backup_`date +"%d-%m-%Y_%H:%M"` ./Makefile ./*.c *.l *.in