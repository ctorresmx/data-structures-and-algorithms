//
// Created by Carlos Torres on 8/1/20.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void runSortingFunction(Algorithm algorithm, int *unorderedArray, int length) {
    printf("%s:\n", algorithm.name);

    clock_t t = clock();
    algorithm.sortingFunction(unorderedArray, length);
    double elapsedTime = ((float) (clock() - t) / CLOCKS_PER_SEC);

    printf("It took %f seconds to run.\n\n", elapsedTime);
}

int* copy_array(int* array, int start, int end) {
    int length = end - start;
    int* copiedArray = malloc(sizeof(int) * length);

    memcpy(copiedArray, array + start, length * sizeof(int));
    return copiedArray;
}

int* naive_merge(const int* orderedArray1, const int* orderedArray2, int length1, int length2) {
    int* orderedArray = malloc(sizeof(int) * (length1 + length2));

    int pos1 = 0;
    int pos2 = 0;

    for (int i = 0; i < length1 + length2; ++i) {
        int val1 = orderedArray1[pos1];
        int val2 = orderedArray2[pos2];

        if (pos1 == length1) {
            orderedArray[i] = val2;
            pos2++;
            continue;
        }

        if (pos2 == length2) {
            orderedArray[i] = val1;
            pos1++;
            continue;
        }

        if (val1 < val2) {
            orderedArray[i] = val1;
            pos1++;
        } else {
            orderedArray[i] = val2;
            pos2++;
        }
    }
    return orderedArray;
}
