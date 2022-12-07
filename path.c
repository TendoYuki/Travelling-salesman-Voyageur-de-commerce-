#include "path.h"

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
    Path* path = malloc(sizeof(Path*));
    path->pathCitiesOrder = malloc(sizeof(City*) * citiesCount);
    path->totalDistance = 0;
    //Copie les villes contenues dans le path
    for(int i=0; i < citiesCount; i++) {
        path->pathCitiesOrder[i] = malloc(sizeof(City*));
        path->pathCitiesOrder[i]->name = NULL;
    }
    return path;
}

void freePath(Path* path) {
    //Libére le path
    free(path->pathCitiesOrder);
    free(path);
}
