#include <iostream>
using namespace std;

int* readNumbers() {
    int* numbers = new int[10];

    for (int i = 0; i < 10; i++) {
        cin >> numbers[i];
    }

    return numbers;
}

int secondSmallestSum(int *numbers, int length) {
    // Step 1: Calculate all sub-array sums
    int* subArraySums = new int[length * (length + 1) / 2];  // Maximum size of all sub-array sums
    int index = 0;

    // Generate all sub-array sums
    for (int i = 0; i < length; ++i) {
        int sum = 0;
        for (int j = i; j < length; ++j) {
            sum += numbers[j];
            subArraySums[index++] = sum;
        }
    }

    // Step 2: Find the smallest and second smallest sums manually
    int smallest = 1000000000;  // Use a large number as initial "smallest"
    int secondSmallest = 1000000000;  // Use a large number as initial "second smallest"

    for (int i = 0; i < index; ++i) {
        if (subArraySums[i] < smallest) {
            secondSmallest = smallest;
            smallest = subArraySums[i];
        } else if (subArraySums[i] > smallest && subArraySums[i] < secondSmallest) {
            secondSmallest = subArraySums[i];
        }
    }

    // Clean up memory
    delete[] subArraySums;

    // Return the second smallest sum
    return secondSmallest;
}
