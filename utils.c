#include "utils.h"

int factorial(int n) {
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

int calculatePossibilitiesCount(int citiesCount) {
    return factorial(citiesCount - 1);
}

void printMatrix(float** tab, int sizeX, int sizeY) {
    for(int i = 0; i < sizeY; i++) {
        printf("\n[ ");
        for(int j = 0; j < sizeX; j++) {
            if (j== sizeX-1) printf("%f", tab[i][j]);
            else printf("%f, ", tab[i][j]);
        }
        printf(" ]\n");
    }
}