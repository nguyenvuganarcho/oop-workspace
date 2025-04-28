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


int Appliance::get_PowerRating() const {
    return powerRating;
}

void Appliance::set_PowerRating(int powerRating) {
    this->powerRating = powerRating;
}

bool Appliance::get_isOn() const {
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
