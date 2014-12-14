	.text
	.globl main

main:
<<<<<<< HEAD
=======
	li $t0 0
	sw $t0 i_
	li $t0 1
	sw $t0 j_
	li $t0 2
	sw $t0 k_
	li $t0 12
	sw $t0 l_
	lw $t1 j_
	la $t2 tab_
	mul $t1 $t1 4
	add $t4 $t2 $t1
	lw $t5 0($t4)
	lw $t1 k_
	la $t2 tab_
	mul $t1 $t1 4
	add $t4 $t2 $t1
	lw $t3 0($t4)
	mul $t0 $t5 $t3
	move $t6 $t0
	lw $t1 i_
	la $t2 tab_
	mul $t1 $t1 4
	add $t4 $t2 $t1
	lw $t5 0($t4)
	move $t5 $t6
	add $t0 $t5 $t3
	move $t6 $t0
	lw $t3 l_
	move $t5 $t6
	sub $t0 $t5 $t3
	move $t6 $t0
	sw $t0 j_
	lw $a0 j_
	li $v0 1
	syscall
>>>>>>> 313f9b10c685e43e54ff532d2ba54198948033a1
	li $a0 0
	li $v0 17
	syscall



<<<<<<< HEAD
tmp_4 : 
=======
tmp_15 : 
>>>>>>> 313f9b10c685e43e54ff532d2ba54198948033a1
	nop

	.data
height_:	.word 128
width_:	.word 128
<<<<<<< HEAD
s1_:	.word -1 ,0 ,1 ,-2 ,0 ,2 ,-1 ,0 ,1 
=======
tab_:	.word 5 ,6 ,7 
i_:	.word 0
j_:	.word 0
k_:	.word 0
l_:	.word 0
>>>>>>> 313f9b10c685e43e54ff532d2ba54198948033a1

