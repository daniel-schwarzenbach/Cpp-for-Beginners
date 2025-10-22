	.file	"isPrime.cpp"
 # GNU C++17 (x86_64-posix-seh-rev0, Built by MinGW-Builds project) version 15.2.0 (x86_64-w64-mingw32)
 #	compiled by GNU C version 15.2.0, GMP version 6.2.1, MPFR version 4.1.0, MPC version 1.2.1, isl version isl-0.27-GMP

 # GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
 # options passed: -mtune=core2 -march=nocona -O0 -std=c++17
	.text
	.globl	_Z8is_primei
	.def	_Z8is_primei;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z8is_primei
_Z8is_primei:
.LFB2791:
	pushq	%rbp	 #
	.seh_pushreg	%rbp
	movq	%rsp, %rbp	 #,
	.seh_setframe	%rbp, 0
	subq	$48, %rsp	 #,
	.seh_stackalloc	48
	.seh_endprologue
	movl	%ecx, 16(%rbp)	 # number, number
 # .\lesson1\isPrime.cpp:18:   if (number < 2) {
	cmpl	$1, 16(%rbp)	 #, number
	jg	.L2	 #,
 # .\lesson1\isPrime.cpp:19:     return false;
	movl	$0, %eax	 #, _4
	jmp	.L3	 #
.L2:
 # .\lesson1\isPrime.cpp:22:   double sqrtNumber = std::sqrt(number);
	movl	16(%rbp), %eax	 # number, tmp102
	movl	%eax, %ecx	 # tmp102,
	call	_ZSt4sqrtIiEN9__gnu_cxx11__enable_ifIXsrSt12__is_integerIT_E7__valueEdE6__typeES3_	 #
	movq	%xmm0, %rax	 #, tmp103
	movq	%rax, -16(%rbp)	 # tmp103, sqrtNumber
 # .\lesson1\isPrime.cpp:23:   for (int i = 2; i <= sqrtNumber; i++) {
	movl	$2, -4(%rbp)	 #, i
 # .\lesson1\isPrime.cpp:23:   for (int i = 2; i <= sqrtNumber; i++) {
	jmp	.L4	 #
.L6:
 # .\lesson1\isPrime.cpp:24:     if (number % i == 0) {
	movl	16(%rbp), %eax	 # number, tmp104
	cltd
	idivl	-4(%rbp)	 # i
	movl	%edx, %eax	 # _1, _1
 # .\lesson1\isPrime.cpp:24:     if (number % i == 0) {
	testl	%eax, %eax	 # _1
	jne	.L5	 #,
 # .\lesson1\isPrime.cpp:25:       return false; // Found a factor, so it's not prime
	movl	$0, %eax	 #, _4
	jmp	.L3	 #
.L5:
 # .\lesson1\isPrime.cpp:23:   for (int i = 2; i <= sqrtNumber; i++) {
	addl	$1, -4(%rbp)	 #, i
.L4:
 # .\lesson1\isPrime.cpp:23:   for (int i = 2; i <= sqrtNumber; i++) {
	pxor	%xmm1, %xmm1	 # _2
	cvtsi2sdl	-4(%rbp), %xmm1	 # i, _2
	movsd	-16(%rbp), %xmm0	 # sqrtNumber, tmp107
	comisd	%xmm1, %xmm0	 # _2, tmp107
	jnb	.L6	 #,
 # .\lesson1\isPrime.cpp:28:   return true; // No factors found, so it is prime
	movl	$1, %eax	 #, _4
.L3:
 # .\lesson1\isPrime.cpp:29: }
	addq	$48, %rsp	 #,
	popq	%rbp	 #
	ret	
	.seh_endproc
	.section .rdata,"dr"
.LC0:
	.ascii "Usage: \0"
.LC1:
	.ascii " <integer>\0"
.LC2:
	.ascii "yes\0"
