#include "include/utils.h"
#include "include/board.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    Board* bd = createBoard(50,20,8, (char*[]){"Lille", "Paris", "Montcuq", "Grenoble", "Amiens", "Saint-Dié", "Dijon", "Toulouse"});

    populateBoard(bd);

    displayBoard(bd);

    generateDistanceMatrix(bd);

    // printFloatMatrix(bd->distanceMatrix, bd->citiesCount, bd->citiesCount);

    generatePossiblePaths(bd);

    calculateAllPathsDistances(bd);

    displayPath(bd,getOptimisedRoute(bd));

    destroyBoard(bd);
    return 0;
}