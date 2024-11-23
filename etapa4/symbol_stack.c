#include "symbol_table.h"
#include "symbol_stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

symbol_stack_t *symbol_stack_create(symbol_table_t *table) {
    symbol_stack_t *symbol_stack = malloc(sizeof(symbol_stack_t));

    if (!symbol_stack) {
        fprintf(stderr, "Erro ao alocar memória para a pilha de símbolos.\n");
        exit(EXIT_FAILURE);
    }
    
    symbol_stack->table = table;
    symbol_stack->next = NULL;
    return symbol_stack;
}

void symbol_stack_push(symbol_stack_t **stack, symbol_table_t *table) {
    symbol_stack_t *symbol_stack = symbol_stack_create(table);
    symbol_stack->next = *stack;
    *stack = symbol_stack;
}

void symbol_stack_pop(symbol_stack_t **stack) {
    if (*stack == NULL) {
        return;
    }
    symbol_stack_t *current = *stack;
    symbol_table_t *table = current->table;
    *stack = (*stack)->next;
    
    symbol_table_free(table);
    free(current);
}

symbol_stack_t *symbol_stack_find(char *key);