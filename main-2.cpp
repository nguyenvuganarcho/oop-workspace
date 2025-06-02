// main-2.cpp
#include <iostream>
#include <tuple>
#include "Ship.h"
#include "Mine.h"
#include "Explosion.h"

int main() {
    // 1) Create a Ship at (5, 5)
    Ship myShip(5, 5);
    std::cout << "Initial Ship position: ("
              << std::get<0>(myShip.getPos()) << ", "
              << std::get<1>(myShip.getPos()) << ")\n";
    std::cout << "Initial Ship type: " << myShip.getType()
              << "  (expect ShipType = 3)\n\n";

    // 2) Move the ship by (+3, -2)
    myShip.move(3, -2);
    std::cout << "After moving by (+3, -2), Ship position: ("
              << std::get<0>(myShip.getPos()) << ", "
              << std::get<1>(myShip.getPos()) << ")\n";
    std::cout << "After move, Ship type is still: " << myShip.getType() << "\n\n";

    // 3) Create a Mine at (4, 7)
    Mine myMine(4, 7);
    std::cout << "Mine position: ("
              << std::get<0>(myMine.getPos()) << ", "
              << std::get<1>(myMine.getPos()) << ")\n";
    std::cout << "Mine type: " << myMine.getType() << "  (expect MineType = 1)\n\n";

    // 4) Explode the mine
    Explosion e = myMine.explode();
    std::cout << "After explode():\n";
    std::cout << "  Returned Explosion position: ("
              << std::get<0>(e.getPos()) << ", "
              << std::get<1>(e.getPos()) << ")\n";
    std::cout << "  Explosion type: " << e.getType() << "  (expect ExplosionType = 0)\n";
    std::cout << "  Original Mine’s type now: " << myMine.getType()
              << "  (expect NoneType = 2)\n\n";

    // 5) Create another Ship at (10, 10) and apply the explosion to it
    Ship targetShip(10, 10);
    std::cout << "Target Ship before apply: position ("
              << std::get<0>(targetShip.getPos()) << ", "
              << std::get<1>(targetShip.getPos()) << "), type = "
              << targetShip.getType() << " (ShipType = 3)\n";

    // Apply the explosion’s effect onto targetShip
    e.apply(targetShip);

    std::cout << "Target Ship after apply: position ("
              << std::get<0>(targetShip.getPos()) << ", "
              << std::get<1>(targetShip.getPos()) << "), type = "
              << targetShip.getType() << " (expect NoneType = 2)\n";

    return 0;
}
