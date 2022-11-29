#include "utils.h"
#include <math.h>
#include <stdio.h>

float distanceCoord(Coords a, Coords b) {
    return sqrt(pow((float)(a.x-b.x),2)+pow((float)(a.y-b.y),2));
}

float distanceCity(City* a, City* b) {
    return sqrt(pow((float)(a->position.x-b->position.x),2)+pow((float)(a->position.y-b->position.y),2));
}

