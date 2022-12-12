#ifndef BOARD_H
#define BOARD_H

struct Path;
struct City;

/**
 * Type plateau contenant sa largeur, sa hauteur la liste de pointeur vers les villes qu'il contient, 
 * le nombre de villes qu'il contient et la matrice des distances intervilles.
*/
typedef struct Board{
    int width;
    int height;
    int citiesCount;
    int possiblePathsCount;
    struct City** cities;
    float** distanceMatrix;
    struct Path** possiblePaths;
} Board;

/*
 * Crée et alloue avec malloc() un plateau en fonction de sa hauteur, de sa largeur, de son nombre de ville et du nom de sees villes
*/
struct Board* createBoard(int width,int height,int citiesCount,char** citiesNames);

/**
 * Affiche un plateau donné avec les villes representées par des croix.
*/
void displayBoard(struct Board* bd);

/**
 * Popule le plateau avec 8 villes placées aléatoirement NB : Deux villes ne peuvent pas être aux mêmes coordonées.
*/
void populateBoard(struct Board* bd);

/**
 * Retourne un pointer vers une ville en fonction d'un plateau donné et du nom recherché.
*/
struct City* getCity(struct Board* bd, char* name);

/**
 * Calcule la matrice avec toutes les distances intervilles d'un plateau donné
*/
void generateDistanceMatrix(struct Board* bd);

/**
 * Désalloue un plateau et tout ses composants
*/
void destroyBoard(struct Board* bd);

/**
 * Retourne l'index d'affichage d'une ville city en fonction d'un plateau bd
*/
int getCityIndex(struct Board* bd, struct City* city);

/**
 * Affiche un plateau bd avec le path passé en paramètre représenté par les des numéros correspondant à l'ordre de passage dans les villes 
*/
void displayPath(struct Board* bd,struct Path* path);

/**
 * Génére la totalité des chemins possible d'un plateau bd passé en paramètre, les coemins possibles seront stockées dans la variable possiblePaths du plateau 
*/
void generatePossiblePaths(struct Board* bd);

/**
 * Fonction récursive appellée uniquement par la fonction generatePossiblePath, permettant de calculer les chemins et de les stocker dans le plateau
*/
void generatePath(struct Board* bd, struct City* currentCity, struct Path* previousPath, struct City** citiesLeft, int citiesLeftCount, int previousDivergence, int maxDepth, int depth);

/**
 * Retourne un pointeur pointant vers le chemin le plus optimisé d'un plateau
 * Il est obligatoire de générer avec generatePossiblePaths la totalité des chemins possibles sur le plateau
*/
struct Path* getOptimisedRoute(struct Board* bd);

/**
 * Calcule la distance totale d'un path passé en paramètre sur un plateau bd
 * Fonction uniquement appellée par la fonction calculateAllPathsDistances
*/
void calculatePathDistance(struct Board* bd, struct Path* path);

/**
 *  Calcule la distance de toute les path d'un plateau bd
*/
void calculateAllPathsDistances(struct Board* bd);

/**
 * Retourne un pointeur vers une ville en fonction de son index sur un plateau bd
*/
struct City* getCityByIndex(struct Board* bd, int index);

/**
 * Retourne la ville la plus proche de la ville ct sur un plateau bd en prenant en compte la liste excluded representant les villes inaccessibles
*/
struct City* getClosestCity(struct Board* bd, struct City* ct, struct City** excluded, int excludedCount);

/**
 * Fonction recursive prenant en paramètre un plateau bd, une liste de ville inaccessible de taille excludedCount 
 * Retourne le path passé en paramètre auquel sera ajouté recursivement la ville la plus proche
*/
struct Path* recursiveRoute(struct Board* bd, struct City** cityExcluded, int excludedCount,struct Path* path);

/**
 * Retourne un path généré par voyage récursive à la ville la plus proche jusqu'a ce qu'il n'y ai plus de villes à parcourir
*/
struct Path* getOptimisedRouteByDistance(struct Board* bd);

#endif