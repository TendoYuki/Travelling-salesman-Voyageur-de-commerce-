#include "utils.h"
#include "board.h"
#include <stdio.h>

int main() {
    Coords a = {1,2};
    Coords b = {5,3};
    Board bd = {50, 20};
    bd = populateBoard(bd);
    displayBoard(bd);
    for(int i = 0; i < 8; i++) {
        printf("%s | x: %d y: %d\n", bd.cities[i].name, bd.cities[i].position.x, bd.cities[i].position.y);
    }
    printf("dist : %f\n",distanceCity(getCity(bd,"Saint-Dié"), getCity(bd,"Amiens")));
    return 0;
}