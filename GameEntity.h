#ifndef GAMEENTITY_H
#define GAMEENTITY_H

#include <tuple>

using namespace std;

enum GameEntityType {
    ExplosionType,
    MineType,
    NoneType,
    ShipType
};

class GameEntity {
    private:
        tuple<int, int> position;
        GameEntityType type;
    public:
    GameEntity(int x, int y, char type) 
    : position(make_tuple(x, y)),
    type(NoneType) {
        switch (type) {
            case 'e':
            type = ExplosionType;
            break;
            case 'm':
            type = MineType;
            break;
            case 's':
            type = ShipType;
            break;
            default:
            type = NoneType;
            break;
        }
    }

    tuple<int, int> getPos() {
        return position;
    }

    GameEntityType getType() {
        return type;
    }

    void setPos(const std::tuple<int,int>& newPos) {
        position = newPos;
    }

    // Setter for type
    void setType(GameEntityType newType) {
        type = newType;
    }
};

#endif

