#include "Musician.h"
using namespace std;

Musician::Musician() {
    instrument = "null";
    experience = 0;
}

Musician::Musician(string instrument, int experience) {
    this ->instrument = instrument;
    this ->experience = experience;
}

string Musician::get_instrument() {
    return instrument;
}

int Musician::get_experience() {
    return experience;
}
