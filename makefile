all:
	lex proj.l	
	gcc lex.yy.c -lfl
clean:
	rm -rf *.out