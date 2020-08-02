//
// Created by Carlos Torres on 8/1/20.
//
#include <stdlib.h>
#include <string.h>

#include "bubble_sort.h"

void swap(int *array, int v1, int v2) {
    int tmp = array[v1];
    array[v1] = array[v2];
    array[v2] = tmp;
}

int* bubble_sort(int* unorderedArray, int length) {
    int* orderedArray = malloc(sizeof(int));
    memcpy(orderedArray, unorderedArray, length * sizeof(int));

    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < length - 1; ++j) {
            if (orderedArray[j] > orderedArray[j + 1]) {
                swap(orderedArray, j, j+1);
            }
        }
    }
    return orderedArray;
}