.LC3:
	.ascii "no\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB2792:
	pushq	%rbp	 #
	.seh_pushreg	%rbp
	movq	%rsp, %rbp	 #,
	.seh_setframe	%rbp, 0
	subq	$48, %rsp	 #,
	.seh_stackalloc	48
	.seh_endprologue
	movl	%ecx, 16(%rbp)	 # argsSize, argsSize
	movq	%rdx, 24(%rbp)	 # args, args
 # .\lesson1\isPrime.cpp:54: int main(int argsSize, char *args[]) {
	call	__main	 #
 # .\lesson1\isPrime.cpp:56:   if (argsSize < 2) {
	cmpl	$1, 16(%rbp)	 #, argsSize
	jg	.L8	 #,
 # .\lesson1\isPrime.cpp:57:     std::cerr << "Usage: " << args[0] << " <integer>" << std::endl;
	leaq	.LC0(%rip), %rdx	 #, tmp109
	movq	.refptr._ZSt4cerr(%rip), %rax	 #, tmp110
	movq	%rax, %rcx	 # tmp110,
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc	 #
	movq	%rax, %rcx	 #, _1
 # .\lesson1\isPrime.cpp:57:     std::cerr << "Usage: " << args[0] << " <integer>" << std::endl;
	movq	24(%rbp), %rax	 # args, tmp111
	movq	(%rax), %rax	 # *args_13(D), _2
	movq	%rax, %rdx	 # _2,
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc	 #
	movq	%rax, %rcx	 #, _3
 # .\lesson1\isPrime.cpp:57:     std::cerr << "Usage: " << args[0] << " <integer>" << std::endl;
	leaq	.LC1(%rip), %rax	 #, tmp112
	movq	%rax, %rdx	 # tmp112,
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc	 #
	movq	%rax, %rcx	 #, _4
 # .\lesson1\isPrime.cpp:57:     std::cerr << "Usage: " << args[0] << " <integer>" << std::endl;
	movq	.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_(%rip), %rax	 #, tmp113
	movq	%rax, %rdx	 # tmp113,
	call	_ZNSolsEPFRSoS_E	 #
 # .\lesson1\isPrime.cpp:58:     return 1; // Return 1 to indicate an error code
	movl	$1, %eax	 #, _9
	jmp	.L9	 #
.L8:
 # .\lesson1\isPrime.cpp:61:   int number = std::atoi(args[1]);
	movq	24(%rbp), %rax	 # args, tmp114
	addq	$8, %rax	 #, _5
 # .\lesson1\isPrime.cpp:61:   int number = std::atoi(args[1]);
	movq	(%rax), %rax	 # *_5, _6
	movq	%rax, %rcx	 # _6,
	call	atoi	 #
	movl	%eax, -4(%rbp)	 # tmp115, number
 # .\lesson1\isPrime.cpp:63:   if (is_prime(number) /* call the function is_prime on number */) {
	movl	-4(%rbp), %eax	 # number, tmp116
	movl	%eax, %ecx	 # tmp116,
	call	_Z8is_primei	 #
 # .\lesson1\isPrime.cpp:63:   if (is_prime(number) /* call the function is_prime on number */) {
	testb	%al, %al	 # _18
	je	.L10	 #,
 # .\lesson1\isPrime.cpp:64:     std::cout << "yes" << std::endl;
	leaq	.LC2(%rip), %rdx	 #, tmp117
	movq	.refptr._ZSt4cout(%rip), %rax	 #, tmp118
	movq	%rax, %rcx	 # tmp118,
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc	 #
	movq	%rax, %rcx	 #, _7
 # .\lesson1\isPrime.cpp:64:     std::cout << "yes" << std::endl;
	movq	.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_(%rip), %rax	 #, tmp119
	movq	%rax, %rdx	 # tmp119,
	call	_ZNSolsEPFRSoS_E	 #
	jmp	.L11	 #
