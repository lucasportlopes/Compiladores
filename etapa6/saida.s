    .globl main
    .type main, @function
main:
.LFB0:
    .cfi_startproc
    pushq %rbp
    .cfi_def_cfa_offset 16
    .cfi_offset 6, -16
    movq %rsp, %rbp
    .cfi_def_cfa_register 6
    subq $32, %rsp
    movl $3, %eax
    movl %eax, -12(%rbp)
    movl $1, %ecx
    movl $1, %edx
    movl %ecx, %eax
    andl %edx, %eax
    movl %eax, %esi
    movl $0, %r9d
    movl %esi, %eax
    cmpl %r9d, %eax
    setne %al
    movzbl %al, %r10d
    cmpl $0, %esi
    jne .L0
    jmp .L1
.L0:
    movl $1, %edi
    movl %edi, -12(%rbp)
.L1:
    movl -12(%rbp), %r11d
    movl $4, %r12d
    movl %r11d, %eax
    addl %r12d, %eax
    movl %eax, %r13d
    movl %r13d, -16(%rbp)
    leave
    ret
    .cfi_endproc
.LFE0:
    .size main, .-main
    .section .note.GNU-stack,"",@progbits
