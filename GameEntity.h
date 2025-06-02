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
            case 'E':
            this->type = ExplosionType;
            break;
            case 'M':
            this->type = MineType;
            break;
            case 'S':
            this->type = ShipType;
            break;
            default:
            type = NoneType;
            break;
        }
    }

    tuple<int, int> getPos() const {
        return position;
    }

    GameEntityType getType() const {
        return type;
    }

    void setPos(const std::tuple<int,int>& newPos) {
        position = newPos;
    }

    void setType(GameEntityType newType) {
        type = newType;
    }
};

#endif

