#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "code_generation.h"
#include "instructions.h"

static int tmp_counter = 0;
static int label_counter = 0;

char *generate_temp() {
  char *tmp = malloc(16 * sizeof(char));
  sprintf(tmp, "r%d", tmp_counter++);
  return tmp;
}

char *generate_label() {
  char *label = malloc(16 * sizeof(char));
  sprintf(label, "L%d", label_counter++);
  return label;
}

ILOCOperation *iloc_operation_create(char *opcode, char *source1, char *source2, char *source3, char *label) {
    ILOCOperation *operation = malloc(sizeof(ILOCOperation));

    if (operation == NULL) {
        fprintf(stderr, "Erro ao alocar memória para a operação ILOC\n");
        exit(EXIT_FAILURE);
    }

    operation->opcode = strdup(opcode);
    operation->source1 = source1 ? strdup(source1) : NULL;
    operation->source2 = source2 ? strdup(source2) : NULL;
    operation->source3 = source3 ? strdup(source3) : NULL;
    operation->label = label ? strdup(label) : NULL;
    
    return operation;
}

ILOCOperationList *iloc_list_create_node(ILOCOperation *operation) {
    ILOCOperationList *operation_list = malloc(sizeof(ILOCOperationList));

    if (operation_list == NULL) {
        fprintf(stderr, "Erro ao alocar memória para a lista de operações ILOC\n");
        exit(EXIT_FAILURE);
    }

    operation_list->operation = operation;
    operation_list->next = NULL;

    return operation_list;
}

void iloc_list_destroy(ILOCOperationList *operation_list) {
    ILOCOperationList *current_list = operation_list;
    ILOCOperationList *next_list = NULL;

    while (current_list != NULL) {
        next_list = current_list->next;
        free(current_list->operation->opcode);
        free(current_list->operation->source1);
        free(current_list->operation->source2);
        free(current_list->operation->source3);
        free(current_list->operation->label);
        free(current_list->operation);
        free(current_list);
        current_list = next_list;
    }
}

ILOCOperationList *iloc_list_concat(ILOCOperationList *list1, ILOCOperationList *list2) {
    if (list1 == NULL) {
        return list2;
    }

    if (list2 == NULL) {
        return list1;
    }

    ILOCOperationList *result = list1;

    ILOCOperationList *current = list1;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = list2;

    return result;
}

