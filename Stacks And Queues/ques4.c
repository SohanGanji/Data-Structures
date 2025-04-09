// in a clinic make a queue operating function where each pateint can enroll thier name and age and each pateint is assigned a unique waiting number and the doctor has full control over the queue and each node is automatically deleted as soon as thier number is arrived create a queue implementstion  like railway network for this scenario using linklists

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Patient {
    int waitingNumber;
    char name[50];
    int age;
    struct Patient* next;
};

struct Queue {
    struct Patient* front;
    struct Patient* rear;
    int nextWaitingNumber;
};

void initialize(struct Queue* q) {
    q->front = NULL;
    q->rear = NULL;
    q->nextWaitingNumber = 1;
}

int isEmpty(struct Queue* q) {
    return q->front == NULL;
}

void enrollPatient(struct Queue* q, char name[], int age) {
    struct Patient* newPatient = (struct Patient*)malloc(sizeof(struct Patient));
    newPatient->waitingNumber = q->nextWaitingNumber++;
    strcpy(newPatient->name, name);
    newPatient->age = age;
    newPatient->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newPatient;
    } else {
        q->rear->next = newPatient;
        q->rear = newPatient;
    }

    printf("Patient enrolled: %s (Age: %d), Waiting Number: %d\n", name, age, newPatient->waitingNumber);
}

void callNextPatient(struct Queue* q) {
    if (isEmpty(q)) {
        printf("No patients in queue.\n");
        return;
    }

    struct Patient* temp = q->front;
    printf("Calling Patient: %s (Age: %d), Waiting Number: %d\n", temp->name, temp->age, temp->waitingNumber);
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
}

void displayQueue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Current Queue:\n");
    struct Patient* temp = q->front;
    while (temp != NULL) {
        printf("Waiting Number: %d, Name: %s, Age: %d\n", temp->waitingNumber, temp->name, temp->age);
        temp = temp->next;
    }
}

int main() {
    struct Queue clinicQueue;
    initialize(&clinicQueue);

    enrollPatient(&clinicQueue, "Alice", 28);
    enrollPatient(&clinicQueue, "Bob", 34);
    enrollPatient(&clinicQueue, "Charlie", 45);

    displayQueue(&clinicQueue);

    callNextPatient(&clinicQueue);
    displayQueue(&clinicQueue);

    callNextPatient(&clinicQueue);
    displayQueue(&clinicQueue);

    return 0;
}
