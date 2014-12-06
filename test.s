	.text
	.globl main

main:
	li $v0 9
	sw $v0 i_
	lw $a0 i_
	li $v0 1
	syscall
	li $a0 0
	li $v0 17
	syscall
	.data
height_:	.word 128
width_:	.word 128
i_:	.word 0
j_:	.word 0

