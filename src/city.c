#include "../include/city.h"

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

City** cloneCityList(City** cities, int citiesCount) {
    City** copy = malloc(sizeof(City*)*(citiesCount));
    //Allouer chaque ville dans la nouvelle liste
    for(int i=0; i < citiesCount; i++) {
        copy[i] = malloc(sizeof(City*));
        copyCity(cities[i], copy[i]);
    }

    return copy;
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

void freeCityList(City** cities, int citiesCount) {
    for(int i=0; i < citiesCount; i++) {
        free(cities[i]->name);
        free(cities[i]);
    }
    free(cities);
}

float distanceCity(City* ct1, City* ct2) {
    return sqrt(pow((float)(ct1->position.x-ct2->position.x),2)+pow((float)(ct1->position.y-ct2->position.y),2));
}

City* createCity(char* name) {
    //Alloue la ville
    City* ct = malloc(sizeof(City*));
    if(ct == NULL) exit(1);

    //Alloue le nom de la ville
    ct->name = (char*)malloc(strlen(name) + 1);
    if(ct->name == NULL) exit(1);

    //Copie name dans le nom de la ville
    strcpy(ct->name, name);
    
    return ct;
}


City** createCitesList(int citiesCount, char** citiesNames) {
    City** cities = malloc(sizeof(City*) * citiesCount);
    for (int i = 0; i < citiesCount; i++) {
        cities[i] = createCity(citiesNames[i]);
    }
    return cities;
}