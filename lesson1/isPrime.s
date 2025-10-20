	.file	"isPrime.cpp"
# GNU C++17 (Ubuntu 13.3.0-6ubuntu2~24.04) version 13.3.0 (x86_64-linux-gnu)
#	compiled by GNU C version 13.3.0, GMP version 6.3.0, MPFR version 4.2.1, MPC version 1.3.1, isl version isl-0.26-GMP

# GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
# options passed: -mtune=generic -march=x86-64 -std=c++17 -fasynchronous-unwind-tables -fstack-protector-strong -fstack-clash-protection -fcf-protection
	.text
#APP
	.globl _ZSt21ios_base_library_initv
#NO_APP
	.globl	_Z8is_primei
	.type	_Z8is_primei, @function
_Z8is_primei:
.LFB2566:
	.cfi_startproc
	endbr64	
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$32, %rsp	#,
	movl	%edi, -20(%rbp)	# number, number
# isPrime.cpp:18:   if (number < 2) {
	cmpl	$1, -20(%rbp)	#, number
	jg	.L2	#,
# isPrime.cpp:19:     return false;
	movl	$0, %eax	#, _4
	jmp	.L3	#
.L2:
# isPrime.cpp:22:   double sqrtNumber = std::sqrt(number);
	movl	-20(%rbp), %eax	# number, tmp86
	movl	%eax, %edi	# tmp86,
	call	_ZSt4sqrtIiEN9__gnu_cxx11__enable_ifIXsrSt12__is_integerIT_E7__valueEdE6__typeES3_	#
	movq	%xmm0, %rax	#, tmp87
	movq	%rax, -8(%rbp)	# tmp87, sqrtNumber
# isPrime.cpp:23:   for (int i = 2; i <= sqrtNumber; i++) {
	movl	$2, -12(%rbp)	#, i
# isPrime.cpp:23:   for (int i = 2; i <= sqrtNumber; i++) {
	jmp	.L4	#
.L6:
# isPrime.cpp:24:     if (number % i == 0) {
	movl	-20(%rbp), %eax	# number, tmp88
	cltd
	idivl	-12(%rbp)	# i
	movl	%edx, %eax	# tmp89, _1
# isPrime.cpp:24:     if (number % i == 0) {
	testl	%eax, %eax	# _1
	jne	.L5	#,
# isPrime.cpp:25:       return false; // Found a factor, so it's not prime
	movl	$0, %eax	#, _4
	jmp	.L3	#
.L5:
# isPrime.cpp:23:   for (int i = 2; i <= sqrtNumber; i++) {
	addl	$1, -12(%rbp)	#, i
.L4:
# isPrime.cpp:23:   for (int i = 2; i <= sqrtNumber; i++) {
	pxor	%xmm1, %xmm1	# _2
	cvtsi2sdl	-12(%rbp), %xmm1	# i, _2
	movsd	-8(%rbp), %xmm0	# sqrtNumber, tmp91
	comisd	%xmm1, %xmm0	# _2, tmp91
	jnb	.L6	#,
# isPrime.cpp:28:   return true; // No factors found, so it is prime
	movl	$1, %eax	#, _4
.L3:
# isPrime.cpp:29: }
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE2566:
	.size	_Z8is_primei, .-_Z8is_primei
	.section	.rodata
.LC0:
	.string	"Usage: "
.LC1:
	.string	" <integer>"
.LC2:
	.string	"yes"
.LC3:
	.string	"no"
	.text
	.globl	main
	.type	main, @function
main:
.LFB2567:
	.cfi_startproc
	endbr64	
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$32, %rsp	#,
	movl	%edi, -20(%rbp)	# argsSize, argsSize
	movq	%rsi, -32(%rbp)	# args, args
# isPrime.cpp:56:   if (argsSize < 2) {
	cmpl	$1, -20(%rbp)	#, argsSize
	jg	.L8	#,
# isPrime.cpp:57:     std::cerr << "Usage: " << args[0] << " <integer>" << std::endl;
	leaq	.LC0(%rip), %rax	#, tmp93
	movq	%rax, %rsi	# tmp93,
	leaq	_ZSt4cerr(%rip), %rax	#, tmp94
	movq	%rax, %rdi	# tmp94,
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT	#
	movq	%rax, %rdx	#, _1
# isPrime.cpp:57:     std::cerr << "Usage: " << args[0] << " <integer>" << std::endl;
	movq	-32(%rbp), %rax	# args, tmp95
	movq	(%rax), %rax	# *args_13(D), _2
	movq	%rax, %rsi	# _2,
	movq	%rdx, %rdi	# _1,
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT	#
	movq	%rax, %rdx	#, _3
# isPrime.cpp:57:     std::cerr << "Usage: " << args[0] << " <integer>" << std::endl;
	leaq	.LC1(%rip), %rax	#, tmp96
	movq	%rax, %rsi	# tmp96,
	movq	%rdx, %rdi	# _3,
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT	#
# isPrime.cpp:57:     std::cerr << "Usage: " << args[0] << " <integer>" << std::endl;
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rdx	#, tmp98
	movq	%rdx, %rsi	# tmp97,
	movq	%rax, %rdi	# _4,
	call	_ZNSolsEPFRSoS_E@PLT	#
