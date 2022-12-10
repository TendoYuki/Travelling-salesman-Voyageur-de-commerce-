#include "../include/coords.h"
#include <math.h>

float distanceCoord(Coords* a, Coords* b) {
    return sqrt(pow((float)(a->x-b->x),2)+pow((float)(a->y-b->y),2));
}