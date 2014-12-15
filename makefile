rep1 = Quad_symbole
rep2 = Stenc

all:
	yacc -d proj.y
	lex proj.l	
	gcc -g -o stencil y.tab.c lex.yy.c $(rep1)/symbol.c $(rep1)/quad.c $(rep2)/stenc.c -ly -lfl -I $(rep1) -I $(rep2)
clean:
	rm -rf *.out y.tab.* lex.yy.* *~
