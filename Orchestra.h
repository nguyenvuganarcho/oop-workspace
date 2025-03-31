#ifndef ORCHESTRA_H
#define ORCHESTRA_H

#include "Musician.h"

class Orchestra {
    private:
        int max_size;
        int current_num_members;
        Musician* members;
    public:
    Orchestra();
    Orchestra(int size);
    int get_current_number_of_members();
    bool has_instrument(string instrument);
    Musician* get_members();
    bool add_musician(Musician new_musician);
    ~Orchestra();
};

#endif