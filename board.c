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

    bd->cities = malloc(sizeof(City) * citiesCount);
    if(bd->cities == NULL) exit(1);

    bd->distanceMatrix = malloc(sizeof(int*) * citiesCount);
    if(bd->distanceMatrix == NULL) exit(1);

    for (int i = 0; i < citiesCount; i++) {
        bd->distanceMatrix[i] = malloc(sizeof(int) * citiesCount);
        if(bd->distanceMatrix[i] == NULL) exit(1);

        bd->cities[i] = malloc(sizeof(City));
        if(bd->cities[i] == NULL) exit(1);

        bd->cities[i]->name = citiesNames[i];
    }
    return bd;
}

void freeBoard(Board* bd) {
    //Libère les villes
    for (int i=0; i<bd->citiesCount; i++) free(bd->cities[i]);
    free(bd->cities);

    //Libère le tableau bidimensionel des distances
    for (int i=0; i<bd->citiesCount; i++) free(bd->distanceMatrix[i]);
    free(bd->distanceMatrix);

    //Libére l'objet Board
    free(bd);
}

void populateBoard(Board* bd) {
    /* On itére citiesCount fois pour mettre une valeur
    on verifie que la valeur aléatoire ne soit pas déja dans la table
    si elle y est on en génére une nouvelle
    sinon on l'ajoute*/

    srand(time(NULL));
    for(int i = 0; i < bd->citiesCount; i++){
        bool isInArray = true;
        Coords rd;
        while(isInArray) {
            rd.x = rand() % 50;
            rd.y = rand() % 20;
            for(int j = 0; j < bd->citiesCount; j++){
                if(!(bd->cities[j]->position.x == rd.x && bd->cities[j]->position.y == rd.y)) isInArray = false;
            }
        }
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

void generateDistanceMatrix(Board* bd){
    Coords origin = {0,0}; 
    for(int i=0;i<bd->citiesCount;i++){
        for(int j=i;j<bd->citiesCount;j++){
            if(i==j){
                bd->distanceMatrix[i][j] = distanceCoord(bd->cities[i]->position, origin);
                continue;
            }
            bd->distanceMatrix[i][j] = distanceCity(bd->cities[i], bd->cities[j]);
            bd->distanceMatrix[j][i] = bd->distanceMatrix[i][j];
        }
    }
}

City* getCity(Board* bd, char* name) {
    int size = sizeof(bd->cities) / sizeof(bd->cities[0]);
    for (int i = 0; i < size; i++)
    {
        if(strcmp(bd->cities[i]->name,name) == 0) return bd->cities[i];
    }
    return NULL;
} 

