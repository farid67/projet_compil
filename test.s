	.text
	.globl main

main:
move $s0 $0 
move $s1 $0 
	la $t2 tab_
	li $t1 0
	mul $t1 $t1 4
	add $t4 $t2 $t1
	lw $t5 0($t4)
	la $t2 gx_
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
	la $t2 gx_
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
	la $t2 gx_
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
	la $t2 gx_
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
	la $t2 gx_
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
	la $t2 tab_
	li $t1 5
	mul $t1 $t1 4
	add $t4 $t2 $t1
	lw $t5 0($t4)
	la $t2 gx_
	li $t1 5
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
	li $t1 6
	mul $t1 $t1 4
	add $t4 $t2 $t1
	lw $t5 0($t4)
	la $t2 gx_
	li $t1 6
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
	li $t1 7
	mul $t1 $t1 4
	add $t4 $t2 $t1
	lw $t5 0($t4)
	la $t2 gx_
	li $t1 7
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
	li $t1 8
	mul $t1 $t1 4
	add $t4 $t2 $t1
	lw $t5 0($t4)
	la $t2 gx_
	li $t1 8
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
	sw $t0 grad_
move $s0 $0 
move $s1 $0 
	la $t2 tab2_
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
	la $t2 tab2_
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
	la $t2 tab2_
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
	la $t2 tab2_
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
	la $t2 tab2_
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
	li $a0 0
	li $v0 17
	syscall



tmp_17 : 
	nop

	.data
height_:	.word 128
width_:	.word 128
gx_:	.word -1 ,0 ,1 ,-2 ,0 ,2 ,-1 ,0 ,1 
tab_:	.word 1 ,2 ,3 ,4 ,5 ,6 ,7 ,8 ,9 
grad_:	.word 0
s_:	.word 1 ,1 ,1 ,1 ,1 
tab2_:	.word 42 ,21 ,7 ,314 ,127 
somme_:	.word 0

