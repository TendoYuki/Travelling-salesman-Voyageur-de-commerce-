#include "utils.h"
#include "board.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void printMatrix(float** tab, int sizeX, int sizeY) {
    for(int i = 0; i < sizeY; i++) {
        printf("\n[ ");
        for(int j = 0; j < sizeX; j++) {
            printf("%f, ", tab[i][j]);
        }
        printf(" ]\n");
    }
    
}

void printPathMatrix(Board* bd) {
    for(int i = 0; i < bd->possiblePathsCount; i++) {
        printf("[ ");
        for(int j = 0; j < bd->citiesCount; j++) {
            printf("%s, ", bd->possiblePaths[i]->pathCitiesOrder[j]->name);
        }
        printf(" ]\n");
    }
    
}

void printCitiesMatrix(City* tab, int size) {
    for(int i = 0; i < size; i++) {
        printf("[ ");
        printf("%s, ", tab[i].name);
        printf(" ]\n");
    }
    
}


void generatePath(Board* bd, City* currentCity, Path* previousPath, City** citiesLeft, int citiesLeftCount, int previousDivergence, int maxDepth, int depth) {
    previousPath->pathCitiesOrder[depth-1] = currentCity;
    if(citiesLeftCount == 0) {
        bd->possiblePaths[previousDivergence] = clonePath(previousPath, bd->citiesCount);
        free(citiesLeft);
        freePath(previousPath, bd->citiesCount);
        return;
    }

    for (int i = 0; i < citiesLeftCount; i++) {
        int divergence = factorial(maxDepth - (depth + 1)) * i + previousDivergence;
        City** newCitiesLeft = copyCityList(citiesLeft, citiesLeftCount);
        generatePath(bd, getCity(bd, citiesLeft[i]->name), clonePath(previousPath, bd->citiesCount), removeCity(newCitiesLeft, i, citiesLeftCount), citiesLeftCount-1, divergence ,maxDepth , depth+1);
        free(newCitiesLeft);
    }
    free(citiesLeft);
    freePath(previousPath, bd->citiesCount);
}

void generatePossiblePaths(Board* bd) {
    Path* path = createPath(bd->citiesCount);
    City** newCitiesLeft = copyCityList(bd->cities, bd->citiesCount);
    generatePath(bd, bd->cities[0], path, removeCity(newCitiesLeft, 0, bd->citiesCount), bd->citiesCount-1, 0, bd->citiesCount, 1);
    free(newCitiesLeft);
}

void calculatePathDistance(Board* bd, Path* path) {
    float dist = 0;
    for(int i=0; i<bd->citiesCount; i++) {
        if (i == bd->citiesCount-1) {
            dist += bd->distanceMatrix[getCityIndex(bd, path->pathCitiesOrder[i])][getCityIndex(bd, path->pathCitiesOrder[0])];
        } 
        else {
            dist += bd->distanceMatrix[getCityIndex(bd, path->pathCitiesOrder[i])][getCityIndex(bd, path->pathCitiesOrder[i+1])];
        }
    }
    path->totalDistance = dist;
} 

void calculateAllPathsDistances(Board* bd){
    for(int i =0;i < bd->possiblePathsCount;i++){
        calculatePathDistance(bd,bd->possiblePaths[i]);
    }
}

Path* getOptimisedRoute(Board* bd){
    Path* path = bd->possiblePaths[0];
    for(int i =1;i < bd->possiblePathsCount;i++){
        if (path->totalDistance > bd->possiblePaths[i]->totalDistance){
            path = bd->possiblePaths[i];
        }
    }
    return path;
}

int main() {
    // Production Board
    // Board* bd = createBoard(50,20,8, (char*[]){"Lille", "Paris", "Montcuq", "Grenoble", "Amiens", "Saint-Dié", "Dijon", "Toulouse"});

    Board* bd = createBoard(50,20,8, (char*[]){"Lille", "Paris", "Montcuq", "Grenoble", "Amiens", "Saint-Dié", "Dijon", "Toulouse"}); // Debug line

    populateBoard(bd);

    displayBoard(bd);

    generateDistanceMatrix(bd);
    // for(int i = 0; i < bd->citiesCount; i++) {
    //     printf("%s\n | x: %d\n | y: %d\n", bd->cities[i]->name, bd->cities[i]->position.x, bd->cities[i]->position.y);
    // }
    generatePossiblePaths(bd);

    calculateAllPathsDistances(bd);

    Path* path = getOptimisedRoute(bd);
    displayOptimisedRoute(bd,path);
    destroyBoard(bd);
    return 0;
}