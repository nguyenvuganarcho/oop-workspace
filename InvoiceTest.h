// InvoiceTest.h

#include <iostream>
#include "Invoice.h"

class InvoiceTest {
public:
    void runTests() {
        testConstructor();
        testAddServiceCost();
        testGetDollarsOwed();
        testGetInvoiceId();
        testNegativeServiceCost();
        
        std::cout << "All Invoice tests completed." << std::endl;
    }

private:
    void testConstructor() {
        std::cout << "Testing Invoice constructor..." << std::endl;
        
        // Test that constructor sets the invoice ID correctly
        Invoice invoice("TEST123");
        if (invoice.getInvoiceId() != "TEST123") {
            std::cout << "Constructor test failed! Expected ID: TEST123, Got: " 
                      << invoice.getInvoiceId() << std::endl;
        }
        
        // Test that constructor initializes dollarsOwed to zero
        if (invoice.getDollarsOwed() != 0) {
            std::cout << "Constructor test failed! Expected dollarsOwed: 0, Got: " 
                      << invoice.getDollarsOwed() << std::endl;
        }
    }

    void testAddServiceCost() {
        std::cout << "Testing addServiceCost()..." << std::endl;
        
        // Test adding a single cost
        {
            Invoice invoice("ABCD");
            invoice.addServiceCost(10);
            if (invoice.getDollarsOwed() != 10) {
                std::cout << "Test 1 failed! Expected: 10, Got: " 
                          << invoice.getDollarsOwed() << std::endl;
            }
        }
        
        // Test adding a different single cost
        {
            Invoice invoice("ABCD");
            invoice.addServiceCost(1);
            if (invoice.getDollarsOwed() != 1) {
                std::cout << "Test 2 failed! Expected: 1, Got: " 
                          << invoice.getDollarsOwed() << std::endl;
            }
        }
        
        // Test adding multiple costs
        {
            Invoice invoice("ABCD");
            invoice.addServiceCost(10.5);
            invoice.addServiceCost(20.75);
            if (invoice.getDollarsOwed() != 31.25) {
                std::cout << "Test 3 failed! Expected: 31.25, Got: " 
                          << invoice.getDollarsOwed() << std::endl;
            }
        }
    }
    
    void testGetDollarsOwed() {
        std::cout << "Testing getDollarsOwed()..." << std::endl;
        
        // Test with zero dollars
        {
            Invoice invoice("ZERO");
            if (invoice.getDollarsOwed() != 0) {
                std::cout << "Test 1 failed! Expected: 0, Got: " 
                          << invoice.getDollarsOwed() << std::endl;
            }
        }
        
        // Test with non-zero dollars
        {
            Invoice invoice("NONZERO");
            invoice.addServiceCost(42.42);
            if (invoice.getDollarsOwed() != 42.42) {
                std::cout << "Test 2 failed! Expected: 42.42, Got: " 
                          << invoice.getDollarsOwed() << std::endl;
            }
        }
    }
    
    void testGetInvoiceId() {
        std::cout << "Testing getInvoiceId()..." << std::endl;
        
        // Test with a simple ID
        {
            Invoice invoice("ABC123");
            if (invoice.getInvoiceId() != "ABC123") {
                std::cout << "Test 1 failed! Expected: ABC123, Got: " 
                          << invoice.getInvoiceId() << std::endl;
            }
        }
        
        // Test with a different ID
        {
            Invoice invoice("XYZ789");
            if (invoice.getInvoiceId() != "XYZ789") {
                std::cout << "Test 2 failed! Expected: XYZ789, Got: " 
                          << invoice.getInvoiceId() << std::endl;
            }
        }
    }
    
    void testNegativeServiceCost() {
        std::cout << "Testing negative service cost handling..." << std::endl;
        
        // Test that negative costs are not added
        {
            Invoice invoice("NEG");
            invoice.addServiceCost(-50);
            if (invoice.getDollarsOwed() != 0) {
                std::cout << "Test 1 failed! Expected: 0, Got: " 
                          << invoice.getDollarsOwed() << std::endl;
            }
        }
        
        // Test with a mix of positive and negative costs
        {
            Invoice invoice("MIXED");
            invoice.addServiceCost(100);
            invoice.addServiceCost(-50);
            if (invoice.getDollarsOwed() != 100) {
                std::cout << "Test 2 failed! Expected: 100, Got: " 
                          << invoice.getDollarsOwed() << std::endl;
            }
        }
    }
};