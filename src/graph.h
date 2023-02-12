#ifndef GRAPH
#define GRAPH

#define LEN 5

enum word_type {
    NUMBER,
    OPERATOR,
    FUNCTION,
    LEFT_PAREN,
    RIGHT_PAREN
};

enum operation_type {
    UNARY,
    BINARY
};

struct word {
    enum word_type type;
    double value;
    char *str;
};

struct operation_struct {
    char str[LEN];
    int prior;
    enum operation_type type;
};

void init_operations(struct operation_struct *operations);
void display(char* input_str);



#endif
