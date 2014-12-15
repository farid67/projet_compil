ici
ici
	.text
	.globl main

main:
	lw $t1 width_
	lw $t1 height_
	lw $t1 width_
	lw $t1 height_
	li $t0 1
	sw $t0 i_



tmp_3 : 
	lw $t6 i_
	li $t7 0
	 blt $t6 $t7 tmp_42
	b tmp_44



tmp_40 : 
	li $t5 1
	lw $t3 i_
	add $t0 $t5 $t3
	sw $t0 i_
	lw $t0 i_
	b tmp_3



tmp_42 : 
	li $t0 1
	sw $t0 j_



tmp_10 : 
	lw $t6 j_
	li $t7 0
	 blt $t6 $t7 tmp_37
	b tmp_39



tmp_35 : 
	li $t5 1
	lw $t3 j_
	add $t0 $t5 $t3
	sw $t0 j_
	lw $t0 j_
	b tmp_10



tmp_37 : 
	la $t2 image_
	mul $t1 $t1 4
	add $t4 $t2 $t1
	lw $t5 0($t4)
	la $t2 s_gx_
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
	la $t2 image_
	mul $t1 $t1 4
	add $t4 $t2 $t1
	lw $t5 0($t4)
	la $t2 s_gx_
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
	la $t2 image_
	mul $t1 $t1 4
	add $t4 $t2 $t1
	lw $t5 0($t4)
	la $t2 s_gx_
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
	sw $t0 gx_



tmp_17 : 
	lw $t6 gx_
	li $t7 0
	 blt $t6 $t7 tmp_21
	b tmp_22



tmp_21 : 
	lw $t3 gx_
	sw $t0 gx_



tmp_22 : 
	la $t2 image_
	mul $t1 $t1 4
	add $t4 $t2 $t1
	lw $t5 0($t4)
	la $t2 s_gy_
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
	la $t2 image_
	mul $t1 $t1 4
	add $t4 $t2 $t1
	lw $t5 0($t4)
	la $t2 s_gy_
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
	la $t2 image_
	mul $t1 $t1 4
	add $t4 $t2 $t1
	lw $t5 0($t4)
	la $t2 s_gy_
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
	sw $t0 gy_



tmp_26 : 
	lw $t6 gy_
	li $t7 0
	 blt $t6 $t7 tmp_30
	b tmp_31



tmp_30 : 
	lw $t3 gy_
	sw $t0 gy_



tmp_31 : 
	lw $t5 gx_
	lw $t3 gy_
	add $t0 $t5 $t3
	move $t6 $t0
	li $t3 2
	move $t5 $t6
	div $t0 $t5 $t3
	move $t6 $t0
	lw $t1 j_
	la $t2 sobel_
	mul $t1 $t1 4
	add $t4 $t2 $t1
	sw $t0 0($t4)
	b tmp_35



tmp_39 : 
	b tmp_40



tmp_44 : 
	li $a0 0
	li $v0 17
	syscall



tmp_49 : 
	nop

	.data
height_:	.word 128
width_:	.word 128
i_:	.word 0
j_:	.word 0
gx_:	.word 0
gy_:	.word 0
image_:	.word 0 
s_gx_:	.word -1 ,0 ,1 ,-2 ,0 ,2 ,-1 ,0 ,1 
s_gy_:	.word 1 ,2 ,1 ,0 ,0 ,0 ,-1 ,2 ,1 

