#include "symbol_table.h"
#include "symbol_stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

symbol_table_t *symbol_table_create(symbol_table_t *parent) {
    symbol_table_t *table = malloc(sizeof(symbol_table_t));
    if (!table) {
        fprintf(stderr, "Erro ao alocar memória para tabela de símbolos.\n");
        exit(EXIT_FAILURE);
    }
    table->first_entry = NULL;
    table->parent = parent;
    return table;
}

void symbol_table_free(symbol_table_t *table) {
    if (table == NULL) {
        return;
    }

    symbol_table_entry_t *current_entry = table->first_entry;
    while (current_entry) {
        symbol_table_entry_t *next_entry = current_entry->next;
        free(current_entry->key);
        free(current_entry->content);
        free(current_entry);
        current_entry = next_entry;
    }

    free(table);
}

symbol_table_content_t *create_content(int line, symbol_table_nature_t nature, symbol_table_type_t type, valor_lexico_t *value) {
    symbol_table_content_t *content = malloc(sizeof(symbol_table_content_t));
    content->line = line;
    content->nature = nature;
    content->type = type;
    content->value = value;
    return content;
}

void symbol_table_insert(symbol_table_t *table, char *key, symbol_table_content_t *content)
{
    // Cria uma nova entrada
    symbol_table_entry_t *new_entry = malloc(sizeof(symbol_table_entry_t));
    
    if (new_entry == NULL) {
        fprintf(stderr, "Erro ao alocar memória para nova entrada.\n");
        return;
    }

    new_entry->key = strdup(key); // Copia a chave
    if (new_entry->key == NULL) {
        fprintf(stderr, "Erro ao duplicar a chave.\n");
        free(new_entry);
        return;
    }

    new_entry->content = content; // Associa o conteúdo
    new_entry->next = NULL;       // A nova entrada será o último elemento

    // Insere na tabela
    if (table->first_entry == NULL) { // Caso a tabela esteja vazia
        table->first_entry = new_entry;
        return;
    }

    // Caso contrário, percorre até o final da lista
    symbol_table_entry_t *current = table->first_entry;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = new_entry; // Adiciona a nova entrada no final da lista
}

symbol_table_entry_t *symbol_table_find(symbol_table_t *table, const char *key) {
    if (table == NULL || key == NULL) {
        return NULL;
    }

    symbol_table_entry_t *entry = table->first_entry;

    while (entry != NULL) {
        if (strcmp(entry->key, key) == 0) {
            return entry;
        }
        entry = entry->next;
    }

    return NULL;
}

void open_scope(symbol_stack_t **stack) {
    symbol_table_t *table = symbol_table_create(NULL);

    if (*stack == NULL) {
        *stack = symbol_stack_create(table);
    } else {
        table->parent = (*stack)->table;
        symbol_stack_push(stack, table);
    }
}

void close_scope(symbol_stack_t **stack) {
    symbol_stack_pop(stack);
}

void semantic_error(int error_code, const char *identifier, int line) {
    if (error_code == ERR_UNDECLARED) {
        fprintf(stderr, "Semantic error (line %d): identifier '%s' not declared.\n", line, identifier);
    } else if (error_code == ERR_DECLARED) {
        fprintf(stderr, "Semantic error (line %d): identifier '%s' already declared in the current scope.\n", line, identifier);
    } else if (error_code == ERR_VARIABLE) {
        fprintf(stderr, "Semantic error (line %d): identifier '%s' declared as a variable but used as a function.\n", line, identifier);
    } else if (error_code == ERR_FUNCTION) {
        fprintf(stderr, "Semantic error (line %d): identifier '%s' declared as a function but used as a variable.\n", line, identifier);
    } else {
        fprintf(stderr, "Semantic error (line %d): unknown error for identifier '%s'.\n", line, identifier);
    }

    exit(error_code);
}

symbol_table_type_t infer_type(symbol_table_type_t type_one, symbol_table_type_t type_two) {
    printf("type_one: %d, type_two: %d\n", type_one, type_two);
    if (type_one == SYMBOL_TYPE_INT && type_two == SYMBOL_TYPE_INT) {
        return SYMBOL_TYPE_INT;
    } else if (type_one == SYMBOL_TYPE_FLOAT && type_two == SYMBOL_TYPE_FLOAT || 
            type_one == SYMBOL_TYPE_INT && type_two == SYMBOL_TYPE_FLOAT || 
            type_one == SYMBOL_TYPE_FLOAT && type_two == SYMBOL_TYPE_INT) {
        return SYMBOL_TYPE_FLOAT;
    }
}
