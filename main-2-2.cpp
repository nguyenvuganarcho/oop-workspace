#include <iostream>
#include "TV.h"

using namespace std;

int main() {
    cout << "TV Class Demonstration" << endl;
    cout << "---------------------" << endl;
    
    // Create a TV with default constructor
    TV defaultTV;
    cout << "Default TV:" << endl;
    cout << "Power Rating: " << defaultTV.getPowerRating() << " W" << endl;
    cout << "Screen Size: " << defaultTV.getScreenSize() << " inches" << endl;
    cout << "Is On: " << (defaultTV.getIsOn() ? "Yes" : "No") << endl;
    cout << "Power Consumption: " << defaultTV.getPowerConsumption() << " W" << endl;
    
    // Create a TV with parameterized constructor
    TV customTV(100, 55.0);
    cout << "\nCustom TV:" << endl;
    cout << "Power Rating: " << customTV.getPowerRating() << " W" << endl;
    cout << "Screen Size: " << customTV.getScreenSize() << " inches" << endl;
    cout << "Is On: " << (customTV.getIsOn() ? "Yes" : "No") << endl;
    
    // Test turning on
    cout << "\nTurning the TV on..." << endl;
    customTV.turnOn();
    cout << "Is On: " << (customTV.getIsOn() ? "Yes" : "No") << endl;
    
    // Calculate power consumption
    cout << "\nPower Consumption: " << customTV.getPowerConsumption() << " W" << endl;
    
    // Test modifying values
    cout << "\nChanging power rating to 150 W and screen size to 65 inches..." << endl;
    customTV.setPowerRating(150);
    customTV.setScreenSize(65.0);
    cout << "New Power Rating: " << customTV.getPowerRating() << " W" << endl;
    cout << "New Screen Size: " << customTV.getScreenSize() << " inches" << endl;
    cout << "New Power Consumption: " << customTV.getPowerConsumption() << " W" << endl;
    
    return 0;
}