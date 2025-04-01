#include <stdio.h>
#include <stdlib.h>

#define N 10

int stack[N];
int top = -1;

void push(int data)
{
    if (top == N - 1)
    {
        printf("Stack is full\n");
    }
    else
    {
        top++;
        stack[top] = data;
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("%d ", stack[top]); 
        top--;
    }
}

void printstack()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
        return;
    }
    
    printf("Stack elements:\n");
    for (int i = top; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
    }
}

int main()
{
    int data, i;

    printf("Enter up to %d elements to push into stack (-1 to stop):\n", N);
    for (i = 0; i < N; i++)
    {
        scanf("%d", &data);
        if (data == -1) break; 
        push(data);
    }

    int count;
    printf("Enter the number of elements to pop:\n");
    scanf("%d", &count);

    printf("Popped elements: ");
    for (i = 0; i < count; i++)
    {
        pop();
    }

    printstack(); 

    return 0;
}