	.text
	.globl main

main:
	li $t0 0
	sw $t0 i_
	li $t0 0
	sw $t0 i_



tmp_3 : 
	lw $t6 i_
	li $t7 5
	 blt $t6 $t7 tmp_12
	b tmp_14



tmp_10 : 
	li $t5 1
	lw $t3 i_
	add $t0 $t5 $t3
	sw $t0 i_
	lw $t0 i_
	b tmp_3



tmp_12 : 
	lw $a0 i_
	li $v0 1
	syscall
	b tmp_10



tmp_14 : 
	li $a0 0
	li $v0 17
	syscall



tmp_19 : 
	nop

	.data
height_:	.word 128
width_:	.word 128
i_:	.word 0

