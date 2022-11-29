#ifndef BOARD_H
#define BOARD_H
#include "utils.h"

/**
 * Type plateau contenant sa largeur, sa hauteur anisi que les huit villes qu'il contient.
*/
typedef struct Board{
    int width;
    int height;
    int citiesCount;
    City** cities;
    float** distanceMatrix;
} Board;
/*
 * Céer un plateau 
*/
Board* createBoard(int,int,int,char**);

/**
 * Affiche un plateau donné avec les villes representées par des croix.
*/
void displayBoard(Board*);

/**
 * Popule le plateau avec 8 villes placées aléatoirement NB : Deux villes ne peuvent pas être aux mêmes coordonées.
*/
void populateBoard(Board*);

/**
 * Retourne la ville en fonction d'un plateau donné et du nom de la ville.
*/
City* getCity(Board*, char*);

/**
 * Créer une matrice avec toutes les distances intervilles
*/
void generateDistanceMatrix(Board*);

#endif