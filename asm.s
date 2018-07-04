	.data
.globl 	a
	.data 	
	.align 2
	.type	a, @object
	.size	a,1
a:
	.byte	0
	.globl	Tempey1
Tempey1:
	.long	0
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	pushq	%rbp
	movq	%rsp, %rbp
	andl	$-16, %esp
	movl	$2, %eax
	addl	$3, %eax
	movw	%ax, Tempey1
	movw	Tempey1, %ax
	movw	%ax, a
	leave
	ret
.LFE0:
.size	main, .-main
