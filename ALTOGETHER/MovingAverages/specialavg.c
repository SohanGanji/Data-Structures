#include <stdio.h>

void sort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void sort_3x3(int mat[4][4], int rows, int cols) {
    int temp[4][4];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            temp[i][j] = mat[i][j];
        }
    }

    for (int i = 0; i < rows - 2; i++) {
        for (int j = 0; j < cols - 2; j++) {
            int sub[9];
            int k = 0;
            for (int x = i; x < i + 3; x++) {
                for (int y = j; y < j + 3; y++) {
                    sub[k++] = mat[x][y];
                }
            }
            sort(sub, 9);
            k = 0;
            for (int x = i; x < i + 3; x++) {
                for (int y = j; y < j + 3; y++) {
                    temp[x][y] = sub[k++];
                }
            }
        }
    }

    printf("Sorted Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", temp[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int mat[4][4] = {
        {9, 8, 7, 6},
        {5, 4, 3, 2},
        {1, 0, 1, 2},
        {3, 4, 5, 6}
    };

    sort_3x3(mat, 4, 4);

    return 0;
}
