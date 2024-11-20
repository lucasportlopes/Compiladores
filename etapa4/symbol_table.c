#include "symbol_table.h"
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
    table->parent = parent; // Define o escopo pai
    return table;
}

void symbol_table_free(symbol_table_t *table) {
    if (table == NULL) {
        return;
    }

    symbol_table_entry_t *entry = table->first_entry;
    while (entry) {
        symbol_table_entry_t *next = entry->next;
        free(entry->key);         // Libera o lexema
        free(entry->content);     // Libera o conteúdo associado
        free(entry);              // Libera a entrada
        entry = next;
    }

    free(table); // Libera a tabela em si
}