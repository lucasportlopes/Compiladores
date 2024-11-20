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

    free(table); // Libera a tabela
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

symbol_table_entry_t *symbol_table_find(symbol_table_t *table, const char *key);