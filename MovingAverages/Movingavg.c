#include <stdio.h>

void compute_moving_average(float *input, float *output, int size, int window_size) {
    for (int i = 0; i <= size - window_size; i++) {
        float sum = 0.0;
        for (int j = 0; j < window_size; j++) {
            sum += input[i + j];
        }
        output[i] = sum / window_size;
    }
}

int main() {
    int size = 10;
    int window_size = 3;
    float input[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};
    float output[size - window_size + 1];

    compute_moving_average(input, output, size, window_size);

    printf("Moving Averages:\n");
    for (int i = 0; i < size - window_size + 1; i++) {
        printf("%.2f ", output[i]);
    }
    printf("\n");

    return 0;
}

