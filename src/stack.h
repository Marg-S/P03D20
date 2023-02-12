#ifndef STACK
#define STACK

#include "graph.h"


struct node {
    struct operation_struct* operation;
    struct node* next;
};

void push(struct node root, char* operation);
struct token* pop(struct node root);
struct token* peek(struct node root);



#endif
