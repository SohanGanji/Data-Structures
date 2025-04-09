#include <stdio.h>

void compute_exponential_moving_average(float *input, float *output, int size, float alpha) {
    output[0] = input[0];
    for (int i = 1; i < size; i++) {
        output[i] = alpha * input[i] + (1 - alpha) * output[i - 1];
    }
}

int main() {
    int size = 10;
    float alpha = 0.2;
    float input[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};
    float output[size];

    compute_exponential_moving_average(input, output, size, alpha);

    printf("Exponential Moving Averages:\n");
    for (int i = 0; i < size; i++) {
        printf("%.2f ", output[i]);
    }
    printf("\n");

    return 0;
}

