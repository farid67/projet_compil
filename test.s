	.text
	.globl main

main:
	li $t0 3
	sw $t0 i_



tmp_2 : 
	lw $t6 i_
	li $t7 2
	 bge $t6 $t7 tmp_8
	b tmp_9



tmp_8 : 
	lw $a0 i_
	li $v0 1
	syscall



tmp_9 : 
	li $a0 0
	li $v0 17
	syscall



tmp_14 : 
	nop

	.data
height_:	.word 128
width_:	.word 128
i_:	.word 0

