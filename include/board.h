#ifndef BOARD_H
#define BOARD_H
#include "path.h"
#include "city.h"

/**
 * Type plateau contenant sa largeur, sa hauteur la liste de pointeur vers les villes qu'il contient, 
 * le nombre de villes qu'il contient et la matrice des distances intervilles.
*/
typedef struct Board{
    int width;
    int height;
    int citiesCount;
    int possiblePathsCount;
    City** cities;
    float** distanceMatrix;
    Path** possiblePaths;
} Board;

/*
 * Crée et alloue avec malloc() un plateau en fonction de sa hauteur, de sa largeur, de son nombre de ville et du nom de sees villes
*/
Board* createBoard(int width,int height,int citiesCount,char** citiesNames);

/**
 * Affiche un plateau donné avec les villes representées par des croix.
*/
void displayBoard(Board* bd);

/**
 * Popule le plateau avec 8 villes placées aléatoirement NB : Deux villes ne peuvent pas être aux mêmes coordonées.
*/
void populateBoard(Board* bd);

/**
 * Retourne un pointer vers une ville en fonction d'un plateau donné et du nom recherché.
*/
City* getCity(Board* bd, char* name);

/**
 * Calcule la matrice avec toutes les distances intervilles d'un plateau donné
*/
void generateDistanceMatrix(Board* bd);

/**
 * Désalloue un plateau et tout ses composants
*/
void destroyBoard(Board* bd);

/**
 * Retourne l'index d'affichage d'une ville city en fonction d'un board bd
*/
int getCityIndex(Board* bd, City* city);

/**
 * Affiche un plateau bd avec le path passé en paramètre représenté par les des numéros correspondant à l'ordre de passage dans les villes 
*/
void displayPath(Board* bd,Path* path);

/**
 * Génére la totalité des chemins possible d'un plateau bd passé en paramètre, les coemins possibles seront stockées dans la variable possiblePaths du plateau 
*/
void generatePossiblePaths(Board* bd);

/**
 * Fonction récursive appellée uniquement par la fonction generatePossiblePath, permettant de calculer les chemins et de les stocker dans le plateau
*/
void generatePath(Board* bd, City* currentCity, Path* previousPath, City** citiesLeft, int citiesLeftCount, int previousDivergence, int maxDepth, int depth);

/**
 * Retourne un pointeur pointant vers le chemin le plus optimisé d'un plateau
 * Il est obligatoire de générer avec generatePossiblePaths la totalité des chemins possibles sur le plateau
*/
Path* getOptimisedRoute(Board* bd);

/**
 * Calcule la distance totale d'un path passé en paramètre sur un board bd
 * Fonction uniquement appellée par la fonction calculateAllPathsDistances
*/
void calculatePathDistance(Board* bd, Path* path);

/**
 *  Calcule la distance de toute les path d'un board bd
*/
void calculateAllPathsDistances(Board* bd);


#endif