#include "Player.h"
#include <iostream>
using namespace std;

Player::Player(string name, int health, int damage) {
    this->name = name;
    this->health = health;
    this->damage = damage;
}

void Player::attack(Player* opponent, int damge) {
    opponent->takeDamage(damage);
}

void Player::takeDamage(int damage) {
    health -= damage;
    if (health < 0) {
        health = 0;
    }
    cout << name << " takes " << damage << " damage. Remaining health: " << health << "\n";
}

string Player::getName() {
    return name;
}

int Player::getHealth() {
    return health;
}

int Player::getDamage() {
    return damage;
}

int Player::setHealth(int health) {
    this->health = health;
}

string Player::setName(string name) {
    this->name = name;
} 

int Player::setDamage(int damage) {
    this->damage = damage;
}