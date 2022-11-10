#ifndef BOARD_H
#define BOARD_H
#include "utils.h"

/**
 * Type plateau contenant sa largeur, sa hauteur anisi que les huit villes qu'il contient.
*/
typedef struct {
    int width;
    int height;
    City cities[8];
} Board;

/**
 * Affiche un plateau donné avec les villes representées par des croix.
*/
void displayBoard(Board);

/**
 * Popule le plateau avec 8 villes placées aléatoirement NB : Deux villes ne peuvent pas être aux mêmes coordonées.
*/
Board populateBoard(Board bd);

/**
 * Retourne la ville en fonction d'un plateau donné et du nom de la ville.
*/
City getCity(Board bd, char* name);

#endif