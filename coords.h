#ifndef COORDS_H
#define COORDS_H
#include <math.h>

/**
 * Type Coords contenant l'abscisse(x) et l'ordonée(y) d'un point.
*/
typedef struct Coords{
    int x;
    int y;
} Coords;

/**
 * Retourne la distance entre deux coordonées.
*/
float distanceCoord(Coords*, Coords*);

#endif