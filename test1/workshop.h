#ifndef WORKSHOP_H
#define WORKSHOP_H


#include <iostream>
using namespace std;

void changeValue(double* num) {
    *num = 42;
}

void printArray (double* arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

double arrayMax(double* arr, int n) {
    double max = arr[0];
    
    for (int i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    return max;
}

double* dynamicArray(int n, double M) {
    double* arr = new double[n];

    for (int i = 0; i < n; i++) {
        arr[i] = M;
    }

    return arr;
}

#endif