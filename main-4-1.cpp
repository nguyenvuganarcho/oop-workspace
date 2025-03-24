#include <iostream>
using namespace std;

extern int* readNumbers();
extern int secondSmallestSum(int *numbers, int n);

int main() {
    int* numbers = readNumbers();
    int result = secondSmallestSum(numbers, 10);

    cout  << "Second smallest number is: " << result << endl;
    return 0;
}