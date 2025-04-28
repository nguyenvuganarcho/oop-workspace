#include <iostream>
#include "TV.h"

using namespace std;

int main() {
    cout << "TV Class Demonstration" << endl;
    cout << "---------------------" << endl;
    
    // Create a TV with default constructor
    TV defaultTV;
    cout << "Default TV:" << endl;
    cout << "Power Rating: " << defaultTV.get_PowerRating() << " W" << endl;
    cout << "Screen Size: " << defaultTV.get_ScreenSize() << " inches" << endl;
    cout << "Is On: " << (defaultTV.get_isOn() ? "Yes" : "No") << endl;
    cout << "Power Consumption: " << defaultTV.getPowerConsumption() << " W" << endl;
    
    // Create a TV with parameterized constructor
    TV customTV(100, 55.0);
    cout << "\nCustom TV:" << endl;
    cout << "Power Rating: " << customTV.get_PowerRating() << " W" << endl;
    cout << "Screen Size: " << customTV.get_ScreenSize() << " inches" << endl;
    cout << "Is On: " << (customTV.get_isOn() ? "Yes" : "No") << endl;
    
    // Test turning on
    cout << "\nTurning the TV on..." << endl;
    customTV.turnOn();
    cout << "Is On: " << (customTV.get_isOn() ? "Yes" : "No") << endl;
    
    // Calculate power consumption
    cout << "\nPower Consumption: " << customTV.getPowerConsumption() << " W" << endl;
    
    // Test modifying values
    cout << "\nChanging power rating to 150 W and screen size to 65 inches..." << endl;
    customTV.set_PowerRating(150);
    customTV.set_ScreenSize(65.0);
    cout << "New Power Rating: " << customTV.get_PowerRating() << " W" << endl;
    cout << "New Screen Size: " << customTV.get_ScreenSize() << " inches" << endl;
    cout << "New Power Consumption: " << customTV.getPowerConsumption() << " W" << endl;
    
    return 0;
}