    .globl main
main:
    mov	$5, %rax
	mov	$7, %rbx
    mov	$9, %rcx

    lea (%rax,%rbx),%rdx

    mov %rax, %rsi 
    imul %rcx, %rsi 

    mov %rbx, %rdi 
    sub %rax, %rdi 

    mov $0, %rdx 
    mov %rsi,%rax 
    mov %rdi,%rcx 
    div %rcx 

	ret
    
	
