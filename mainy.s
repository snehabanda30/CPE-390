.globl main
main:
    mov $0xDEADBEEF1234567, %rax
	mov $0xABBAF0BB0BBE98D, %rbx

    mov %rax, %rcx
	and %rbx, %rcx

    mov %rax, %rdx
	or %rbx, %rdx

    mov %rax, %rsi
	xor %rbx, %rsi
	ret
# rax =  0xdeadbeef1234567   1002855686337676647 
# rbx =  0xabbaf0bb0bbe98d   773404225768778125 
# rcx =  0x8aa8b0ab0234105   624464376365269253 
# rdx =  0xffbffeff1bbedef   1151795535741185519
# rsi =  0x75174e54198acea   527331159375916266    
