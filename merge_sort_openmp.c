//
// Created by Carlos Torres on 8/15/20.
//
#include <string.h>

#include "merge_sort_openmp.h"
#include "util.h"

int* merge_sort_openmp(int* unorderedArray, int length) {
    if (length == 1) {
        return unorderedArray;
    }

    int* copiedArray = copy_array(unorderedArray, 0, length);
    int separationIndex = length / 2;

    int* orderedArray1 = NULL;
    int* orderedArray2 = NULL;
    int* result = NULL;
    #pragma omp parallel sections
    {
            #pragma omp section
            {
                orderedArray1 = merge_sort_openmp(copy_array(copiedArray, 0, separationIndex), separationIndex);
            }
            #pragma omp section
            {
                orderedArray2 = merge_sort_openmp(copy_array(copiedArray, separationIndex, length), length - separationIndex);
            }
    }
    result = naive_merge(orderedArray1, orderedArray2, separationIndex, length - separationIndex);
    return result;
}