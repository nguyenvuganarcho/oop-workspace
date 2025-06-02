#ifndef UTIlS_H
#define UTILS_H

#include "GameEntity.h"
#include <tuple>
#include <cstdlib>
#include <cmath>

using namespace std;

class Utils {
    public:
    static tuple<int, int> generateRandomPos(int gridWidth, int gridHeight) {
        int x = rand() % gridWidth;
        int y = rand() % gridHeight;
        return make_tuple(x, y);
    }

    static double calculateDistance(tuple<int, int> pos1, tuple<int, int> pos2) {
        int x1 = get<0>(pos1);
        int y1 = get<1>(pos1);
        int x2 = get<0>(pos2);
        int y2 = get<1>(pos2);

        double dx = static_cast<double>(x1 - x2);
        double dy = static_cast<double>(y1 - y2);

        return sqrt(dx*dx + dy*dy);
    }
};

#endif