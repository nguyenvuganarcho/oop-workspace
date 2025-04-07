#ifndef WIZARD_H
#define WIZARD_H

#include "Player.h"
using namespace std;

class Wizard : public Player {
    private:
        int mana;
    public:
    Wizard(string name, int health, int damage, int mana);
    void castSpell(Player* opponent);
    int getMana();
    int setMana(int mana);
};

#endif