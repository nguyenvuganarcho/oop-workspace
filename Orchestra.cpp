#include <iostream>
#include "Orchestra.h"
using namespace std;

Orchestra::Orchestra() {
    max_size = 0;
    current_num_members = 0;
    members = nullptr;
}

Orchestra::Orchestra(int size) {
    max_size = size;
    current_num_members = 0;
    members = new Musician[max_size];
}

int Orchestra::get_current_number_of_members() {
    return current_num_members;
}

bool Orchestra::has_instrument(string instrument) {
    for (int i = 0; i < current_num_members; i++) {
        if (members[i].get_instrument() == instrument) {
            return true;
        } else {
            return false;
        }
    }
}

Musician* Orchestra::get_members() {
    return members;
}

bool Orchestra::add_musician(Musician new_musician) {
    if (current_num_members < max_size) {
        members[current_num_members] = new_musician;
        current_num_members++;
        return true;
    }
    return false;
}

Orchestra:: ~Orchestra() {
    delete[] members;
}