#include <stdbool.h>
#include <stdlib.h>
#include "uthash.h"


struct HashNode {
    int key;
    int value;
    UT_hash_handle hh;
};

struct HashNode_1 {
    int id;
    char name[10];
    int age;
    bool male;
    UT_hash_handle hh;
};

int main(void) 
{
    struct HashNode *myMap = NULL;
    struct HashNode *newNode = malloc(sizeof(struct HashNode));
    newNode->key = 2;
    newNode->value = 3;
    HASH_ADD_INT(myMap, key, newNode);

    return 0;
}