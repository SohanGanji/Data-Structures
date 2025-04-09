#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int top = -1;

void push(char stack[], char ch) {
    stack[++top] = ch;
}

char pop(char stack[]) {
    return stack[top--];
}

bool isPalindrome(char str[], int len) {
    top = -1;
    char stack[len];
    for (int i = 0; i < len; i++) {
        push(stack, str[i]);
    }
    for (int i = 0; i < len; i++) {
        if (str[i] != pop(stack)) {
            return false;
        }
    }
    return true;
}

int main() {
    int size;
    printf("Enter the size of the string: ");
    scanf("%d", &size);

    char str[size + 1];
    printf("Enter the string: ");
    scanf("%s", str);

    if (strlen(str) != size) {
        printf("Warning: Entered string length doesn't match the given size.\n");
    }

    if (isPalindrome(str, size))
        printf("The string is a palindrome.\n");
    else
        printf("The string is not a palindrome.\n");

    return 0;
}