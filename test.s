	.text
	.globl main

main:
	li $v0 6
	sw $v0 i_
	li $a0 0
	li $v0 17
	syscall
	.data
height_:	.word 128
width_:	.word 128
tab_:	.word 0 ,2 ,1 ,3 ,1 ,3 
i_:	.word 0

