	.text
	.globl main

main:
	li $t0 2
	sw $t0 i_
	lw $t1 i_
	li $t2 3
	add $t0 $t1 $t2
	sw $t0 i_
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

