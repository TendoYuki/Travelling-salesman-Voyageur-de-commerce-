#include "board.h"
#include "utils.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char * citiesNames[] = {"Lille", "Paris", "Montcuq", "Grenbole", "Amiens", "Saint-Dié", "Dijon", "Toulouse"};

void displayBoard(Board bd) {
    int count = 0;
    for(int y = 0; y <= bd.height + 1; y++) {
        for(int x = 0; x <= bd.width + 1; x++) {
            if(y==0 || y == bd.height+1) {
                printf("-");
            }
            else if(x==0 || x==bd.width+1) {
                printf("|");
            }
            else{
                if(bd.cities[count].position.x+1 == x && bd.cities[count].position.y+1 == y){
                    printf("X");
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

City getCity(Board bd, char* name) {
    int size = sizeof(bd.cities) / sizeof(bd.cities[0]);
    for (int i = 0; i < size; i++)
    {
        if(strcmp(bd.cities[i].name,name) == 0) {
            return bd.cities[i];
        }
    }
    
} 

Board populateBoard(Board bd) {
    srand(time(NULL));
    int i = 0;
    int size = sizeof(bd.cities) / sizeof(bd.cities[0]);

    /* On itére size fois pour mettre une valeur
    on verifie que la valeur aléatoire ne soit pas déja dans la table
    si elle y est on en génére une nouvelle
    sinon on l'ajoute*/

    for(int i = 0; i < size; i++){
        bool isInArray = true;
        Coords rd;
        while(isInArray) {
            rd.x = rand() % 50;
            rd.y = rand() % 20;
            for(int j = 0; j < size; j++){
                if(!(bd.cities[j].position.x == rd.x && bd.cities[j].position.y == rd.y)){
                    isInArray = false;
                }
            }
        }
        City ct;
        ct.name = citiesNames[i];
        ct.position  = rd;
        bd.cities[i] = ct; 
    }
    //Algorithme de tri à bulle
    for (int i = 0; i<=size-1; i++){
        for(int j = 0; j < size - i - 1; j++) {
            if (bd.cities[j].position.y > bd.cities[j+1].position.y) {
                City temp = bd.cities[j];
                bd.cities[j] = bd.cities[j+1];
                bd.cities[j+1] = temp;
            }
            else if (bd.cities[j].position.y == bd.cities[j+1].position.y) {
                if (bd.cities[j].position.x > bd.cities[j+1].position.x) {
                    City temp = bd.cities[j];
                    bd.cities[j] = bd.cities[j+1];
                    bd.cities[j+1] = temp;
                }
            }
        }
    }
    return bd;
}