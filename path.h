#ifndef PATH_H
#define PATH_H

#include <stdlib.h>
#include "city.h"

/**
 * Type Chemin, avec l'ordre de passage et la distance totale du parcours
*/
typedef struct Path{
    float totalDistance;
    City** pathCitiesOrder;
} Path;

/**
 * Libére le chemin mais ne libère pas les villes qu'il contient
*/
void freePath(Path*);

/**
 * Crée et alloue avec malloc() un Path et retourne son addresse
*/
Path* createPath(int);

/**
 * Copie un path dans un nouveau et retourne l'adresse de la copie, allouée avec malloc()
*/
Path* clonePath(Path*, int);

#endif