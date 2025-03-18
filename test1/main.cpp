#include "workshop.h"
#include <iostream>
using namespace std;

int main() {
    double array[] = {4.5, 6.65, 9.02, 4.33, 7.21};
    int n = sizeof(array) / sizeof(array[0]);
    int size = 10;
    double M = 9.99;
    double num = 4.55;

    changeValue(&num);

    cout << "After change: " << num << endl;
    
    printArray(array, n);
    double max = arrayMax(array, n);

    cout << "the maximun element of the array is: " << max << endl;

    double* newArr = dynamicArray(size, M);

    cout << "Array elements: ";
    for (int i = 0; i < size; i++) {
        cout << newArr[i] << " ";
    }
    cout << endl;

    delete newArr;

    return 0;
}