#ifndef TV_H
#define TV_H

#include "Appliance.h"

class TV : public Appliance {
    private:
    double screenSize;

    public:
    TV();
    TV(int powerRating, double screenSize);

    // getters and setters
    void set_ScreenSize(double screenSize);
    double get_ScreenSize() const;

    // Overriding the pure virtual function from Appliance
    double getPowerConsumption() const override;
};

#endif // TV_H