void iloc_list_display(ILOCOperationList *operation_list) {
    ILOCOperationList *current_list = operation_list;

    while (current_list != NULL) {
        if (current_list->operation->label != NULL) {
            printf("%s:\n", current_list->operation->label);
        }

        if (strcmp(current_list->operation->opcode, ADD) == 0 || 
            strcmp(current_list->operation->opcode, SUB) == 0 || 
            strcmp(current_list->operation->opcode, MULT) == 0 || 
            strcmp(current_list->operation->opcode, DIV) == 0 || 
            strcmp(current_list->operation->opcode, ADDI) == 0 || 
            strcmp(current_list->operation->opcode, SUBI) == 0 || 
            strcmp(current_list->operation->opcode, RSUBI) == 0 || 
            strcmp(current_list->operation->opcode, MULTI) == 0 || 
            strcmp(current_list->operation->opcode, DIVI) == 0 || 
            strcmp(current_list->operation->opcode, RDIVI) == 0 || 
            strcmp(current_list->operation->opcode, LSHIFT) == 0 || 
            strcmp(current_list->operation->opcode, LSHIFTI) == 0 || 
            strcmp(current_list->operation->opcode, RSHIFT) == 0 || 
            strcmp(current_list->operation->opcode, RSHIFTI) == 0 || 
            strcmp(current_list->operation->opcode, AND) == 0 || 
            strcmp(current_list->operation->opcode, ANDI) == 0 || 
            strcmp(current_list->operation->opcode, OR) == 0 || 
            strcmp(current_list->operation->opcode, ORI) == 0 || 
            strcmp(current_list->operation->opcode, XOR) == 0 || 
            strcmp(current_list->operation->opcode, XORI) == 0 ||
            strcmp(current_list->operation->opcode, CMP_LT) == 0 || 
            strcmp(current_list->operation->opcode, CMP_LE) == 0 || 
            strcmp(current_list->operation->opcode, CMP_EQ) == 0 || 
            strcmp(current_list->operation->opcode, CMP_GE) == 0 || 
            strcmp(current_list->operation->opcode, CMP_GT) == 0 || 
            strcmp(current_list->operation->opcode, CMP_NE) == 0 ||
            strcmp(current_list->operation->opcode, LOADAI) == 0 || 
            strcmp(current_list->operation->opcode, LOADA0) == 0 ||
            strcmp(current_list->operation->opcode, CLOADAI) == 0 || 
            strcmp(current_list->operation->opcode, CLOADA0) == 0) {
            printf("%s %s, %s => %s\n", current_list->operation->opcode, current_list->operation->source1, current_list->operation->source2, current_list->operation->source3);
        } else if (
            strcmp(current_list->operation->opcode, LOADI) == 0 || 
            strcmp(current_list->operation->opcode, LOAD) == 0 || 
            strcmp(current_list->operation->opcode, CLOAD) == 0 || 
            strcmp(current_list->operation->opcode, STORE) == 0 || 
            strcmp(current_list->operation->opcode, CSTORE) == 0 || 
            strcmp(current_list->operation->opcode, I2I) == 0 || 
            strcmp(current_list->operation->opcode, C2C) == 0 || 
            strcmp(current_list->operation->opcode, C2I) == 0 || 
            strcmp(current_list->operation->opcode, I2C) == 0) {
            printf("%s %s => %s\n", current_list->operation->opcode, current_list->operation->source1, current_list->operation->source2);
        } else if (
            strcmp(current_list->operation->opcode, STOREAI) == 0 || 
            strcmp(current_list->operation->opcode, STOREAO) == 0 || 
            strcmp(current_list->operation->opcode, CSTOREAI) == 0 || 
            strcmp(current_list->operation->opcode, CSTOREAO) == 0 ||
            strcmp(current_list->operation->opcode, CBR) == 0) {
            printf("%s %s => %s, %s\n", current_list->operation->opcode, current_list->operation->source1, current_list->operation->source2, current_list->operation->source3);
        } else if (
            strcmp(current_list->operation->opcode, JUMPI) == 0 || 
            strcmp(current_list->operation->opcode, JUMP) == 0) {
            printf("%s => %s\n", current_list->operation->opcode, current_list->operation->source1);
        }

        current_list = current_list->next;
    }
}

const char* map_register(const char* iloc_register) {
    if (strcmp(iloc_register, "r0") == 0) return "%rax";
    if (strcmp(iloc_register, "r1") == 0) return "%rbx";
    if (strcmp(iloc_register, "r2") == 0) return "%rcx";
    if (strcmp(iloc_register, "r3") == 0) return "%rdx";
    if (strcmp(iloc_register, "r4") == 0) return "%rsi";
    if (strcmp(iloc_register, "r5") == 0) return "%rdi";
    return iloc_register; 
}

