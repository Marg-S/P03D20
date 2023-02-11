#ifndef STACK
#define STACK

void push(struct stack root, char* operation);
char* pop(struct stack root);


struct stack {
    char* operation;
    struct stack* next;
};


#endif
