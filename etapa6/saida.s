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



    movq -12(%rbp), %rcx
    movq -16(%rbp), %rdx
    movq %rcx, %rax
    addq %rdx, %rax
    movq %rax, %rsi
    movq %rsi, -20(%rbp)



    
    popq %rbp
    .cfi_def_cfa 7, 8
    ret
    .cfi_endproc
.LFE0:
    .size main, .-main
    .section .note.GNU-stack,"",@progbits