void asm_list_display(ILOCOperationList *operation_list) {
    ILOCOperationList *current_list = operation_list;

    printf("    .globl main\n");
    printf("    .type main, @function\n");
    printf("main:\n");
    printf(".LFB0:\n");
    printf("    .cfi_startproc\n");
    printf("    pushq %rbp\n");
    printf("    .cfi_def_cfa_offset 16\n");
    printf("    .cfi_offset 6, -16\n");
    printf("    movq %rsp, %rbp\n");
    printf("    .cfi_def_cfa_register 6\n");
    // printf("    movq %rsp, %rbp\n");
    // printf("    subq $16, %rsp\n");  

    while (current_list != NULL) {
        if (current_list->operation->label != NULL) {
            printf(".%s:\n", current_list->operation->label);
        }

        const char *src1 = current_list->operation->source1 ? map_register(current_list->operation->source1) : NULL;
        const char *src2 = current_list->operation->source2 ? map_register(current_list->operation->source2) : NULL;
        const char *dest = current_list->operation->source3 ? map_register(current_list->operation->source3) : NULL;

        if (strcmp(current_list->operation->opcode, LOADI) == 0) {
            printf("    movq $%s, %s\n", src1, src2);
            // printf("    movq $%s, -8(%%rbp)\n", src1);
        } else if(strcmp(current_list->operation->opcode, ADD) == 0) {
            printf("    movq %s, %%rax\n", src1);
            printf("    addq %s, %%rax\n", src2);
            printf("    movq %%rax, %s\n", dest);
            // printf("    movq -8(%%rbp), %%rax\n");
            // printf("    addq %s, %%rax\n");
            // printf("    movq %%rax, -8(%%rbp)\n");
        } else if(strcmp(current_list->operation->opcode, SUB) == 0) {
            printf("    movq %s, %%rax\n", src1);
            printf("    subq %s, %%rax\n", src2);
            printf("    movq %%rax, %s\n", dest);
        } else if(strcmp(current_list->operation->opcode, MULT) == 0) {
            printf("    movq %s, %%rax\n", src1);
            printf("    imulq %s\n", src2);
            printf("    movq %%rax, %s\n", dest);
        } else if(strcmp(current_list->operation->opcode, DIV) == 0) {
            printf("    movq %s, %%rax\n", src1);
            printf("    cqo\n");
            printf("    idivq %s\n", src2);
            printf("    movq %%rax, %s\n", dest);
        } else if(strcmp(current_list->operation->opcode, CMP_LT) == 0) {
            printf("    movq %s, %%rax\n", src1);
            printf("    cmpq %s, %%rax\n", src2);
            printf("    setl %%al\n");
            printf("    movzbl %%al, %s\n", dest);
        } else if(strcmp(current_list->operation->opcode, CMP_EQ) == 0) {
            printf("    movq %s, %%rax\n", src1);
            printf("    cmpq %s, %%rax\n", src2);
            printf("    sete %%al\n");
            printf("    movzbl %%al, %s\n", dest);
        } else if(strcmp(current_list->operation->opcode, CBR) == 0) {
            printf("    cmpq $0, %s\n", src1);
            printf("    jne .%s\n", src2);
            printf("    jmp .%s\n", dest);
        } else if(strcmp(current_list->operation->opcode, CMP_GT) == 0) {
            printf("    movq %s, %%rax\n", src1);
            printf("    cmpq %s, %%rax\n", src2);
            printf("    setg %%al\n");
            printf("    movzbl %%al, %s\n", dest);
        } else if(strcmp(current_list->operation->opcode, CMP_GE) == 0) {
            printf("    movq %s, %%rax\n", src1);
            printf("    cmpq %s, %%rax\n", src2);
            printf("    setge %%al\n");
            printf("    movzbl %%al, %s\n", dest);
        } else if(strcmp(current_list->operation->opcode, CMP_LE) == 0) {
            printf("    movq %s, %%rax\n", src1);
            printf("    cmpq %s, %%rax\n", src2);
            printf("    setle %%al\n");
            printf("    movzbl %%al, %s\n", dest);
        } else if(strcmp(current_list->operation->opcode, CMP_NE) == 0) {
            printf("    movq %s, %%rax\n", src1);
            printf("    cmpq %s, %%rax\n", src2);
            printf("    setne %%al\n");
            printf("    movzbl %%al, %s\n", dest);
        } else if(strcmp(current_list->operation->opcode, JUMPI) == 0) {
            printf("    jmp .%s\n", current_list->operation->source1);
        } else if(strcmp(current_list->operation->opcode, OR) == 0) {
            printf("    movq %s, %%rax\n", src1);
            printf("    orq %s, %%rax\n", src2);
            printf("    movq %%rax, %s\n", dest);
        } else if(strcmp(current_list->operation->opcode, AND) == 0) {
            printf("    movq %s, %%rax\n", src1);
            printf("    andq %s, %%rax\n", src2);
            printf("    movq %%rax, %s\n", dest);
        } else if (strcmp(current_list->operation->opcode, STOREAI) == 0) {
            printf("    movq %s, -%s(%%rbp)\n", src1, current_list->operation->source3);
            // printf("    movq %s, -%s(%%rbp)\n", src1, current_list->operation->source2);
        } else if (strcmp(current_list->operation->opcode, LOADAI) == 0) {
            // printf("    movq -%s(%%rbp), %s\n", src1, dest);
            printf("    movq -%s(%%rbp), %s\n", src2, dest);
            // printf("    movq -%s(%%rbp), %s\n", src1, dest);
        } 

        current_list = current_list->next;
    }

    // printf("    movq %rbp, %rsp\n");
    printf("    popq %rbp\n");
    printf("    .cfi_def_cfa 7, 8\n");
    printf("    ret\n");
    printf("    .cfi_endproc\n");
    printf(".LFE0:\n");
    printf("    .size main, .-main\n");
    printf("    .section .note.GNU-stack,\"\",@progbits\n");
}