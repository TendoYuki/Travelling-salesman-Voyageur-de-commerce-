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