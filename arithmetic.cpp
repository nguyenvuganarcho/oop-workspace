#include <iostream>
#include <string>

using namespace std;

string addBinary(string a, string b) {
    // Pad the shorter string with leading zeros to match lengths
    int max_len = max(a.size(), b.size());
    a = string(max_len - a.size(), '0') + a;
    b = string(max_len - b.size(), '0') + b;
    
    int carry = 0;
    string result;
    
    // Iterate from the least significant bit (right to left)
    for (int i = max_len - 1; i >= 0; i--) {
        int sum = (a[i] - '0') + (b[i] - '0') + carry;
        carry = sum / 2; // Update carry
        result.push_back((sum % 2) + '0'); // Append current bit
    }
    
    // Add remaining carry if it exists
    if (carry > 0) {
        result.push_back('1');
    }
    
    // Reverse the result to get the correct order
    string reversed_result;
    for (int i = result.size() - 1; i >= 0; i--) {
        reversed_result.push_back(result[i]);
    }
    
    return reversed_result;
}

// Example usage:
int main() {
    string a = "101";
    string b = "1";
    cout << addBinary(a, b) << endl; // Output: 110
    return 0;
}