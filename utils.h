#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    City** pathCitiesOrder;
} Path;

/**
 * Retourne une nouvelle liste en fonction d'un pointeurs vers une liste de ville passé en paramétre.
 * La nouvelle liste ne contiendra pas la ville d'index passé en paramètre, et devra être libérée avec free() 
*/
City** removeCity(City**,int, int);

/**
 * 
*/
City** copyCityList(City**, int);

/**
 * Copie le contenu de la ville city dans la ville copy
 * Alloue de la mémoire pour le nom avec malloc(), elle devra être liberée avec free
*/
void copyCity(City*, City*);

City* cloneCity(City*) ;

void freeCityList(City**, int);

/**
 * Libére le chemin mais ne libère pas les villes qu'il contient
*/
void freePath(Path*, int);

/**
 * Crée et alloue avec malloc() un Path et retourne son addresse
*/
Path* createPath(int);

/**
 * Copie un path dans un nouveau et retourne l'adresse de la copie, allouée avec malloc()
*/
Path* clonePath(Path*, int);

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
