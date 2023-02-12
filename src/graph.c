#include "graph.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#include "queue.h"
#include "stack.h"

#define WIDTH 80  // ширина отрисовки
#define HEIGHT 25
#define X_MIN 0
#define X_MAX 4 * M_PI  // максимальное значение x
#define Y_MIN -1
#define Y_MAX 1
#define X_CENTER 0
#define Y_CENTER 13
#define STEP_X (X_MAX - X_MIN) / WIDTH   // шаг отрисовки по x
#define STEP_Y (Y_MAX - Y_MIN) * HEIGHT  // шаг отрисовки по y
#define COUNT_OP 12                      //

// struct node init(); // функция инициализации списка
// char* get_rpn(char* str); // преобразование выражения в ОПЗ
// double calc(char* str, double x); // расчёт Y

int main(int argc, char *argv[]) {
    int ret = 0;
    if (argc != 2) {
        printf("Usage: graph <expression>\n");
        ret = 1;
    } else {
        struct word *operations = malloc(COUNT_OP * sizeof(struct word));
        init_operations(operations);
        //-----------------------------------------------------------
        struct word *p = find_word(operations, "(");
        // if (p) printf("%d %d", p->type, (int)round(p->value));
        struct stack *top = NULL;
        push(&top, p);
        struct word *pp = pop(&top);
        if (pp) {
            printf("stack: %d %d", pp->type, (int)round(pp->value));
            // struct queue *first = NULL, *last = NULL;
            // insert(pp, &last, &first);
            // struct word *qq = delete (&first);
            // if (pp) printf("\nqueue: %d %d", qq->type, (int)round(qq->value));
        }

        //-----------------------------------------------------------

        // display(argv[1]);

        // char* rpn_str = get_rpn(); // преобразовать в ОПЗ

        // init(); // инициализировать стек

        free(operations);
    }

    return ret;
}

struct word *find_word(struct word *operations, char *str_find) {
    struct word *p = operations, *find = NULL;
    for (int i = 0; i < COUNT_OP; i++, p++) {
        if (strcmp(p->str, str_find) == 0) {
            find = p;
            break;
        }
    }

    return find;
}

void display(char *input_str) {
    printf(input_str);

    for (double x = 0; x < X_MAX; x += (X_MAX - X_MIN) / WIDTH) {
        // calc(rpn_str, x); // расчёт Y
    }

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            double x = X_MIN + j * STEP_X;
            double y = sin(cos(2 * x));
            // y = evaluateExpression(polish);
            if (i == (int)((Y_MAX - y) / STEP_Y + Y_CENTER) && j >= X_CENTER)
                printf("*");
            else
                printf(".");
        }
        printf("\n");
    }
}

void init_operations(struct word *operations) {
    struct word *p = operations;

    strcpy(p->str, "(");
    p->value = 0;
    p->type = LEFT_PAREN;
    p++;

    strcpy(p->str, ")");
    p->value = 1;
    p->type = RIGHT_PAREN;
    operations++;
    p++;

    strcpy(p->str, "+");
    p->value = 2;
    p->type = OPERATOR;
    p++;

    strcpy(p->str, "-");
    p->value = 2;
    p->type = OPERATOR;
    p++;

    strcpy(p->str, "*");
    p->value = 3;
    p->type = OPERATOR;
    p++;

    strcpy(p->str, "/");
    p->value = 3;
    p->type = OPERATOR;
    p++;

    strcpy(p->str, "sin");
    p->value = 1;
    p->type = FUNCTION;
    p++;

    strcpy(p->str, "cos");
    p->value = 4;
    p->type = FUNCTION;
    p++;

    strcpy(p->str, "tan");
    p->value = 4;
    p->type = FUNCTION;
    p++;

    strcpy(p->str, "ctg");
    p->value = 4;
    p->type = OPERATOR;
    p++;

    strcpy(p->str, "sqrt");
    p->value = 4;
    p->type = FUNCTION;
    p++;

    strcpy(p->str, "ln");
    p->value = 4;
    p->type = FUNCTION;
}

double calculate(char* expression) {
  struct stack top = NULL;
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
    } else if (strcmp(token, "sin") == 0) {
      double operand1 = pop(&stack);
      push(&stack, sin(operand1));
    } else {
      push(&stack, atof(token));
    }
    token = strtok(NULL, " ");
  }
  return pop(&stack);
}
