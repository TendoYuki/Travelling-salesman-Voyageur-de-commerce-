#ifndef UTILS_H
#define UTILS_H

/**
 * Type Coords contenant l'abscisse(x) et l'ordonée(y) d'un point.
*/
typedef struct Coords{
    int x;
    int y;
} Coords;

/**
 * Type Ville ayant un nom et des coordonées.
*/
typedef struct City{
    char* name;
    Coords position;
} City;

/**
 * Type Chemin, avec l'ordre de passage et la distance totale du parcours
*/
typedef struct Path{
    float totalDistance;
    City* pathCitiesOrder;
} Path;

/**
 * Retourne la distance entre deux coordonées.
*/
float distanceCoord(Coords*, Coords*);

/**
 * Retourne la distance entre deux villes.
*/
float distanceCity(City*, City*);

/**
 * Calcule la factorelle d'un nombre
*/
int factorial(int);

/**
 * Calcule le nombre de possibilitées de chemin en fonction du nombre de villes
*/
int calculatePossibilitiesCount(int);
#endif
