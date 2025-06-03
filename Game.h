#ifndef GAME_H
#define GAME_H

#include <vector>
#include <iostream>

#include "GameEntity.h"
#include "Effect.h"
#include "Explosion.h"
#include "Mine.h"
#include "Ship.h"
#include "Utils.h"

using namespace std;

class Game {
    private:
    vector<GameEntity*> entities;
    public:
    Game() = default;
    
    vector<GameEntity*> initGame(int numShips, int numMines, int gridWidth, int gridHeight) {
        entities.clear();

        for (int i = 0; i < numShips; i++) {
            tuple<int,int> pos = Utils::generateRandomPos(gridWidth, gridHeight);
            int x = get<0>(pos);
            int y = get<1>(pos);

            Ship* s = new Ship(x, y);
            entities.push_back(s);
        }

        for (int i = 0; i < numMines; i++) {
            tuple<int, int> pos = Utils::generateRandomPos(gridWidth, gridHeight);
            int x = get<0>(pos);
            int y = get<1>(pos);

            Mine* m = new Mine(x, y);
            entities.push_back(m);
        }

        return entities;
    }

    vector<GameEntity*> get_entities() const {
        return entities;
    }

    void set_entities(const vector<GameEntity*>& ents) {
        entities = ents;
    }

    void gameLoop(int maxIterations, double mineDistanceThreshold) {
        for (int i = 0; i < maxIterations; i++) {
            for (GameEntity* ge : entities) {
                if (ge->getType() == ShipType) {
                    Ship* shipPtr = static_cast<Ship*>(ge);
                    shipPtr->move(1,0);
                }
            }

        vector<tuple<Ship*,Mine*>> collisions;
        for (GameEntity* ge1 : entities) {
            if (ge1->getType() != ShipType) continue;
            Ship* shipPtr = static_cast<Ship*>(ge1);

            for (GameEntity* ge2 : entities) {
                if (ge2->getType() != MineType) continue;
                Mine* minePtr = static_cast<Mine*>(ge2);

                tuple<int, int> shipPos = shipPtr->getPos();
                int sx = get<0>(shipPos);
                int sy = get<1>(shipPos);

                tuple<int, int> minePos =  minePtr->getPos();
                int mx = get<0>(minePos);
                int my = get<1>(minePos);

                double distance = Utils::calculateDistance(shipPos, minePos);
                if (distance <= mineDistanceThreshold) {
                    collisions.push_back(make_tuple(shipPtr, minePtr));
                }
            } 
        }

        for (size_t i = 0; i < collisions.size(); i++) {
            Ship* shipPtr = get<0>(collisions[i]);
            Mine* minePtr = get<1>(collisions[i]);

            Explosion e = minePtr->explode();
            e.apply(*shipPtr);
        }

        int shipRemain = 0;
        for (GameEntity* ge: entities) {
            if (ge->getType() == ShipType) {
                shipRemain++;
            } 
        }

        if (shipRemain == 0) {
            cout << "All ships destroyed at iteration " << i << ".\n";
            break;
        }

    }
}
    
    
};

#endif