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
    *stack = current->next;
    
    symbol_table_free(current->table);
    free(current);
}

void symbol_stack_free(symbol_stack_t **stack) {
    while (*stack != NULL) {
        symbol_stack_pop(stack);
    }
}

symbol_table_content_t *symbol_stack_find(symbol_stack_t **stack, char *key) {
    symbol_stack_t *current = *stack;

    while (current) {
        symbol_table_entry_t *entry = symbol_table_find(current->table, key);
        if(!entry) {
            current = current->next;
            continue;
        }
        symbol_table_content_t *content = entry->content;
        if (content) {
            return content;
        }
        current = current->next;
    }
    
    return NULL;
}

void symbol_stack_insert_at_bottom(symbol_stack_t **stack, char *key, symbol_table_content_t *content) {
    if (*stack == NULL) {
        return;
    }

    symbol_stack_t *current = *stack;
    while (current->next != NULL) {
        current = current->next;
    }

    symbol_table_insert(current->table, key, content);
}
