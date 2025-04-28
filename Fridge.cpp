#include "Fridge.h"

Fridge::Fridge() : Appliance() {
    volume = 0.0;
}

Fridge::Fridge(int powerRating, double volume) : Appliance(powerRating) {
    this->volume = volume;
}

double Fridge::get_Volume() const {
    return volume;
}

void Fridge::set_Volume(double volume) {
    this->volume = volume;
}

double Fridge::getPowerConsumption() const {
    return get_powerRating() * 24 * (volume / 100);
}
