#include <iostream>
#include "Utils.h"
#include <ctime>

using namespace std;

int main() {

    srand(static_cast<unsigned>(time(nullptr)));

    const int GRID_W = 20;
    const int GRID_H = 20;
    const int NUM_POS = 5;

 
    tuple<int,int> positions[NUM_POS];

    
    for (int i = 0; i < NUM_POS; ++i) {
        positions[i] = Utils::generateRandomPos(GRID_W, GRID_H);
    }


    cout << "Generated positions:\n";
    for (int i = 0; i < NUM_POS; ++i) {
        int x = get<0>(positions[i]);
        int y = get<1>(positions[i]);
        cout << "  [" << i << "] = (" << x << ", " << y << ")\n";
    }
    cout << endl;

  
    cout << "Distances between consecutive positions:\n";
    for (int i = 0; i < NUM_POS - 1; ++i) {
        double d = Utils::calculateDistance(positions[i], positions[i+1]);
        cout << "  dist( pos[" << i << "], pos[" << i+1 << "] ) = "
                  << d << "\n";
    }

   
    return 0;
}