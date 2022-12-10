#ifndef UTILS_H
#define UTILS_H

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
void printFloatMatrix(float** tab, int sizeX, int sizeY);

/**
 * Crée et alloue avec malloc() une matrice de nombre à virgule de taille veritcale sizeY et de taille horizontale sizeX
*/
float** createFloatMatrix(int sizeY, int sizeX);

/**
 * Désalloue une matrice matrix de nombre à virgule de taille veritcale sizeY
*/
void freeFloatMatrix(float** matrix, int sizeY);

#endif
