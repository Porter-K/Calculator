
enum operation{
    add,
    sub,
    multiply,
    divide,
    null
};

struct pointers{
    int* nums;
    enum operation* ops;
    int lastNum;
    int lastOp;
};

int isNumber(char c);
int isOperation(char c);

struct pointers parse(char equation[]);
