#ifndef COORDS_H
#define COORDS_H

/**
 * Type Coords contenant l'abscisse(x) et l'ordonée(y) d'un point.
*/
typedef struct Coords{
    int x;
    int y;
} Coords;

/**
 * Retourne la distance entre les coordonées a et b.
*/
float distanceCoord(Coords* a, Coords* b);

#endif