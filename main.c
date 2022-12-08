#include "include/utils.h"
#include "include/board.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    Board* bd = createBoard(50,20,8, (char*[]){"Lille", "Paris", "Montcuq", "Grenoble", "Amiens", "Saint-Dié", "Dijon", "Toulouse"});

    populateBoard(bd);

    displayBoard(bd);

    generateDistanceMatrix(bd);

    printFloatMatrix(bd->distanceMatrix, bd->citiesCount, bd->citiesCount);

    generatePossiblePaths(bd);

    calculateAllPathsDistances(bd);

    // displayPath(bd,getOptimisedRoute(bd));

    // printf("%p\n",  );

    for(int i = 0; i < bd->citiesCount; i++) {
        printf("%s\n | x: %d\n | y: %d\n", bd->cities[i]->name, bd->cities[i]->position.x, bd->cities[i]->position.y);
    }


    Path* path = getOptimisedRouteByDistance(bd);
    displayPath(bd,path);
    displayPath(bd,getOptimisedRoute(bd));
    free(path);
    destroyBoard(bd);
    return 0;
}