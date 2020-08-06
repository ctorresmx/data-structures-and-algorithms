//
// Created by Carlos Torres on 8/1/20.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "util.h"

int *createRandomArray(int length) {
    int *array = malloc(sizeof(int) * length);
    for (int i = 0; i < length; ++i) {
        array[i] = rand();
    }
    return array;
}

void printArray(const int* array, int length) {
    printf("[");
    for (int i = 0; i < length; ++i) {
        printf("%i ", *(array + i));
    }
    printf("]\n");
}

void runSortingFunction(int *(*sortingFunction) (int*, int), char *sortingFunctionName, int *unorderedArray, int length) {
    printf("%s:\n", sortingFunctionName);

    clock_t t = clock();
    sortingFunction(unorderedArray, length);
    double elapsedTime = ((float) (clock() - t) / CLOCKS_PER_SEC);

    printf("It took %f seconds to run.\n\n", elapsedTime);
}