#ifndef UTILS_H
#define UTILS_H

/**
 * Type Coords contenant l'abscisse(x) et l'ordonée(y) d'un point.
*/
typedef struct {
    int x;
    int y;
} Coords;

/**
 * Type Ville ayant un nom et des coordonées.
*/
typedef struct {
    char* name;
    Coords position;
} City;


/**
 * Retourne la distance entre deux coordonées.
*/
float distanceCoord(Coords, Coords);

/**
 * Retourne la distance entre deux villes.
*/
float distanceCity(City, City);

#endif