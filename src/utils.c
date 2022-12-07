#include "../include/utils.h"

int factorial(int n) {
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

int calculatePossibilitiesCount(int citiesCount) {
    return factorial(citiesCount - 1);
}

void printFloatMatrix(float** tab, int sizeX, int sizeY) {
    for(int i = 0; i < sizeY; i++) {
        printf("\n[ ");
        for(int j = 0; j < sizeX; j++) {
            if (j== sizeX-1) printf("%f", tab[i][j]);
            else printf("%f, ", tab[i][j]);
        }
        printf(" ]\n");
    }
}

float** createFloatMatrix(int sizeY, int sizeX) {
    float** matrix = malloc(sizeof(float*) * sizeY);
    if(matrix== NULL) exit(1);

    for (int i = 0; i < sizeY; i++) {
        matrix[i] = malloc(sizeof(float) * sizeX);
        if(matrix[i] == NULL) exit(1);
    }
    return matrix;
}

void freeFloatMatrix(float** matrix, int sizeY) {
    for (int i=0; i < sizeY; i++) free(matrix[i]);
    free(matrix);
}