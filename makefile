all:
	yacc -d proj.y
	lex proj.l	
	gcc -g y.tab.c lex.yy.c Quad_symbole/symbol.c Quad_symbole/quad.c -ly -lfl -I Quad_symbole
clean:
	rm -rf *.out y.tab.* lex.yy.*