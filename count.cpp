#include <iostream>
using namespace std;

int count(int arr[], int n) {
    int total = 0;
    
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            total++;
        }
    }

    return total;
}