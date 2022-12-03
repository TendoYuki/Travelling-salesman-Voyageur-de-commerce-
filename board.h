#ifndef BOARD_H
#define BOARD_H
#include "utils.h"

/**
 * Type plateau contenant sa largeur, sa hauteur la liste de pointeur vers les villes qu'il contient, 
 * le nombre de villes qu'il contient et la matrice des distances intervilles.
*/
typedef struct Board{
    int width;
    int height;
    int citiesCount;
    City** cities;
    float** distanceMatrix;
} Board;

/*
 * Crée un plateau 
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
 * Retourne un pointeru vers une ville en fonction d'un plateau donné et du nom recherché.
*/
City* getCity(Board*, char*);

/**
 * Calcule la matrice avec toutes les distances intervilles d'un plateau donné
*/
void generateDistanceMatrix(Board*);

/**
 * Désalloue un plateau et tout ses composants
*/
void destroyBoard(Board*);

#endif