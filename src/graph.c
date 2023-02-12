#include "graph.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
        // объявить и инициализировать массив допустимых операций и функций
        // int n = 12;
        // struct operation_struct *operations = malloc(n * sizeof(struct operation_struct));
        // init_operations(operations);

        display(argv[1]);

        // char* rpn_str = get_rpn(); // преобразовать в ОПЗ

        // init(); // инициализировать стек

        // display(rpn_str);

        // free(operations);
    }

    return ret;
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

void init_operations(struct operation_struct *operations) {
    strcpy(operations->str, "(");
    operations->prior = 0;
    operations->type = LEFT_PAREN;
}

struct node *find_word(char *str, struct node *stack) {
    struct node *p = stack, *find = NULL;
    while (p) {
        if ((p->operation)->str == str) {
            find = p;
            break;
        }
        p = p->next;
    }

    return find;
}
