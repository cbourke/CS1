	.section	__TEXT,__text,regular,pure_instructions
	.globl	_main
	.align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp2:
	.cfi_def_cfa_offset 16
Ltmp3:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp4:
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movl	$0, -4(%rbp)
	movl	%edi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	cmpl	$2, -8(%rbp)
	je	LBB0_2
## BB#1:
	leaq	L_.str(%rip), %rsi
	movq	___stderrp@GOTPCREL(%rip), %rax
	movq	(%rax), %rdi
	movq	-16(%rbp), %rax
	movq	(%rax), %rdx
	movb	$0, %al
	callq	_fprintf
	movl	$1, %edi
	movl	%eax, -36(%rbp)         ## 4-byte Spill
	callq	_exit
LBB0_2:
	movq	-16(%rbp), %rax
	movq	8(%rax), %rdi
	callq	_atof
	xorps	%xmm1, %xmm1
	movsd	%xmm0, -24(%rbp)
	movsd	-24(%rbp), %xmm0
	sqrtsd	%xmm0, %xmm0
	movsd	%xmm0, -32(%rbp)
	ucomisd	-24(%rbp), %xmm1
	jbe	LBB0_4
## BB#3:
	leaq	L_.str1(%rip), %rsi
	movq	___stderrp@GOTPCREL(%rip), %rax
	movq	(%rax), %rdi
	movb	$0, %al
	callq	_fprintf
	movl	$2, %edi
	movl	%eax, -40(%rbp)         ## 4-byte Spill
	callq	_exit
LBB0_4:
	leaq	L_.str2(%rip), %rdi
	movsd	-24(%rbp), %xmm0
	movsd	-32(%rbp), %xmm1
	movb	$2, %al
	callq	_printf
	movl	$0, %ecx
	movl	%eax, -44(%rbp)         ## 4-byte Spill
	movl	%ecx, %eax
	addq	$48, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"Usage: %s x\n"

L_.str1:                                ## @.str1
	.asciz	"Cannot handle complex roots\n"

L_.str2:                                ## @.str2
	.asciz	"square root of %f = %f\n"


.subsections_via_symbols
