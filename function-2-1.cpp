#include <iostream>
using namespace std;

int* readNumbers() {
  int* numbers = new int[10];

  for (int i = 0; i < 10; i++) {
    cin >> numbers[i];
  }

  return numbers;
}

void hexDigits(int* numbers, int length) {
  char hexChar[] = {'0', '1', '2', '3', '4', '5', '6', '7',
                    '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

  for (int i = 0; i < 10; i++) {
    char hexDigit = hexChar[numbers[i]];
    cout << i << " " << numbers[i] << "" << hexDigit << endl;
  }
}