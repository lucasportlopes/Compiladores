#ifndef _SYMBOL_STACK_H_
#define _SYMBOL_STACK_H_

#include "symbol_table.h"

typedef struct symbol_stack_t {
    symbol_table_t *table;
    struct symbol_stack_t *next;
} symbol_stack_t;

symbol_stack_t *symbol_stack_create(symbol_table_t *table);

void symbol_stack_free(symbol_stack_t *stack);

void symbol_stack_push(symbol_stack_t **stack, symbol_table_t *table);

void symbol_stack_pop(symbol_stack_t **stack);

symbol_stack_t *symbol_stack_find(char *key);

#endif // _SYMBOL_TABLE_H_
