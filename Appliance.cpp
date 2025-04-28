#include "Appliance.h"

using namespace std;

Appliance::Appliance() {
    powerRating = 0;
    isOn = false;
}


Appliance::Appliance(int powerRating) {
    this->powerRating = powerRating;
    isOn = false;
}


int Appliance::getPowerRating() const {
    return powerRating;
}

void Appliance::setPowerRating(int powerRating) {
    this->powerRating = powerRating;
}

bool Appliance::getIsOn() const {
    return isOn;
}

void Appliance::turnOn() {
    isOn = true;
}

void Appliance::turnOff() {
    isOn = false;
}

double Appliance::getPowerConsumption() const {
    return 0.0;
}
