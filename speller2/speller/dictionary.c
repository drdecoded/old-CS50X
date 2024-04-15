// Implements a dictionary's functionality

#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


#include "dictionary.h"
#define TABLE_SIZE 1000

typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;


// Number of buckets in hash table
// const unsigned int N = 1;

node *table[TABLE_SIZE];
unsigned int num_words = 0;
bool loaded = false;


unsigned int hash(const char *str)
{
    unsigned long hash = 5381;
    int c;

    while ((c = *str++))
    {
        hash = ((hash << 5) + hash) + c;
    }

    return (hash % TABLE_SIZE);
}

bool check(const char *word)
{
    char c[strlen(word)];
    strcpy(c, word);
    for (int i = 0; c[i] != '\0'; i++)
    {
        c[i] = tolower(c[i]);
    }

    int index = hash(c);
    if (table[index] != NULL)
    {
        node *tmp = table[index];
        while (tmp != NULL)
        {
            if (strcmp(tmp->word, c) == 0)
            {
                return true;
            }
            tmp = tmp->next;
        }
    }

    return false;
}

bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    for (int i = 0; i < TABLE_SIZE; i++)
    {
        table[i] = NULL;
    }

    int index = 0;
    char word[LENGTH + 1];
    node *nd;
    while (fscanf(file, " %s", word) != EOF)
    {
        num_words++;

        do
        {
            nd = malloc(sizeof(node));
            if (nd == NULL)
            {
                free(nd);
            }
        } while (nd == NULL);

        index = hash(word);
        strcpy(nd->word, word);
        nd->next = table[index];
        table[index] = nd;
    }

    fclose(file);
    loaded = true;
    return true;
}

unsigned int size(void)
{
    if (loaded == false)
    {
        return 0;
    }

    return num_words;
}

bool unload(void)
{
    if (loaded == false)
    {
        return false;
    }

    for (int i = 0; i < TABLE_SIZE; i++)
    {

        if (table[i] != NULL)
        {
            node *ptr = table[i];

            while (ptr != NULL)
            {

                node *preptr = ptr;
                ptr = ptr->next;
                free(preptr);
            }
        }
    }

    return true;
}
