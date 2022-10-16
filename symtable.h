/**
 * Implementace překladače imperativního jazyka IFJ22
 *
 * @file symtable.h
 * @brief File containing definitions of structs and functions for the symbol hash table
 *
 * @author Matúš Ďurica (xduric06)
 * @author Ivan Mahút (xmahut01)
 * @author Dušan Slúka (xsluka00)
 * @author Gabriela Paganíková (xpagan00)
 */

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "murmurhash.h"
#include <stdbool.h>
#include <stdint.h>

#define SYMTAB_MAX_SIZE 256 // Max size of the symbol table - keep it in 2^n format!

/**
 * @brief Contains data types in strings, just for ease of use
 *
 */
typedef enum
{
    INT_T,
    FLOAT_T,
    STRING_T,
    BOOL_T
} Data_type;

/**
 * @brief Struct containg data of 1 item in the symbol table
 *
 */
typedef struct
{
    Data_type type; // Data type of variable/function
    bool def;       // Variable/function has been defined
} tab_item_data;

/**
 * @brief Item of hash table
 *
 */
typedef struct tab_item
{
    char *identifier;   // Identifier of variable/function
    tab_item_data data; // Data struct containing data of the item
    // struct tab_item *next_item; // pointer to next item in the hash table, probably useless
} * Symtab_item;

typedef Symtab_item Symtab[SYMTAB_MAX_SIZE];

int symt_init(Symtab);

int symt_add(Symtab, char *, tab_item_data);

int symt_find(Symtab, char *, tab_item_data *);

// bool symt_remove(Symtab, char *);

int symt_free(Symtab);

#endif // HASHTABLE_H
