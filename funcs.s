# write your asm code here
# Sneha Banda. I pledge I have abided by Stevens Honor Code.
.globl _Z5counti

_Z5counti: 

    mov $1, %rsi 
    cmp $0, %rcx 
    jle exit
    sub $3, %rcx
countuploop:

    add $3, %rsi 
    cmp %rcx, %rsi 
    jl countuploop 
    mov %rsi,%rax

exit:
    ret 

    .globl _Z5sumsqPKyj
_Z5sumsqPKyj:   
    xor %rax, %rax # sum = 0 
    cmp $0, %rdx
    jle sumsqout
 sumsqloop:
    mov (%rcx), %r9 
    imul %r9,%r9
    add %r9, %rax
    add $8, %rcx
    sub $1, %rdx
    jnz sumsqloop
 sumsqout: 
    ret

    .globl _Z4add1Pyj
_Z4add1Pyj:   
    cmp $0, %rdx
    jle add1out
 add1loop:
    xor %r8,%r8 
    mov (%rcx), %r8 
    add $1,%r8
    add $8, %rcx
    sub $1, %rdx
    jnz add1loop
    mov %r8,%rax

 add1out:
    mov %r8,%rax
    ret
   .globl _Z11replaceZeroy
_Z11replaceZeroy: 
    mov $0xFFFFF08F, %rdx
    and %rcx,%rdx
    mov %rdx,%rax 
    ret 


   .globl _Z10replaceOney
_Z10replaceOney: 
    mov $0x00000E70, %rdx
    or %rcx,%rdx
    mov %rdx,%rax 
    ret 

    .globl _Z7togglesy
_Z7togglesy: 
    mov $0x00000E70, %rdx
    xor %rcx,%rdx
    mov %rdx,%rax 
    ret 
    .globl _Z8replaceDy
_Z8replaceDy: 
    mov $0x0000000F, %rdx
    and %rcx,%rdx
    cmp $0x0000000D,%rdx 
    jne mored
    jmp oned
oned: 
    mov $0xFFFFFFFFFC,%rdx
    and %rdx,%rcx 
    ret
mored: 
    mov $0xFFFFFFFFFC,%rax
    rol $4,%rax 
    and %rax,%rcx 
    xor %rcx,%rdx
    mov %rdx,%rax
    ret

/* 
question 1: -------------------------- 19
question 2: --------------------------
102
81, 1, 4, 16,
question 3: --------------------------
6, 4, 7, 8, 5, 10,
question 4: --------------------------
Binary:0000000000000000000000000000000011110010111011001011000010001110
Hex: f2ecb08e
question 5: --------------------------
Binary: 0000000000000000000000000000000011110010111011001011111011111110
Hex: f2ecbefe
question 6: --------------------------
Binary: 0000000000000000000000000000000011110010111011001011010011001110
Hex: f2ecb4ce
question 7: --------------------------
Binary: 0000000000000000000010011000011101100101010000110010000111001001
Hex: 987654321c9

*/ 








   