#include <iostream>
using namespace std;

extern int* readNumbers(int *numbers, int n);
extern int secondSmallest(int *numbers, int n);

int main() {
    int* numbers = readNumbers();
    int result = secondSmallest(numbers, 10);

    cout  << "Second smallest number is: " << result << endl;
    return 0;
}