#ifndef CITY_H
#define CITY_H
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "coords.h"

/**
 * Type Ville ayant un nom et des coordonées.
*/
typedef struct City{
    char* name;
    Coords position;
} City;

/**
 * Retourne la distance entre deux villes.
*/
float distanceCity(City*, City*);

/**
 * Retourne une nouvelle liste en fonction d'un pointeurs vers une liste de ville passé en paramétre.
 * La nouvelle liste ne contiendra pas la ville d'index passé en paramètre, et devra être libérée avec free() 
*/
City** removeCity(City**,int, int);

/**
 * Copie le contenu de la ville city dans la ville copy
 * Alloue de la mémoire pour le nom avec malloc(), elle devra être liberée avec free
*/
void copyCity(City*, City*);

/**
 * Créer un clone de la ville city en allouant avec malloc() une nouvelle ville qui sera retournée
*/
City* cloneCity(City*) ;

/**
 * Libère une liste de ville ainsi que les villes qu'elle contient 
*/
void freeCityList(City**, int);

/**
 * Copie une liste de ville en allouant une nouvelle liste, tout en créant des nouvelles villes allouées avec malloc() ayant le contenu des précédentes 
*/
City** cloneCityList(City**, int);

#endif