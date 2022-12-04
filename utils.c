#include "utils.h"

float distanceCoord(Coords* a, Coords* b) {
    return sqrt(pow((float)(a->x-b->x),2)+pow((float)(a->y-b->y),2));
}

float distanceCity(City* a, City* b) {
    return sqrt(pow((float)(a->position.x-b->position.x),2)+pow((float)(a->position.y-b->position.y),2));
}

void copyCity(City* city, City* copy) {
    copy->name = strdup(city->name);
    copy->position.x = city->position.x;
    copy->position.y = city->position.y;
}

City* cloneCity(City* city) {
    City* ct = malloc(sizeof(City*));
    ct->name = strdup(city->name);
    ct->position.x = city->position.x;
    ct->position.y = city->position.y;
    return ct;
}


City** copyCityList(City** cities, int citiesCount) {
    City** copy = malloc(sizeof(City*)*(citiesCount));
    //Allouer chaque ville dans la nouvelle liste
    for(int i=0; i < citiesCount; i++) {
        copy[i] = malloc(sizeof(City*));
        copyCity(cities[i], copy[i]);
    }

    return copy;
}

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

void freePath(Path* path, int citiesCount) {
    //Libére le path
    free(path->pathCitiesOrder);
    free(path);
}

void freeCityList(City** cities, int citiesCount) {
    for(int i=0; i < citiesCount; i++) {
        free(cities[i]->name);
        free(cities[i]);
    }
    free(cities);
}

City** removeCity(City** cities,int index, int citiesCount) {
    City** newCities = malloc(sizeof(City)*(citiesCount-1));

    //Allouer chaque ville dans la nouvelle liste
    for(int i=0; i < citiesCount-1; i++) {
        newCities[i] = malloc(sizeof(City));
    }

    int offset = 0;
    for(int i=0; i<citiesCount-1; i++) {
        if(i==index) offset++;
        if (i+offset > citiesCount-1) break;

        newCities[i] = cities[i + offset];
    }
    return newCities;
}

int factorial(int n) {
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

int calculatePossibilitiesCount(int citiesCount) {
    return factorial(citiesCount - 1);
}