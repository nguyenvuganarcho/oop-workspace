#include <iostream>
#include "Fridge.h"

using namespace std;

int main() {
    cout << "Fridge Class Demonstration" << endl;
    cout << "--------------------------" << endl;
    
    // Create a fridge with default constructor
    Fridge defaultFridge;
    cout << "Default Fridge:" << endl;
    cout << "Power Rating: " << defaultFridge.getPowerRating() << " W" << endl;
    cout << "Volume: " << defaultFridge.getVolume() << " litres" << endl;
    cout << "Is On: " << (defaultFridge.getIsOn() ? "Yes" : "No") << endl;
    cout << "Power Consumption: " << defaultFridge.getPowerConsumption() << " Wh" << endl;
    
    // Create a fridge with parameterized constructor
    Fridge customFridge(150, 250.0);
    cout << "\nCustom Fridge:" << endl;
    cout << "Power Rating: " << customFridge.getPowerRating() << " W" << endl;
    cout << "Volume: " << customFridge.getVolume() << " litres" << endl;
    cout << "Is On: " << (customFridge.getIsOn() ? "Yes" : "No") << endl;
    
    // Test turning on
    cout << "\nTurning the custom fridge on..." << endl;
    customFridge.turnOn();
    cout << "Is On: " << (customFridge.getIsOn() ? "Yes" : "No") << endl;
    
    // Calculate power consumption
    cout << "\nPower Consumption: " << customFridge.getPowerConsumption() << " Wh" << endl;
    cout << "Calculation: " << customFridge.getPowerRating() << " W * 24 h * (" 
         << customFridge.getVolume() << " litres / 100) = " 
         << customFridge.getPowerConsumption() << " Wh" << endl;
    
    // Test modifying values
    cout << "\nChanging power rating to 200 W and volume to 300 litres..." << endl;
    customFridge.setPowerRating(200);
    customFridge.setVolume(300.0);
    cout << "New Power Rating: " << customFridge.getPowerRating() << " W" << endl;
    cout << "New Volume: " << customFridge.getVolume() << " litres" << endl;
    cout << "New Power Consumption: " << customFridge.getPowerConsumption() << " Wh" << endl;
    
    return 0;
}