#include "Fridge.h"

Fridge::Fridge() : Appliance() {
    volume = 0.0;
}

Fridge::Fridge(int powerRating, double volume) : Appliance(powerRating) {
    this->volume = volume;
}

double Fridge::getVolume() const {
    return volume;
}

void Fridge::setVolume(double volume) {
    this->volume = volume;
}

double Fridge::getPowerConsumption() const {
    return getPowerRating() * 24 * (volume / 100);
}
