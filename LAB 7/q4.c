#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int get_precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

int main() {
    int size;
    printf("Enter the size of the expression: ");
    scanf("%d", &size);

    char infix[size + 1], postfix[size + 1];
    char stack[size];
    int top = -1;
    int i = 0, j = -1;
    char token;

    printf("Enter the infix expression: ");
    scanf("%s", infix);
    token = infix[i];

    while (token != '\0') {
        if (isalnum(token)) {
            j++;
            postfix[j] = token;
        } else {
            if (top == -1 || token == '(') {
                top++;
                stack[top] = token;
            } else if (token == ')') {
                while (top != -1 && stack[top] != '(') {
                    j++;
                    postfix[j] = stack[top];
                    top--;
                }
                if (top != -1) top--;
            } else {
                while (top != -1 && get_precedence(stack[top]) >= get_precedence(token) 
                      && stack[top] != '(') {
                    if (token == '^' && stack[top] == '^') break;
                    j++;
                    postfix[j] = stack[top];
                    top--;
                }
                top++;
                stack[top] = token;
            }
        }
        i++;
        token = infix[i];
    }

    while (top != -1) {
        j++;
        postfix[j] = stack[top];
        top--;
    }

    postfix[j + 1] = '\0';

    printf("The postfix expression is %s.\n", postfix);
    return 0;
}