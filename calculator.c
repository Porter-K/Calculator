#include <stdio.h>
#include <stdlib.h>

void calculatorCLI();
int getNum();

int main(int argc, char *arv[]){
    calculatorCLI();
    return 0;
}

void calculatorCLI(){
    int num1, num2;
    char operator;
    while(1){
        printf("Enter an operator: (x to exit)");
        operator = fgetc(stdin);
        if(operator=='x'){
            exit(0);
        }

        printf("Enter a number: ");
        num1 = getNum();

        printf("Enter a second number: ");
        num2 = getNum();

        printf("%d %c %d = ", num1, operator, num2);

        int answer;
        switch(operator){
            case '+':
                answer= num1+num2;
                break;
            case '-':
                answer = num1-num2;
                break;
            case '*':
                answer = num1*num2;
                break;
            case '/':
                answer = num1/num2;
                break;
            case '%':
                answer = num1%num2;
        }
        printf("%d\n", answer);
    }
}

int getNum(){
    char input[10];
    int num;
    //fgets(input, 10, stdin);
    //sscanf(input, "%d", &num);
    scanf("%d", &num);
    getchar();
    return num;
}