#ifndef FRIDGE_H
#define FRIDGE_H

#include "Appliance.h"

class Fridge : public Appliance {
    private:
    double volume;

    public:
    Fridge();
    Fridge(int powerRating, double volume);

    // Getters and Setters
    double get_Volume() const;
    void set_Volume(double volume);

    // Overriding the pure virtual function from Appliance
    double getPowerConsumption() const override;

};

#endif // FRIDGE_H