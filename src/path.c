#include "../include/path.h"

Path* clonePath(Path* path, int citiesCount) {
    Path* copy = createPath(citiesCount);
    copy->totalDistance = path->totalDistance;
    //Copie les villes contenues dans le path
    for(int i=0; i < citiesCount; i++) {
        if(path->pathCitiesOrder[i]->name != NULL) copy->pathCitiesOrder[i] = path->pathCitiesOrder[i];
    }

    return copy;
}


Path* createPath(int citiesCount) {
    //Alloue un path
    Path* path = malloc(sizeof(Path*));
    if(path == NULL) exit(1);

    //Alloue la liste de pointeur vers des villes représentant l'ordre de passage dans ces dernières
    path->pathCitiesOrder = malloc(sizeof(City*) * citiesCount);
    if(path->pathCitiesOrder == NULL) exit(1);
    
    //Valeur par défaut de la distance

    path->totalDistance = 0;

    //Alloue chaque poineur villes contenues dans l'ordre de passage du path
    for(int i=0; i < citiesCount; i++) {
        path->pathCitiesOrder[i] = malloc(sizeof(City*));
        if(path->pathCitiesOrder[i] == NULL) exit(1);
        path->pathCitiesOrder[i]->name = NULL;
    }

    return path;
}

Path** createPathList(int pathListSize,int citiesCount) {
    //Alloue la liste de path
    Path** pathList = malloc(sizeof(Path*) * pathListSize);
    if(pathList == NULL) exit(1);

    //Alloue chaque chemin possible
    for (int i = 0; i < pathListSize; i++) {
        pathList[i] = createPath(citiesCount);
    }
    return pathList;
}

void freePath(Path* path) {
    //Libére le path
    free(path->pathCitiesOrder);
    free(path);
}

void freePathList(Path** pathList, int pathCount) {
    for(int i = 0; i < pathCount; i++) freePath(pathList[i]);
    free(pathList);
}