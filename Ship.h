#ifndef SHIP_H
#define SHIP_H

#include <tuple>

#include "GameEntity.h"

class Ship : public GameEntity {
    public:
    Ship(int x, int y) : GameEntity(x, y, 'S') {}

    void move(int dx, int dy) {
        tuple<int, int> pos = getPos();
        int currentX = get<0>(pos);
        int currentY = get<1>(pos);

        tuple<int,int> newPos = make_tuple(currentX + dx, currentY + dy);

        setPos(newPos);

    }
};

#endif