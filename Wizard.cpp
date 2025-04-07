#include "Wizard.h"
#include <iostream>
using namespace std;

Wizard::Wizard(string name, int health, int damage, int mana) : Player(name, health, damage), mana(mana) {}

void Wizard::castSpell(Player* opponent) {
    cout << name << " casts a spell on " << opponent->getName() << " for " << damage << " damage.\n";
    opponent->takeDamage(mana);
}

int Wizard::getMana() {
    return mana;
}

int Wizard::setMana(int mana) {
    this->mana = mana;
}
