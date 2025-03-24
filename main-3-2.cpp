#include <iostream>
using namespace std;

extern int* readNumbers();
extern bool equalArrays(int* numbers1, int* numbers2, int length);
extern int* reverseArray(int* numbers1, int length);

int main() {
    int* numbers1 = readNumbers();
    int* reversed = reverseArray(numbers1, 10);

    if (equalArrays(numbers1, reversed, 10)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

  

    delete[] numbers1;
    delete[] reversed;

    return 0;
}