#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ALPHABET_SIZE 26

// Node Structure
typedef struct TrieNode
{
    bool isEnd;
    struct TrieNode *child[ALPHABET_SIZE]; 
} TrieNode;

TrieNode *create_node (void);
void insert(TrieNode *root, const char *word);
TrieNode *find_prefix(TrieNode *root, const char *prefix);

// Main function
int main (int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: ./autocomplete <word>\n");
        return 1;
    }

    char *findWord = argv[1];

//  Root node 
    TrieNode *root = create_node();

    // Insert test word
    insert(root, findWord);

    return 0;
}

// Functions
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

void insert(TrieNode *root, const char *word)
{
    TrieNode *curr = root;

    // Reject words containing non-letters, since the index
    // computed below must stay within 0-25 ('A'-'Z')
    for (int i = 0; word[i] != '\0'; i++)
    {
        if (!isalpha(word[i]))
        {
            return;
        }
    }

    for (int i = 0; word[i] != '\0'; i++)
    {
        int index = toupper(word[i]) - 'A';

        if (curr->child[index] == NULL)
        {
            curr->child[index] = create_node();
        }

        curr = curr->child[index];
    }

    curr->isEnd = true;
}

TrieNode *find_prefix(TrieNode *root, const char *prefix)
{
    // An empty prefix or a null root matches nothing
    if (root == NULL || prefix[0] == '\0')
    {
        return NULL;
    }

    TrieNode *curr = root;

    // Walk down the trie one character at a time
    for (int i = 0; prefix[i] != '\0'; i++)
    {
        // Convert each letter to its 0-25 index ('A'-'Z')
        int index = toupper(prefix[i]) - 'A';

        // Missing child means the prefix is not in the trie
        if (curr->child[index] == NULL)
        {
            return NULL;
        }

        curr = curr->child[index];
    }

    // Return the node matching the end of the prefix
    return curr;
}