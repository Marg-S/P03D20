#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_EXPR_SIZE 100

struct Stack {
  int top;
  double items[MAX_EXPR_SIZE];
};

void push(struct Stack *stack, double value) {
  stack->items[++stack->top] = value;
}

double pop(struct Stack *stack) {
  return stack->items[stack->top--];
}

int is_empty(struct Stack *stack) {
  return stack->top == -1;
}

double evaluate(char* expression) {
  struct Stack stack = {.top = -1};
  char *token = strtok(expression, " ");
  while (token != NULL) {
    if (strcmp(token, "+") == 0) {
      double operand2 = pop(&stack);
      double operand1 = pop(&stack);
      push(&stack, operand1 + operand2);
    } else if (strcmp(token, "-") == 0) {
      double operand2 = pop(&stack);
      double operand1 = pop(&stack);
      push(&stack, operand1 - operand2);
    } else if (strcmp(token, "*") == 0) {
      double operand2 = pop(&stack);
      double operand1 = pop(&stack);
      push(&stack, operand1 * operand2);
    } else if (strcmp(token, "/") == 0) {
      double operand2 = pop(&stack);
      double operand1 = pop(&stack);
      push(&stack, operand1 / operand2);
    } else if (strcmp(token, "^") == 0) {
      double operand2 = pop(&stack);
      double operand1 = pop(&stack);
      push(&stack, pow(operand1, operand2));
    } else {
      push(&stack, atof(token));
    }
    token = strtok(NULL, " ");
  }
  return pop(&stack);
}

