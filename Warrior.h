#ifndef WARRIOR_H
#define WARRIOR_H

#include "Player.h"
using namespace std;

class Warrior : public Player {
    private:
        string weapon;
    public:
    Warrior(string name, int health, int damage, string weapon);
    void swingWeapon(Player* opponent);
    string getWeapon();
    void setWeapon(string weapon);
};

#endif