#ifndef GRAPH
#define GRAPH

#define LEN 5

enum word_type { NUMBER, OPERATOR, FUNCTION, LEFT_PAREN, RIGHT_PAREN };

// enum operation_type { UNARY, BINARY };

struct word {
    enum word_type type;
    double value;
    char str[LEN];
};

void init_operations(struct word *operations);
struct word *find_word(struct word *operations, char *str_find);
void display(char *input_str);

#endif
