// Implements a dictionary's functionality
// ** USE A HASH TABLE (ARRAY OF LINKED LISTS) WITH HASH FUNCTION (ASSIGNING A NUMBER TO EVERY INPUT)

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;
int count_word = 0; // initializes in count_word at 0

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Hash word to obtain a hash value
    // access linked list at index in hash table
    // traverse list, looking for word

    int hash_num = hash(word);

    // initialize cursor variable
    node *cursor = table[hash_num];
    // loop until end of linked list
    while (cursor != NULL)
    {
        // check if words are same
        if (strcasecmp(cursor -> word, word) == 0)
        {
            // we found the word so return true
            return true;
        }
        // Else... we move cursor to next node
        cursor = cursor -> next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory (a hash table), returning true if successful, else false
bool load(const char *dictionary)
{
    // open dictionary file
    // use "fopen" (file, read || write) and check for return value IF NULL
    FILE *dict_file = fopen(dictionary, "r");
    if (dict_file == NULL)
    {
        return false;
    }

    // read strings from file one at a time
    // fscanf(file, "%s", word) so we can repeat this process for each word; better to use while loop
    // word -> char datatype with length+1
    // fscanf will return "EOF" once it reaches end of file
    char str[LENGTH + 1];
    while (fscanf(dict_file, "%s", str) != EOF)
    {
        // create a new node for each word
        // use malloc
        // remember to check if return value is NULL
        // copy word into node using strcpy(destination, source)
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            return false;
        }
        strcpy(new_node -> word, str);

        // hash word to obtain a hash value
        // function takes a string and returns an index
        int hash_num = hash(str);

        // insert node into hash table at that location
        // check if head is pointing to NULL
        // point new_node to NULL
        // else we point new_node to first node
        // point header to new_node
        if (table[hash_num] == NULL)
        {
            new_node -> next = NULL;
        }
        else
        {
            new_node -> next = table[hash_num];
        }
        table[hash_num] = new_node;

        // increase count_word++
        count_word += 1;
    }
    // Close the file and we can return true
    fclose(dict_file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return count_word;
}

// Helper function (use recursion...)
void free_node(node *n)
{
    // base case
    if (n -> next != NULL)
    {
        free_node(n -> next);
    }
    // free memory at n
    free(n);
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // iterate over N (26 for alphabet)
    for (int i = 0; i < N; i++)
    {
        // check: if table at position i is NOT NULL
        if (table[i] != NULL)
        {
            // call new function free_node(arg)
            free_node(table[i]);
        }
    }
    return true;
}

/* Back to speller.c */
// test - $ check50 cs50/problems/2023/x/speller
// style - $ style50 speller.c
// submit - $ submit50 cs50/problems/2023/x/speller
