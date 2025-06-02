#ifndef MINE_H
#define MINE_H

#include <tuple>

#include "GameEntity.h"
#include "Explosion.h"


class Mine : public GameEntity {
public:

    Mine(int x, int y) : GameEntity(x, y, 'm') {}

    Explosion explode() {
       tuple<int,int> pos = getPos();
       int mx = get<0>(pos);
       int my = get<1>(pos);

       Explosion e(mx, my);

       setType(NoneType);
       return e;
    }
};

#endif 
