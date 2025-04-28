#ifndef APPLIANCE_H
#define APPLIANCE_H

using namespace std;

class Appliance {
private:
    int powerRating;
    bool isOn;

public:
    // Constructors
    Appliance();
    Appliance(int powerRating);
    
    // Getters and setters
    int get_PowerRating() const;
    void set_PowerRating(int powerRating);
    bool get_isOn() const;
    
    // Methods
    void turnOn();
    void turnOff();
    virtual double getPowerConsumption() const;
};

#endif // APPLIANCE_H