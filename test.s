	.text
	.globl main

main:
	li $v0 0
	sw $v0 i_
	li $a0 10
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

