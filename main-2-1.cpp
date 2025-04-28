#include <iostream>
#include "Fridge.h"

using namespace std;

int main() {
    cout << "Fridge Class Demonstration" << endl;
    cout << "--------------------------" << endl;
    
    // Create a fridge with default constructor
    Fridge defaultFridge;
    cout << "Default Fridge:" << endl;
    cout << "Power Rating: " << defaultFridge.get_PowerRating() << " W" << endl;
    cout << "Volume: " << defaultFridge.get_Volume() << " litres" << endl;
    cout << "Is On: " << (defaultFridge.get_isOn() ? "Yes" : "No") << endl;
    cout << "Power Consumption: " << defaultFridge.getPowerConsumption() << " Wh" << endl;
    
    // Create a fridge with parameterized constructor
    Fridge customFridge(150, 250.0);
    cout << "\nCustom Fridge:" << endl;
    cout << "Power Rating: " << customFridge.get_PowerRating() << " W" << endl;
    cout << "Volume: " << customFridge.get_Volume() << " litres" << endl;
    cout << "Is On: " << (customFridge.get_isOn() ? "Yes" : "No") << endl;
    
    // Test turning on
    cout << "\nTurning the custom fridge on..." << endl;
    customFridge.turnOn();
    cout << "Is On: " << (customFridge.get_isOn() ? "Yes" : "No") << endl;
    
    // Calculate power consumption
    cout << "\nPower Consumption: " << customFridge.getPowerConsumption() << " Wh" << endl;
    cout << "Calculation: " << customFridge.get_PowerRating() << " W * 24 h * (" 
         << customFridge.get_Volume() << " litres / 100) = " 
         << customFridge.getPowerConsumption() << " Wh" << endl;
    
    // Test modifying values
    cout << "\nChanging power rating to 200 W and volume to 300 litres..." << endl;
    customFridge.set_PowerRating(200);
    customFridge.set_Volume(300.0);
    cout << "New Power Rating: " << customFridge.get_PowerRating() << " W" << endl;
    cout << "New Volume: " << customFridge.get_Volume() << " litres" << endl;
    cout << "New Power Consumption: " << customFridge.getPowerConsumption() << " Wh" << endl;
    
    return 0;
}