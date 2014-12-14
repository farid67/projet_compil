	.text
	.globl main

main:
	li $a0 0
	li $v0 17
	syscall



tmp_4 : 
	nop

	.data
height_:	.word 128
width_:	.word 128
s1_:	.word -1 ,0 ,1 ,-2 ,0 ,2 ,-1 ,0 ,1 

