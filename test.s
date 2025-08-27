	.file	"test.c"
	.text
	.section .rdata,"dr"
.LC0:
	.ascii "%d \12\0"
	.text
	.globl	fibb
	.def	fibb;	.scl	2;	.type	32;	.endef
	.seh_proc	fibb
fibb:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movl	$1, -4(%rbp)
	movl	$0, -8(%rbp)
	movl	$0, -12(%rbp)
	jmp	.L2
.L3:
	movl	-4(%rbp), %edx
	movl	-8(%rbp), %eax
	addl	%edx, %eax
	movl	%eax, -16(%rbp)
	movl	-16(%rbp), %eax
	movl	%eax, %edx
	leaq	.LC0(%rip), %rax
	movq	%rax, %rcx
	call	printf
	movl	-4(%rbp), %eax
	movl	%eax, -8(%rbp)
	movl	-16(%rbp), %eax
	movl	%eax, -4(%rbp)
	addl	$1, -12(%rbp)
.L2:
	movl	-12(%rbp), %eax
	cmpl	16(%rbp), %eax
	jl	.L3
	nop
	nop
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	call	__main
	movl	$10, -4(%rbp)
	cmpl	$2, 16(%rbp)
	jne	.L5
	movq	24(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	movq	%rax, %rcx
	call	atoi
	movl	%eax, -4(%rbp)
.L5:
	movl	-4(%rbp), %eax
	movl	%eax, %ecx
	call	fibb
	movl	$0, %eax
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (MinGW-W64 x86_64-ucrt-posix-seh, built by Brecht Sanders, r8) 13.2.0"
	.def	printf;	.scl	2;	.type	32;	.endef
	.def	atoi;	.scl	2;	.type	32;	.endef
