// main-3.cpp
#include <iostream>
#include <tuple>

#include "Game.h"

int main() {
    // 1) Create a Game instance
    Game g;

    // 2) Initialize with 3 Ships and 3 Mines on a 10×10 grid
    int numShips      = 3;
    int numMines      = 3;
    int gridWidth     = 10;
    int gridHeight    = 10;
    double threshold  = 2.5;   // distance threshold
    int maxIterations = 10;

    // Instead of: auto ents = g.initGame(...);
    vector<GameEntity*> ents = g.initGame(numShips, numMines, gridWidth, gridHeight);

    // Print initial entities
    cout << "Initial entities:\n";
    for (size_t i = 0; i < ents.size(); ++i) {
        GameEntity* ge = ents[i];
        tuple<int,int> pos = ge->getPos();
        int x = get<0>(pos);
        int y = get<1>(pos);

        GameEntityType t = ge->getType();
        cout << "  Type ";
        if (t == ShipType) {
            cout << "Ship";
        } else if (t == MineType) {
            cout << "Mine";
        } else if (t == ExplosionType) {
            cout << "Explosion";
        } else {
            cout << "None";
        }
        cout << " at (" << x << ", " << y << ")\n";
    }
    cout << "\n";

    // 3) Run the game loop
    cout << "Running game loop...\n";
    g.gameLoop(maxIterations, threshold);

    // 4) Cleanup: delete all pointers
    for (size_t i = 0; i < ents.size(); ++i) {
        delete ents[i];
    }

    return 0;
}
