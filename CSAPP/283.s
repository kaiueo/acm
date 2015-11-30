	.file	"283.c"
	.text
.globl f2u
	.type	f2u, @function
f2u:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	fnstcw	-2(%ebp)
	movzwl	-2(%ebp), %eax
	movb	$12, %ah
	movw	%ax, -4(%ebp)
	flds	8(%ebp)
	fldcw	-4(%ebp)
	fistpll	-16(%ebp)
	fldcw	-2(%ebp)
	movl	-16(%ebp), %eax
	leave
	ret
	.size	f2u, .-f2u
.globl float_ge
	.type	float_ge, @function
float_ge:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	%ebx, -12(%ebp)
	movl	%esi, -8(%ebp)
	movl	%edi, -4(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	f2u
	movl	%eax, %ebx
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	f2u
	leal	(%ebx,%ebx), %edx
	testl	%edx, %edx
	jne	.L4
	movl	%eax, %edx
	addl	%edx, %edx
	je	.L5
.L4:
	movl	%ebx, %ecx
	shrl	$31, %ecx
	movl	%eax, %edi
	shrl	$31, %edi
	movl	%edi, %esi
	testl	%ecx, %ecx
	jne	.L12
	movl	%edi, %edx
	testb	%dl, %dl
	jne	.L5
.L12:
	testl	%edi, %edi
	jne	.L13
	testl	%ecx, %ecx
	.p2align 4,,3
	jne	.L13
	cmpl	%eax, %ebx
	.p2align 4,,5
	jae	.L5
.L13:
	movl	%esi, %edx
	testb	%dl, %dl
	.p2align 4,,3
	je	.L14
	testl	%ecx, %ecx
	.p2align 4,,3
	jne	.L8
.L14:
	movl	$0, %eax
	.p2align 4,,3
	jmp	.L10
.L8:
	cmpl	%eax, %ebx
	setbe	%al
	movzbl	%al, %eax
	jmp	.L10
.L5:
	movl	$1, %eax
.L10:
	movl	-12(%ebp), %ebx
	movl	-8(%ebp), %esi
	movl	-4(%ebp), %edi
	movl	%ebp, %esp
	popl	%ebp
	ret
	.size	float_ge, .-float_ge
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC3:
	.string	"%d\n"
	.text
.globl main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
	subl	$16, %esp
	movl	$0x40000000, 4(%esp)
	movl	$0x41200000, (%esp)
	call	float_ge
	movl	%eax, 4(%esp)
	movl	$.LC3, (%esp)
	call	printf
	leave
	ret
	.size	main, .-main
	.ident	"GCC: (GNU) 4.4.0 20090506 (Red Hat 4.4.0-4)"
	.section	.note.GNU-stack,"",@progbits
