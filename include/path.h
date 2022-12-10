#ifndef PATH_H
#define PATH_H

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
void freePath(Path* path);

/**
 * Crée et alloue avec malloc() un Path et retourne son addresse
*/
Path* createPath(int citiesCount);

/**
 * Copie un path dans un nouveau et retourne l'adresse de la copie, allouée avec malloc()
*/
Path* clonePath(Path* path, int citiesCount);

/**
 * Crée et alloue avec malloc() une liste de Path et retourne l'adresse du premier élément de la liste
*/
Path** createPathList(int pathListSize,int citiesCount);

/**
 * Désalloue une liste de chemin pathList en fonction du nombre de chemin pathCount 
 * NB: les villes contenues dans chaque chemin ne seront pas désallouées
*/
void freePathList(Path** pathList, int pathCount);

#endif