#include <stdio.h>
#include <stdbool.h>

int top = -1;

void push(char stack[], char ch) {
    stack[++top] = ch;
}

char pop(char stack[]) {
    if (top == -1)
        return '\0';
    return stack[top--];
}

bool isMatchingPair(char open, char close) {
    if (open == '(' && close == ')') return true;
    if (open == '{' && close == '}') return true;
    if (open == '[' && close == ']') return true;
    return false;
}

bool isBalanced(char expr[], int size) {
    top = -1;
    char stack[size];
    for (int i = 0; expr[i] != '\0'; i++) {
        if (expr[i] == '(' || expr[i] == '{' || expr[i] == '[') {
            push(stack, expr[i]);
        } else if (expr[i] == ')' || expr[i] == '}' || expr[i] == ']') {
            char open = pop(stack);
            if (!isMatchingPair(open, expr[i])) {
                return false;
            }
        }
    }
    return top == -1;
}

int main() {
    int size;
    printf("Enter the size of the expression: ");
    scanf("%d", &size);

    char expr[size + 1];
    printf("Enter the expression: ");
    scanf("%s", expr);

    if (isBalanced(expr, size))
        printf("Balanced\n");
    else
        printf("Not Balanced\n");

    return 0;
}