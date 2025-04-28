#include "TV.h"

using namespace std;

TV::TV() : Appliance() {
    screenSize = 0.0;
}

TV::TV(int powerRating, double screenSize) : Appliance(powerRating) {
    this->screenSize = screenSize;
}

void TV::set_ScreenSize(double screenSize) {
    this->screenSize = screenSize;
}

double TV::get_ScreenSize() const {
    return screenSize;
}

double TV::getPowerConsumption() const {
    return get_PowerRating() * (screenSize / 10);
}