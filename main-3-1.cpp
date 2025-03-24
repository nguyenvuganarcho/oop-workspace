#include <iostream>
using namespace std;

extern int* readNumbers();
extern bool equalsArray(int* numbers1, int* numbers2, int length);

int main() {
    int* numbers1 = readNumbers();
    int* numbers2 = readNumbers();

    if (equalsArray(numbers1, numbers2, 10)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    delete[] numbers1;
    delete[] numbers2;

    return 0;
}