#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 80    // ширина отрисовки
#define X_MAX 4 * M_PI    // максимальное значение x
#define STEP X_MAX / WIDTH  // шаг отрисовки

//struct stack init(); // функция инициализации списка
//char* get_rpn(char* str); // преобразование выражения в ОПЗ
//double calc(char* str, double x); // расчёт Y
//void display(char* rpn_str);

int main() {

    char* input_str[12]; // объявить и инициализировать массив допустимых операций и функций
    input_str[0] = "+";



    //fgets(); // считать входную строку

    //char* rpn_str = get_rpn(); // преобразовать в ОПЗ

    //init(); // инициализировать стек


    //display(rpn_str);


    return 0;
} 

void display(char* rpn_str) {
    for (int x = 0; x < X_MAX; x += STEP) {

    }
    //calc(rpn_str, x); // расчёт Y

}
