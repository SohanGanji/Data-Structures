#include <stdio.h>

// Function to compute the moving average
void moving_average(float *input, float *output, int size, int window) {
    float sum = 0;
    int i, j;

    for (i = 0; i < window; i++) {
        sum += input[i];
    }
    output[0] = sum / window;

    
    for (i = window; i < size; i++) {
        sum += input[i] - input[i - window];
        output[i - window + 1] = sum / window;
    }
}

int main() {
    int size = 10; 
    int window = 3; 

    float input[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};
    float output[size - window + 1];

    moving_average(input, output, size, window);

    
    for (int i = 0; i < size - window + 1; i++) {
        printf("%.2f ", output[i]);
    }

    return 0;
}
