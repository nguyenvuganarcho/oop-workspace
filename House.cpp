#include "House.h"

// Default constructor - creates an empty House object
House::House() {
    maxAppliances = 10;  // Default capacity
    numAppliances = 0;   // No appliances initially
    appliances = new Appliance*[maxAppliances];  // Allocate memory for appliance pointers
}

// Parameterized constructor - creates a House object with space for numAppliances appliances
House::House(int numAppliances) {
    maxAppliances = numAppliances;
    this->numAppliances = 0;  // No appliances initially
    appliances = new Appliance*[maxAppliances];  // Allocate memory for appliance pointers
}

// Destructor - deallocates memory for the appliance pointers
House::~House() {
    // Free memory for each appliance
    for (int i = 0; i < numAppliances; i++) {
        delete appliances[i];
    }
    // Free memory for the array of pointers
    delete[] appliances;
}

// Add an Appliance object to the House
bool House::addAppliance(Appliance* appliance) {
    // Check if there's space in the house
    if (numAppliances < maxAppliances) {
        // Add the appliance to the array
        appliances[numAppliances] = appliance;
        numAppliances++;
        return true;
    } else {
        // No space left in the house
        return false;
    }
}

// Calculate total power consumption of all appliances in the House
double House::getTotalPowerConsumption() {
    double totalConsumption = 0.0;
    
    // Sum up power consumption of each appliance
    for (int i = 0; i < numAppliances; i++) {
        totalConsumption += appliances[i]->getPowerConsumption();
    }
    
    return totalConsumption;
}