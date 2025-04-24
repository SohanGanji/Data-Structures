// write a program to find the binary numbers from 1 to n using queue implementation

#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000
#define MAX_LEN 32

char queue[SIZE][MAX_LEN];
int front = 0, rear = 0;

void enqueue(char* str) {
    int i = 0;
    while (str[i] != '\0') {
        queue[rear][i] = str[i];
        i++;
    }
    queue[rear][i] = '\0';
    rear++;
}

void dequeue(char* str) {
    int i = 0;
    while (queue[front][i] != '\0') {
        str[i] = queue[front][i];
        i++;
    }
    str[i] = '\0';
    front++;
}

void appendChar(char* dest, char* src, char ch) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = ch;
    dest[i+1] = '\0';
}

void generateBinary(int n) {
    enqueue("1");
    for (int i = 0; i < n; i++) {
        char current[MAX_LEN];
        dequeue(current);
        printf("%s\n", current);

        char s1[MAX_LEN], s2[MAX_LEN];
        appendChar(s1, current, '0');
        appendChar(s2, current, '1');

        enqueue(s1);
        enqueue(s2);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    generateBinary(n);
    return 0;
}
