	.text
	.globl main

main:
	li $t0 0
	sw $t0 i_



tmp_2 : 
	lw $t6 i_
	li $t7 1
	 bne $t6 $t7 tmp_9
	b tmp_7



tmp_7 : 
	li $t0 5
	sw $t0 j_
	b tmp_10



tmp_9 : 
	li $t0 10
	sw $t0 j_



tmp_10 : 



tmp_11 : 
	lw $t6 i_
	lw $t7 j_
	 blt $t6 $t7 tmp_18
	b tmp_20



tmp_18 : 
	li $t5 1
	lw $t3 i_
	add $t0 $t5 $t3
	sw $t0 i_
	lw $t0 i_
	lw $a0 i_
	li $v0 1
	syscall
	b tmp_11



tmp_20 : 
	li $a0 0
	li $v0 17
	syscall



tmp_25 : 
	nop

	.data
height_:	.word 128
width_:	.word 128
i_:	.word 0
j_:	.word 0

