#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    int size;
    printf("Enter the size of the postfix expression: ");
    scanf("%d",&size);

    char postfix[size+1];
    int stack[size];
    int top=-1;
    int i=0;
    char token;
    int operand1, operand2, result;

    printf("Enter the postfix expression: ");
    scanf("%s",postfix);

    while ((token=postfix[i++])!='\0') {
        if (isdigit(token)) {
            top++;
            stack[top]=token-'0';
        } else {
            operand2=stack[top];
            top--;
            operand1=stack[top];
            top--;
            switch (token) {
                case '+':
                    result=operand1+operand2;
                    break;
                case '-':
                    result=operand1-operand2;
                    break;
                case '*':
                    result=operand1*operand2;
                    break;
                case '/':
                    result=operand1/operand2;
                    break;
                case '^':
                    result=1;
                    for (int k=0;k<operand2;k++) {
                        result*=operand1;
                    }
                    break;
                default:
                    printf("Invalid operator: %c\n", token);
                    return 1;
            }
            top++;
            stack[top]=result;
        }
    }

    if (top != 0) {
        printf("Invalid postfix expression\n");
        return 1;
    }

    printf("Result of the postfix expression: %d\n", stack[top]);
    return 0;
}