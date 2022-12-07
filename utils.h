
#ifndef UTILS_H
#define UTILS_H

#include <math.h>
#include <stdio.h>
#include "city.h"

/**
 * Calcule la factorelle d'un nombre n
*/
int factorial(int n);

/**
 * Calcule le nombre de possibilitées de chemin en fonction du nombre de villes
*/
int calculatePossibilitiesCount(int citiesCount);

/**
 * Affiche une matrice tab de taille horizontale sizeX et de taille verticale sizeY
*/
void printMatrix(float** tab, int sizeX, int sizeY);

#endif
