#ifndef EFFECT_H
#define EFFECT_H

#include "GameEntity.h"
using namespace std;

class Effect {
    public:
    virtual ~Effect() = default;
    virtual void apply(GameEntity& entity) = 0; 
};

#endif