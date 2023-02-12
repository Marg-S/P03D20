#include <stdio.h>

#include "stack.h"

// функция инициализации списка
struct node* init(struct word) {
    struct node* node1 = malloc(sizeof(struct stack));
    (*node1).info = word;
    (*node1).next = NULL;

    return node1;
}

int push(struct stack top, struct word) {
    struct node* tmp = malloc(sizeof(struct node));
    if (tmp->next == NULL) {
        puts("STACK_OVERFLOW");
        ret = 1;
    }
    else {
        tmp->next = *top;
        tmp->operation = word;
        *top = tmp;
    }

    return ret;
}

struct node* pop(struct node *root) {

}
remove_door(struct node* elem, struct node* root) {
    struct node *p = root, *node_next = NULL;

    if (elem != root)
        while (elem && p && (*p).next != elem) p = (*p).next;
    if (p && elem && root) {
        (*p).next = (*elem).next;
        // free((*elem).info);
        free(elem);
        node_next = (*p).next;
    }
T pop2(Node_t **head) {
    Node_t *out;
    T value;
    if (*head == NULL) {
    exit(STACK_UNDERFLOW);
    }
    out = *head;
    *head = (*head)->next;
    value = out->value;
    free(out);
    return value;
}
    return node_next;
}
char* peek(struct node root) {

}
    T peek(const Node_t* head) {
    if (head == NULL) {
        exit(STACK_UNDERFLOW);
    }
    return head->value;
}