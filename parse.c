#include <stdlib.h>
#include <stdio.h>
#include "parse.h"


struct pointers parse(char equation[]){
    struct pointers ptrs;
    ptrs.nums = malloc(sizeof(int)*50);
    ptrs.ops = malloc(sizeof(enum operation)*50);

    int numIndex = -1;
    int opsIndex = -1;
    
    for(int i=0; equation[i]!='\0'; i++){
        if(isNumber(equation[i])){
            if(i>0&&isNumber(equation[i-1])){
                ptrs.nums[numIndex]*=10;
                ptrs.nums[numIndex]+=(equation[i]-48);
            }else{
                numIndex++;
                ptrs.nums[numIndex]=(equation[i]-48);
            }
        }else if (isOperation(equation[i])) {
            opsIndex++;
            switch (equation[i]) {
                case '+':
                    ptrs.ops[opsIndex]=add;
                    break;
                case '-':
                    ptrs.ops[opsIndex]=sub;
                    break;
                case '*':
                    ptrs.ops[opsIndex]=multiply;
                    break;
                case '/':
                    ptrs.ops[opsIndex]=divide;
                    break;
            }
        }
    }
    ptrs.lastNum=numIndex;
    ptrs.lastOp=opsIndex;

    return ptrs;
}

int isNumber(char c){
    if(c>='0'&&c<='9'){
        return 1;
    }
    else return 0;
}

int isOperation(char c){
    switch (c) {
        case '+':
        case '-':
        case '*':
        case '/':
            return 1;
            break;
        default:
            return 0;
            break;    
    }
}