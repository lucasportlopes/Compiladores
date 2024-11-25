#ifndef _SYMBOL_STACK_H_
#define _SYMBOL_STACK_H_

#include "symbol_table.h"
#include "types.h"

symbol_stack_t *symbol_stack_create(symbol_table_t *table);

void symbol_stack_free(symbol_stack_t *stack);

void symbol_stack_push(symbol_stack_t **stack, symbol_table_t *table);

void symbol_stack_pop(symbol_stack_t **stack);

symbol_table_content_t *symbol_stack_find(symbol_stack_t **stack, char *key);

void symbol_stack_insert_at_bottom(symbol_stack_t **stack, char *key, symbol_table_content_t *content);

#endif // _SYMBOL_TABLE_H_
