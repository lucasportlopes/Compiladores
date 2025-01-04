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
    movl $2, %eax
    movl %eax, -0(%rbp)
    movl $1, %ecx
    movl %ecx, -4(%rbp)
    movl $1, %esi
    movl $1, %edi
    movl %esi, %eax
    andl %edi, %eax
    movl %eax, %r8d
    cmpl $0, %r8d
    jne .L0
    jmp .L1
.L0:
    movl -0(%rbp), %r9d
    movl $100, %r10d
    movl %r9d, %eax
    addl %r10d, %eax
    movl %eax, %r11d
    movl %r11d, -0(%rbp)
    jmp .L2
.L1:
    movl -0(%rbp), %r13d
    movl $200, %r14d
    movl %r13d, %eax
    addl %r14d, %eax
    movl %eax, %r15d
    movl %r15d, -0(%rbp)
.L2:
    movl -0(%rbp), %eax
    leave
    ret
    .cfi_endproc
.LFE0:
    .size main, .-main
    .section .note.GNU-stack,"",@progbits
