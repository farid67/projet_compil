	.text
	.globl main

main:
	 la $a0 tmp_0
	li $v0 4
	syscall
	 la $a0 tmp_4
	li $v0 4
	syscall
	li $a0 0
	li $v0 17
	syscall



tmp_12 : 
	nop

	.data
height_:	.word 128
width_:	.word 128
tmp_0:	 .asciiz "Bonjour\n"
tmp_4:	 .asciiz "Hello\n"

