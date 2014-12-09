	.text
	.globl main

main:
	li $t0 12
	la $t2 tab_
	li $t1 3
	mul $t1 $t1 4
	add $t1 $t2 $t1
	sw $t0 0($t1)
	la $t2 tab_
	li $t1 3
	mul $t1 $t1 4
	add $t1 $t2 $t1
	lw $t0 0($t1)
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
tab_:	.word 0 ,0 ,0 ,0 ,0 ,0 
i_:	.word 0

