	.file	"263.c"
	.text
.globl sra
	.type	sra, @function
sra:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx
	movl	12(%ebp), %ecx
	movl	8(%ebp), %edx
	shrl	%cl, %edx
	movl	$31, %eax
	subl	%ecx, %eax
	movl	%eax, %ecx
	movl	$1, %eax
	sall	%cl, %eax
	leal	-1(%eax), %ecx
	movl	%eax, %ebx
	andl	%edx, %ebx
	notl	%ebx
	leal	(%ebx,%eax), %eax
	movl	%ecx, %ebx
	notl	%ebx
	andl	%ebx, %eax
	andl	%ecx, %edx
	orl	%edx, %eax
	popl	%ebx
	popl	%ebp
	ret
	.size	sra, .-sra
.globl srl
	.type	srl, @function
srl:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx
	movl	12(%ebp), %edx
	movl	$31, %ecx
	subl	%edx, %ecx
	movl	$2, %ebx
	movl	%ebx, %eax
	sall	%cl, %eax
	subl	$1, %eax
	movl	8(%ebp), %ebx
	movl	%edx, %ecx
	sarl	%cl, %ebx
	andl	%ebx, %eax
	popl	%ebx
	popl	%ebp
	ret
	.size	srl, .-srl
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"%d\n"
.LC1:
	.string	"%u\n"
	.text
.globl main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
	subl	$32, %esp
	movl	%ebx, 24(%esp)
	movl	%esi, 28(%esp)
	movl	$10, 4(%esp)
	movl	$-2048, (%esp)
	call	sra
	movl	%eax, %ebx
	movl	$10, 4(%esp)
	movl	$2048, (%esp)
	call	srl
	movl	%eax, %esi
	movl	%ebx, 4(%esp)
	movl	$.LC0, (%esp)
	call	printf
	movl	%esi, 4(%esp)
	movl	$.LC1, (%esp)
	call	printf
	movl	24(%esp), %ebx
	movl	28(%esp), %esi
	movl	%ebp, %esp
	popl	%ebp
	ret
	.size	main, .-main
	.ident	"GCC: (GNU) 4.4.0 20090506 (Red Hat 4.4.0-4)"
	.section	.note.GNU-stack,"",@progbits