# isPrime.cpp:58:     return 1; // Return 0 to indicate an error code
	movl	$1, %eax	#, _9
	jmp	.L9	#
.L8:
# isPrime.cpp:61:   int number = std::atoi(args[1]);
	movq	-32(%rbp), %rax	# args, tmp99
	addq	$8, %rax	#, _5
# isPrime.cpp:61:   int number = std::atoi(args[1]);
	movq	(%rax), %rax	# *_5, _6
	movq	%rax, %rdi	# _6,
	call	atoi@PLT	#
	movl	%eax, -4(%rbp)	# tmp100, number
# isPrime.cpp:63:   if (is_prime(number)/* call the function is_prime on number */) {
	movl	-4(%rbp), %eax	# number, tmp101
	movl	%eax, %edi	# tmp101,
	call	_Z8is_primei	#
# isPrime.cpp:63:   if (is_prime(number)/* call the function is_prime on number */) {
	testb	%al, %al	# _17
	je	.L10	#,
# isPrime.cpp:64:     std::cout << "yes" << std::endl;
	leaq	.LC2(%rip), %rax	#, tmp102
	movq	%rax, %rsi	# tmp102,
	leaq	_ZSt4cout(%rip), %rax	#, tmp103
	movq	%rax, %rdi	# tmp103,
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT	#
# isPrime.cpp:64:     std::cout << "yes" << std::endl;
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rdx	#, tmp105
	movq	%rdx, %rsi	# tmp104,
	movq	%rax, %rdi	# _7,
	call	_ZNSolsEPFRSoS_E@PLT	#
	jmp	.L11	#
.L10:
# isPrime.cpp:66:     std::cout << "no" << std::endl;
	leaq	.LC3(%rip), %rax	#, tmp106
	movq	%rax, %rsi	# tmp106,
	leaq	_ZSt4cout(%rip), %rax	#, tmp107
	movq	%rax, %rdi	# tmp107,
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT	#
# isPrime.cpp:66:     std::cout << "no" << std::endl;
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rdx	#, tmp109
	movq	%rdx, %rsi	# tmp108,
	movq	%rax, %rdi	# _8,
	call	_ZNSolsEPFRSoS_E@PLT	#
.L11:
# isPrime.cpp:68:   return 0; // Return 0 to indicate successful execution
	movl	$0, %eax	#, _9
.L9:
# isPrime.cpp:69: }
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE2567:
	.size	main, .-main
	.section	.text._ZSt4sqrtIiEN9__gnu_cxx11__enable_ifIXsrSt12__is_integerIT_E7__valueEdE6__typeES3_,"axG",@progbits,_ZSt4sqrtIiEN9__gnu_cxx11__enable_ifIXsrSt12__is_integerIT_E7__valueEdE6__typeES3_,comdat
	.weak	_ZSt4sqrtIiEN9__gnu_cxx11__enable_ifIXsrSt12__is_integerIT_E7__valueEdE6__typeES3_
	.type	_ZSt4sqrtIiEN9__gnu_cxx11__enable_ifIXsrSt12__is_integerIT_E7__valueEdE6__typeES3_, @function
_ZSt4sqrtIiEN9__gnu_cxx11__enable_ifIXsrSt12__is_integerIT_E7__valueEdE6__typeES3_:
.LFB2867:
	.cfi_startproc
	endbr64	
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$16, %rsp	#,
	movl	%edi, -4(%rbp)	# __x, __x
# /usr/include/c++/13/cmath:451:     { return __builtin_sqrt(__x); }
	pxor	%xmm1, %xmm1	# _1
	cvtsi2sdl	-4(%rbp), %xmm1	# __x, _1
	movq	%xmm1, %rax	# _1, _1
	movq	%rax, %xmm0	# _1,
	call	sqrt@PLT	#
# /usr/include/c++/13/cmath:451:     { return __builtin_sqrt(__x); }
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE2867:
	.size	_ZSt4sqrtIiEN9__gnu_cxx11__enable_ifIXsrSt12__is_integerIT_E7__valueEdE6__typeES3_, .-_ZSt4sqrtIiEN9__gnu_cxx11__enable_ifIXsrSt12__is_integerIT_E7__valueEdE6__typeES3_
	.section	.rodata
	.type	_ZNSt8__detail30__integer_to_chars_is_unsignedIjEE, @object
	.size	_ZNSt8__detail30__integer_to_chars_is_unsignedIjEE, 1
_ZNSt8__detail30__integer_to_chars_is_unsignedIjEE:
	.byte	1
	.type	_ZNSt8__detail30__integer_to_chars_is_unsignedImEE, @object
	.size	_ZNSt8__detail30__integer_to_chars_is_unsignedImEE, 1
_ZNSt8__detail30__integer_to_chars_is_unsignedImEE:
	.byte	1
	.type	_ZNSt8__detail30__integer_to_chars_is_unsignedIyEE, @object
	.size	_ZNSt8__detail30__integer_to_chars_is_unsignedIyEE, 1
_ZNSt8__detail30__integer_to_chars_is_unsignedIyEE:
	.byte	1
	.ident	"GCC: (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
