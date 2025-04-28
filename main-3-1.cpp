#include <iostream>
#include "House.h"
#include "Fridge.h"
#include "TV.h"

using namespace std;

int main() {
    cout << "House Class Demonstration" << endl;
    cout << "------------------------" << endl;
    
    // Create a house with the default constructor (capacity of 10)
    House myHouse;
    
    cout << "Initial power consumption: " << myHouse.getTotalPowerConsumption() << " W" << endl;
    
    // Create some appliances to add to the house
    Appliance* genericAppliance = new Appliance(100);
    Fridge* fridge = new Fridge(150, 250.0);
    TV* tv = new TV(200, 55.0);
    
    // Turn on the appliances
    genericAppliance->turnOn();
    fridge->turnOn();
    tv->turnOn();
    
    // Add appliances to the house
    cout << "\nAdding appliances to the house..." << endl;
    
    if (myHouse.addAppliance(genericAppliance)) {
        cout << "Generic Appliance added successfully!" << endl;
    } else {
        cout << "Failed to add Generic Appliance!" << endl;
    }
    
    if (myHouse.addAppliance(fridge)) {
        cout << "Fridge added successfully!" << endl;
    } else {
        cout << "Failed to add Fridge!" << endl;
    }
    
    if (myHouse.addAppliance(tv)) {
        cout << "TV added successfully!" << endl;
    } else {
        cout << "Failed to add TV!" << endl;
    }
    
    // Calculate total power consumption
    cout << "\nTotal power consumption after adding appliances: " 
         << myHouse.getTotalPowerConsumption() << " W" << endl;
    
    // Create a house with limited capacity
    cout << "\nCreating a house with limited capacity (1)..." << endl;
    House smallHouse(1);
    
    // Try to add multiple appliances to the small house
    Appliance* anotherAppliance = new Appliance(50);
    
    if (smallHouse.addAppliance(anotherAppliance)) {
        cout << "First appliance added to small house!" << endl;
    } else {
        cout << "Failed to add first appliance to small house!" << endl;
        delete anotherAppliance;  // Clean up if not added
    }
    
    Appliance* oneMoreAppliance = new Appliance(75);
    
    if (smallHouse.addAppliance(oneMoreAppliance)) {
        cout << "Second appliance added to small house!" << endl;
    } else {
        cout << "Failed to add second appliance to small house!" << endl;
        delete oneMoreAppliance;  // Clean up if not added
    }
    
    // Note: no need to delete the appliances added to the houses
    // as the House destructor will take care of them
    
    return 0;
}