// Invoice.cpp

#include "Invoice.h"

Invoice::Invoice(const std::string& id) : invoiceId(id), dollarsOwed(0.0) {
    // Initialize invoice with the given ID and zero dollars owed
}

void Invoice::addServiceCost(double costDollars) {
    // Only add positive dollar amounts
    if (costDollars > 0) {
        dollarsOwed += costDollars;
    }
}

double Invoice::getDollarsOwed() const {
    return dollarsOwed;
}

std::string Invoice::getInvoiceId() const {
    return invoiceId;
}