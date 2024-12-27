    .globl main
    .type main, @function
main:
.LFB0:
    .cfi_startproc
    pushq %rbp
    movq -rfp(%rbp), %rbx
    movq $3, %rcx
    movq %rbx, %rax
    addq %rcx, %rax
    movq %rax, %rdx
    movq %rdx, -rfp(%rbp)
    pop %rbp
    ret
    .cfi_endproc
.LFE0:
    .size main, .-main
    .section .note.GNU-stack,"",@progbits
