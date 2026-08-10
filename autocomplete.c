#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define ALPHABET_SIZE 26

typedef struct TrieNode
{
    bool isEnd;
    struct TrieNode *child[ALPHABET_SIZE]; 
} TrieNode;

TrieNode *create_node (void);

int main (void)
{
    TrieNode node1 = *create_node();
    printf("%p\n", node1);
}

TrieNode *create_node (void)
{
    TrieNode *node = malloc(sizeof(TrieNode));

    if (node == NULL)
    {
        return NULL;
    }

    node->isEnd = false;
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        node->child[i] = NULL;
    }
    return node;
}