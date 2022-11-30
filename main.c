#include "utils.h"
#include "board.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void printMatrix(float** tab, int size) {
    for(int i = 0; i < size; i++) {
        printf("[ ");
        for(int j = 0; j < size; j++) {
            printf("%f, ", tab[i][j]);
        }
        printf(" ]\n");
    }
    
}

void printPathMatrix(Path* tab, int size) {
    for(int i = 0; i < calculatePossibilitiesCount(size); i++) {
        printf("[ ");
        for(int j = 0; j < size; j++) {
            printf("%s, ", tab[i].pathCitiesOrder[j].name);
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

void removeElement(City* cities, int index, int size) {
    City newCities[size - 1];
    int offset = 0;
    for(int i; i<size - 1; i++) {
        if(i==index) offset++;
        newCities[i] = cities[i + offset];
    }

    for(int i; i<size; i++) {
        cities[i] = newCities[i];
    }
}

// void possibilites(City cities[], int nbr, Path path[], int pathIndex) {
//     for(int i = 0; i<nbr; i++) {
//         if(nbr==0) {
//             return path;
//         }
//         if(nbr != 4) {
//             path->totalDistance+=distanceCity(cities[i], path->pathCitiesOrder[4 - nbr - 1]);
//         }
//         path[pathIndex].pathCitiesOrder[4 - nbr] = cities[i];
//         possibilites(removeElement(cities, i, nbr), nbr-1, path, pathIndex);
//         pathIndex++;
//     }
// }


// Path* calculatePossibilities(City cities[], int citiesCount, Path* pathList, int pathIndex) {
//     if(citiesCount == 0 ) {
//         return pathList;
//     }
//     for(int i = 1; i <= citiesCount; i++) {  
//         //i -> current city index
//         //Enleve la ville courrante des villes restantes
//         City citiesLeft[citiesCount - 1];
//         int offset = 0;
//         for(int j = 0; j<citiesCount; j++) {
//             if(j==i-1) offset++;
//             citiesLeft[j] = cities[j + offset];
//         }

//         pathList[pathIndex].pathCitiesOrder[i-1] = cities[i-1];
//         printCitiesMatrix(cities, citiesCount);
//         return calculatePossibilities(citiesLeft, citiesCount-1, pathList, pathIndex + citiesCount * i);
//     }
// }

// Path* calculatePossibilities(City* cities) {
    
// }


int main() {
    // Production Board
    // Board* bd = createBoard(50,20,8, (char*[]){"Lille", "Paris", "Montcuq", "Grenbole", "Amiens", "Saint-Dié", "Dijon", "Toulouse"});

    Board* bd = createBoard(50,20,4, (char*[]){"Lille", "Paris", "Montcuq", "Grenbole"});

    populateBoard(bd);

    displayBoard(bd);

    generateDistanceMatrix(bd);

    // Printing all cities x and y coords DEBUG ONLY
    // for(int i = 0; i < bd->citiesCount; i++) {
    //     printf("%s\n | x: %d\n | y: %d\n", bd->cities[i]->name, bd->cities[i]->position.x, bd->cities[i]->position.y);
    // }

    freeBoard(bd);
    return 0;
}