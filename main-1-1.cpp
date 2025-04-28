#include <iostream>
#include "Appliance.h"

using namespace std;

int main() {
    // Create an appliance with default constructor
    Appliance defaultAppliance;
    cout << "Default Appliance:" << endl;
    cout << "Power Rating: " << defaultAppliance.getPowerRating() << endl;
    cout << "Is On: " << (defaultAppliance.getIsOn() ? "Yes" : "No") << endl;
    
    // Create an appliance with parameterized constructor
    Appliance customAppliance(1500);
    cout << "\nCustom Appliance:" << endl;
    cout << "Power Rating: " << customAppliance.getPowerRating() << endl;
    cout << "Is On: " << (customAppliance.getIsOn() ? "Yes" : "No") << endl;
    
    // Test turning on and off
    cout << "\nTurning the custom appliance on..." << endl;
    customAppliance.turnOn();
    cout << "Is On: " << (customAppliance.getIsOn() ? "Yes" : "No") << endl;
    
    cout << "\nTurning the custom appliance off..." << endl;
    customAppliance.turnOff();
    cout << "Is On: " << (customAppliance.getIsOn() ? "Yes" : "No") << endl;
    
    // Test power consumption
    cout << "\nPower Consumption: " << customAppliance.getPowerConsumption() << endl;
    
    // Test setter
    cout << "\nChanging power rating to 2000..." << endl;
    customAppliance.setPowerRating(2000);
    cout << "New Power Rating: " << customAppliance.getPowerRating() << endl;
    
    return 0;
}