#ifndef EQUVALENCE_TESTS_H
#define EQUVALENCE_TESTS_H
// EquivalenceTests.h

#include <iostream>
#include "Addition.h"

class EquivalenceTests {
public:
    void runTests() {
        testPositiveIntegers();
        testNegativeIntegers();
        // Add other tests here
    }

private:
    void testPositiveIntegers() {
        Addition addition;
        if (addition.add(5, 10) != 15) {
            std::cout << "Test 1 failed!" << std::endl;
        }
    }

    void testNegativeIntegers() {
        Addition addition;
        if (addition.add(-4, -5) != -9) {
            std::cout << "Test 2 failed!" << std::endl;
        }
    }

    // Add other test functions here

    void testZero() {
        Addition addition;
        if (addition.add(0,0) != 0) {
            std::cout << "Test 3 failed!" << std::endl;
        }
    }

    void testPositiveAndNegative() {
        Addition addition;
        if (addition.add(5, -3) != 2) {
            std::cout << "Test 4 failed!" << std::endl;
        }
    }

    void testBigNumbers() {
        Addition addition;
        if (addition.add(1000000, 2000000) != 3000000) {
            std::cout << "Test 5 failed!" << std::endl;
        }
    }

    void testSpecialCases() {
        Addition addition;
        if (addition.add(1, -1) != 0) {
            std::cout << "Test 6 failed!" << std::endl;
        }
    }
};

#endif // EQUVALENCE_TESTS_H