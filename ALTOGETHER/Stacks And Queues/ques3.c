// implement circular queue using array and perform enque &deque & display operations


#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

struct CircularQueue {
    int items[SIZE];
    int front;
    int rear;
};

void initialize(struct CircularQueue* q) {
    q->front = -1;
    q->rear = -1;
}

int isFull(struct CircularQueue* q) {
    return (q->front == (q->rear + 1) % SIZE);
}

int isEmpty(struct CircularQueue* q) {
    return (q->front == -1);
}

void enqueue(struct CircularQueue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full! Cannot enqueue %d\n", value);
        return;
    }

    if (isEmpty(q)) {
        q->front = q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % SIZE;
    }

    q->items[q->rear] = value;
    printf("Enqueued: %d\n", value);
}

void dequeue(struct CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot dequeue.\n");
        return;
    }

    printf("Dequeued: %d\n", q->items[q->front]);

    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % SIZE;
    }
}

void display(struct CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue: ");
    int i = q->front;
    while (1) {
        printf("%d ", q->items[i]);
        if (i == q->rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    struct CircularQueue q;
    initialize(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    display(&q);

    dequeue(&q);
    display(&q);

    enqueue(&q, 50);
    display(&q);

    enqueue(&q, 60);
    display(&q);

    return 0;
}