.L10:
 # .\lesson1\isPrime.cpp:66:     std::cout << "no" << std::endl;
	leaq	.LC3(%rip), %rdx	 #, tmp120
	movq	.refptr._ZSt4cout(%rip), %rax	 #, tmp121
	movq	%rax, %rcx	 # tmp121,
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc	 #
	movq	%rax, %rcx	 #, _8
 # .\lesson1\isPrime.cpp:66:     std::cout << "no" << std::endl;
	movq	.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_(%rip), %rax	 #, tmp122
	movq	%rax, %rdx	 # tmp122,
	call	_ZNSolsEPFRSoS_E	 #
.L11:
 # .\lesson1\isPrime.cpp:68:   return 0; // Return 0 to indicate successful execution
	movl	$0, %eax	 #, _9
.L9:
 # .\lesson1\isPrime.cpp:69: }
	addq	$48, %rsp	 #,
	popq	%rbp	 #
	ret	
	.seh_endproc
	.section	.text$_ZSt4sqrtIiEN9__gnu_cxx11__enable_ifIXsrSt12__is_integerIT_E7__valueEdE6__typeES3_,"x"
	.linkonce discard
	.globl	_ZSt4sqrtIiEN9__gnu_cxx11__enable_ifIXsrSt12__is_integerIT_E7__valueEdE6__typeES3_
	.def	_ZSt4sqrtIiEN9__gnu_cxx11__enable_ifIXsrSt12__is_integerIT_E7__valueEdE6__typeES3_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZSt4sqrtIiEN9__gnu_cxx11__enable_ifIXsrSt12__is_integerIT_E7__valueEdE6__typeES3_
_ZSt4sqrtIiEN9__gnu_cxx11__enable_ifIXsrSt12__is_integerIT_E7__valueEdE6__typeES3_:
.LFB3114:
	pushq	%rbp	 #
	.seh_pushreg	%rbp
	movq	%rsp, %rbp	 #,
	.seh_setframe	%rbp, 0
	subq	$32, %rsp	 #,
	.seh_stackalloc	32
	.seh_endprologue
	movl	%ecx, 16(%rbp)	 # __x, __x
 # C:/ProgramData/mingw64/mingw64/lib/gcc/x86_64-w64-mingw32/15.2.0/include/c++/cmath:462:     { return __builtin_sqrt(__x); }
	pxor	%xmm1, %xmm1	 # _1
	cvtsi2sdl	16(%rbp), %xmm1	 # __x, _1
	movq	%xmm1, %rax	 # _1, _1
	movq	%rax, %xmm0	 # _1,
	call	sqrt	 #
 # C:/ProgramData/mingw64/mingw64/lib/gcc/x86_64-w64-mingw32/15.2.0/include/c++/cmath:462:     { return __builtin_sqrt(__x); }
	addq	$32, %rsp	 #,
	popq	%rbp	 #
	ret	
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.ident	"GCC: (x86_64-posix-seh-rev0, Built by MinGW-Builds project) 15.2.0"
	.def	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc;	.scl	2;	.type	32;	.endef
	.def	_ZNSolsEPFRSoS_E;	.scl	2;	.type	32;	.endef
	.def	atoi;	.scl	2;	.type	32;	.endef
	.def	sqrt;	.scl	2;	.type	32;	.endef
	.section	.rdata$.refptr._ZSt4cout, "dr"
	.p2align	3, 0
	.globl	.refptr._ZSt4cout
	.linkonce	discard
.refptr._ZSt4cout:
	.quad	_ZSt4cout
	.section	.rdata$.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, "dr"
	.p2align	3, 0
	.globl	.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	.linkonce	discard
.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_:
	.quad	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	.section	.rdata$.refptr._ZSt4cerr, "dr"
	.p2align	3, 0
	.globl	.refptr._ZSt4cerr
	.linkonce	discard
.refptr._ZSt4cerr:
	.quad	_ZSt4cerr
