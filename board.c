#include "board.h"
#include "utils.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


Board* createBoard(int width, int height, int citiesCount, char** citiesNames) {
    Board* bd = malloc(sizeof(Board));
    if(bd == NULL) exit(1);

    bd->width = width;
    bd->height = height;
    bd->citiesCount = citiesCount;

    bd->cities = malloc(sizeof(City*) * citiesCount);
    if(bd->cities == NULL) exit(1);

    bd->possiblePathsCount = factorial(citiesCount-1);

    bd->possiblePaths = malloc(sizeof(Path*) * bd->possiblePathsCount);
    if(bd->possiblePaths == NULL) exit(1);

    for (int i = 0; i < bd->possiblePathsCount; i++) {
        bd->possiblePaths[i] = createPath(bd->citiesCount);
    }

    bd->distanceMatrix = malloc(sizeof(int*) * citiesCount);
    if(bd->distanceMatrix == NULL) exit(1);

    for (int i = 0; i < citiesCount; i++) {
        bd->distanceMatrix[i] = malloc(sizeof(int) * citiesCount);
        if(bd->distanceMatrix[i] == NULL) exit(1);

        bd->cities[i] = malloc(sizeof(City*));
        if(bd->cities[i] == NULL) exit(1);

        bd->cities[i]->name = (char *)malloc(strlen(citiesNames[i]) + 1);

        strcpy(bd->cities[i]->name, citiesNames[i]);
    }

    return bd;
}

int getCityIndex(Board* bd, City* city) {
    for(int i = 0; i< bd->citiesCount; i++) {
        if(strcmp(bd->cities[i]->name, city->name)==0) return i;
    }
}

void destroyBoard(Board* bd) {
    //Libère les villes
    freeCityList(bd->cities, bd->citiesCount);

    //Libére les chemins possibles
    for (int i = 0; i < bd->possiblePathsCount; i++) {
        freePath(bd->possiblePaths[i]);
    }

    //Libère la liste des chemin possibles
    free(bd->possiblePaths);

    //Libère le tableau bidimensionel des distances
    for (int i=0; i<bd->citiesCount; i++) free(bd->distanceMatrix[i]);
    free(bd->distanceMatrix);

    //Libére l'objet Board
    free(bd);
}

void populateBoard(Board* bd) {
    // On itére citiesCount fois pour générer des coordonées aléatoire pour chaque ville
    srand(time(NULL));
    for(int i = 0; i < bd->citiesCount; i++){
        bool isInArray = true;
        Coords rd;
        while(isInArray) {
            //On génére des valeurs aléatoires x et y compises respectivment entre 0 et la largeur, 0 et la hauteur
            rd.x = rand() % bd->width;
            rd.y = rand() % bd->height;
            //On verifie que la valeur aléatoire ne soit pas déja dans la table
            for(int j = 0; j < bd->citiesCount; j++){
                //Si elle n'est pas déja dans la table on sort de la boucle
                if(!(bd->cities[j]->position.x == rd.x && bd->cities[j]->position.y == rd.y)) isInArray = false;
            }
        }
        //On assigne la coordonée aléatoirement généré à la ville séléctionnée
        bd->cities[i]->position = rd; 
    }
    //Algorithme de tri des villes
    for (int i = 0; i<= bd->citiesCount-1; i++){
        for(int j = 0; j < bd->citiesCount - i - 1; j++) {
            if (bd->cities[j]->position.y > bd->cities[j+1]->position.y) {
                City* temp = bd->cities[j];
                bd->cities[j] = bd->cities[j+1];
                bd->cities[j+1] = temp;
            }
            else if (bd->cities[j]->position.y == bd->cities[j+1]->position.y) {
                if (bd->cities[j]->position.x > bd->cities[j+1]->position.x) {
                    City* temp = bd->cities[j];
                    bd->cities[j] = bd->cities[j+1];
                    bd->cities[j+1] = temp;
                }
            }
        }
    }
}

void displayBoard(Board* bd) {
    int count = 0;
    for(int y = 0; y <= bd->height + 1; y++) {
        for(int x = 0; x <= bd->width + 1; x++) {
            if(y==0 || y == bd->height+1) {
                printf("-");
            }
            else if(x==0 || x==bd->width+1) printf("|"); 
            else{
                if(count < bd->citiesCount && bd->cities[count]->position.x+1 == x && bd->cities[count]->position.y+1 == y){
                    printf("X");
                    count++;
                }
                else printf(" ");
            }
        }
        printf("\n");
    }
}

void displayPath(Board* bd,Path* path) {
    int count = 0;
    for(int y = 0; y <= bd->height + 1; y++) {
        for(int x = 0; x <= bd->width + 1; x++) {
            if(y==0 || y == bd->height+1) {
                printf("-");
            }
            else if(x==0 || x==bd->width+1) printf("|"); 
            else{
                if(count < bd->citiesCount && bd->cities[count]->position.x+1 == x && bd->cities[count]->position.y+1 == y){
                    int index =0;
                    for(int i=0;i<bd->citiesCount;i++){
                        if(strcmp(path->pathCitiesOrder[i]->name,bd->cities[count]->name)==0){
                            index = i;
                        }
                    }
                    printf("%d", index);
                    count++;
                }
                else {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
}

void generateDistanceMatrix(Board* bd){
    Coords origin = {0,0}; 
    for(int i=0;i<bd->citiesCount;i++){
        for(int j=i;j<bd->citiesCount;j++){
            if(i==j){
                bd->distanceMatrix[i][j] = distanceCoord(&bd->cities[i]->position, &origin);
                continue;
            }
            bd->distanceMatrix[i][j] = distanceCity(bd->cities[i], bd->cities[j]);
            bd->distanceMatrix[j][i] = bd->distanceMatrix[i][j];
        }
    }
}

City* getCity(Board* bd, char* name) {
    for (int i = 0; i < bd->citiesCount; i++)
    {
        if(strcmp(bd->cities[i]->name,name) == 0) return bd->cities[i];
    }
    return NULL;
} 

void generatePossiblePaths(Board* bd) {
    Path* path = createPath(bd->citiesCount);
    City** newCitiesLeft = cloneCityList(bd->cities, bd->citiesCount);
    generatePath(bd, bd->cities[0], path, removeCity(newCitiesLeft, 0, bd->citiesCount), bd->citiesCount-1, 0, bd->citiesCount, 1);
    free(newCitiesLeft);
}

void generatePath(Board* bd, City* currentCity, Path* previousPath, City** citiesLeft, int citiesLeftCount, int previousDivergence, int maxDepth, int depth) {
    previousPath->pathCitiesOrder[depth-1] = currentCity;
    if(citiesLeftCount == 0) {
        bd->possiblePaths[previousDivergence] = clonePath(previousPath, bd->citiesCount);
        free(citiesLeft);
        freePath(previousPath);
        return;
    }

    for (int i = 0; i < citiesLeftCount; i++) {
        int divergence = factorial(maxDepth - (depth + 1)) * i + previousDivergence;
        City** newCitiesLeft = cloneCityList(citiesLeft, citiesLeftCount);
        generatePath(bd, getCity(bd, citiesLeft[i]->name), clonePath(previousPath, bd->citiesCount), removeCity(newCitiesLeft, i, citiesLeftCount), citiesLeftCount-1, divergence ,maxDepth , depth+1);
        free(newCitiesLeft);
    }
    free(citiesLeft);
    freePath(previousPath);
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