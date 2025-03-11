
#include <iostream>
#include <string>
using namespace std;

void print_binary_str(int number) {

    if (number == 0) {
        cout << "0" << endl;
        return;
    }
    string binary_result = "";

    while (number > 0) {
        int remainder = number % 2;
        binary_result += to_string(remainder);
        number = number / 2;
    }

    string reverse_result = "";
    for (int i = binary_result.length() - 1; i >= 0; i--) {
        reverse_result += binary_result[i];
    }

    cout << reverse_result << endl;

}

int main() {
    int number = 75;
    print_binary_str(number);

    return 0;

}