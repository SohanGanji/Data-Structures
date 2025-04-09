#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* right;
    struct Node* down;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->right = NULL;
    newNode->down = NULL;
    return newNode;
}

void printGrid(struct Node* head) {
    struct Node* row = head;
    struct Node* col;
    while (row != NULL) {
        col = row;
        while (col != NULL) {
            printf("%d ", col->data);
            col = col->right;
        }
        printf("\n");
        row = row->down;
    }
}

int main() {
    int n = 3, m = 3;
    struct Node* head = createNode(1);
    struct Node* row = head;
    struct Node* col;

    for (int i = 0; i < n; i++) {
        col = row;
        for (int j = 1; j < m; j++) {
            col->right = createNode(i * m + j + 1);
            col = col->right;
        }
        if (i < n - 1) {
            row->down = createNode((i + 1) * m + 1);
            row = row->down;
        }
    }

    struct Node* tempRow = head;
    struct Node* tempCol;
    while (tempRow != NULL) {
        tempCol = tempRow;
        while (tempCol != NULL && tempCol->right != NULL) {
            tempCol->right->down = tempCol->down ? tempCol->down->right : NULL;
            tempCol = tempCol->right;
        }
        tempRow = tempRow->down;
    }

    printf("Grid:\n");
    printGrid(head);

    return 0;
}
