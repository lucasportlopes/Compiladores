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
    movl $4, %eax
    movl %eax, -16(%rbp)             
    movl -12(%rbp), %eax           
    movl -16(%rbp), %edx
    addl %edx, %eax           
    movl %eax, -20(%rbp)          
    movl -20(%rbp), %eax

    leave
    ret                           
    .cfi_endproc
.LFE0:
    .size main, .-main
    .section .note.GNU-stack,"",@progbits
