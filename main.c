#include "include/utils.h"
#include "include/board.h"
#include "include/path.h"
#include "include/car.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    Board* bd = createBoard(50,20,8, (char*[]){"Lille", "Paris", "Montcuq", "Grenoble", "Amiens", "Saint-Dié", "Dijon", "Toulouse"});

    populateBoard(bd);

    printf("\nAffichage des villes générées aléatoirement placées sur un plateau : \n");
    displayBoard(bd);

    generateDistanceMatrix(bd);

    // Affiche la matrice de toutes les distances
    // printFloatMatrix(bd->distanceMatrix, bd->citiesCount, bd->citiesCount);

    generatePossiblePaths(bd);

    calculateAllPathsDistances(bd);

    //Création d'une voiture éléctrique pour pouvoir correspondre au tableau deja crée car les valeurs ne peuvent correspondre à la vie réele (la tableau du sujet est trop petit)
    // Aucune voiture electrique à une autonomie inférieure a 80km, nous avons donc crée flash mc queen la voiture electrique à seuelemnt 50 km d'autonomie
    Car flashMcQueen = {
        "Chevrolet Corvette C6 Electrical Model", //Purement fictionnel, ce modèle n'existe pas dans la vie réele
        50, // Autonomie
        1 // KM/minute -> recharge
    };


    Path *path = getOptimisedRouteByDistance(bd);
    printf("\nRoute calculée par le déplacement à la ville la plus proche (récursivement) : \n");
    displayPath(bd,path);

    Path *path2 = getOptimisedRoute(bd);
    printf("\nRoute la plus optimisée calculée par la génération de tout les chemins possibles (récursivement) : \n");
    displayPath(bd,path2);

    // Affiche le tableau du temps de recharge par ville en fonction du chemin le plus optimisé
    int* tab = optimizePathForVehicle(&flashMcQueen, 15, path, bd);

    printf("\nTemps de recharge(en minutes) de la voiture par ville le plus optimisé en fonction du chemin (index correspondant à l'ordre de passage dans les villes):\n[");
    for(int i = 0; i< bd->citiesCount; i++) printf(" %d ", tab[i]);
    printf("]\n");


    free(tab);
    free(path);
    destroyBoard(bd);
    return 0;
}