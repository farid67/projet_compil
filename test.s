	.text
	.globl main

main:
	la $t2 tab_
	li $t1 0
	mul $t1 $t1 4
	add $t4 $t2 $t1
	lw $t5 0($t4)
	la $t2 s_
	li $t1 0
	mul $t1 $t1 4
	add $t4 $t2 $t1
	lw $t3 0($t4)
	mul $t0 $t5 $t3
	move $t6 $t0
	move $s1 $t0
	move $t0 $s0
	 move $t5 $s1
	 move $t3 $s0
	add $t0 $t5 $t3
	move $t6 $t0
	move $s0 $t0
	move $t0 $s0
	la $t2 tab_
	li $t1 1
	mul $t1 $t1 4
	add $t4 $t2 $t1
	lw $t5 0($t4)
	la $t2 s_
	li $t1 1
	mul $t1 $t1 4
	add $t4 $t2 $t1
	lw $t3 0($t4)
	mul $t0 $t5 $t3
	move $t6 $t0
	move $s1 $t0
	move $t0 $s0
	 move $t5 $s1
	 move $t3 $s0
	add $t0 $t5 $t3
	move $t6 $t0
	move $s0 $t0
	move $t0 $s0
	la $t2 tab_
	li $t1 2
	mul $t1 $t1 4
	add $t4 $t2 $t1
	lw $t5 0($t4)
	la $t2 s_
	li $t1 2
	mul $t1 $t1 4
	add $t4 $t2 $t1
	lw $t3 0($t4)
	mul $t0 $t5 $t3
	move $t6 $t0
	move $s1 $t0
	move $t0 $s0
	 move $t5 $s1
	 move $t3 $s0
	add $t0 $t5 $t3
	move $t6 $t0
	move $s0 $t0
	move $t0 $s0
	la $t2 tab_
	li $t1 3
	mul $t1 $t1 4
	add $t4 $t2 $t1
	lw $t5 0($t4)
	la $t2 s_
	li $t1 3
	mul $t1 $t1 4
	add $t4 $t2 $t1
	lw $t3 0($t4)
	mul $t0 $t5 $t3
	move $t6 $t0
	move $s1 $t0
	move $t0 $s0
	 move $t5 $s1
	 move $t3 $s0
	add $t0 $t5 $t3
	move $t6 $t0
	move $s0 $t0
	move $t0 $s0
	la $t2 tab_
	li $t1 4
	mul $t1 $t1 4
	add $t4 $t2 $t1
	lw $t5 0($t4)
	la $t2 s_
	li $t1 4
	mul $t1 $t1 4
	add $t4 $t2 $t1
	lw $t3 0($t4)
	mul $t0 $t5 $t3
	move $t6 $t0
	move $s1 $t0
	move $t0 $s0
	 move $t5 $s1
	 move $t3 $s0
	add $t0 $t5 $t3
	move $t6 $t0
	move $s0 $t0
	move $t0 $s0
	sw $t0 somme_
	lw $a0 somme_
	li $v0 1
	syscall
	lw $t5 somme_
	li $t3 12
	add $t0 $t5 $t3
	move $t6 $t0
	sw $t0 somme_
	lw $a0 somme_
	li $v0 1
	syscall
	li $a0 0
	li $v0 17
	syscall



tmp_16 : 
	nop

	.data
height_:	.word 128
width_:	.word 128
tab_:	.word 42 ,21 ,7 ,314 ,127 
s_:	.word 1 ,1 ,1 ,1 ,1 
somme_:	.word 0

