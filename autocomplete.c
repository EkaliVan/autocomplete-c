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
void insert(TrieNode *node, const char *word);

// Main function
int main (void)
{
//  Root node 
    TrieNode *root = create_node();

    // Insert test word
    insert(root, "ant");

    //  Manual Testing
    // 'a' 
    if (root->child['a' - 'a'] != NULL)
    {
        printf("Found 'a'\n");

        // 'n'  
        if (root->child['a' - 'a']->child['n' - 'a'] != NULL)
        {
            printf("Found 'n'\n");

            // 't'  
            if (root->child['a' - 'a']->child['n' - 'a']->child['t' - 'a'] != NULL)
            {
                printf("Found 't'\n");

                // Check isEnd == True 
                if (root->child['a' - 'a']->child['n' - 'a']->child['t' - 'a']->isEnd)
                {
                    printf("SUCCESS: 'ant' is correctly inserted!\n");
                }
            }
        }
    }
    else
    {
        printf("FAILED: Insertion failed!\n");
    }

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