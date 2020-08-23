//
// Created by Carlos Torres on 8/2/20.
//
#include "merge_sort.h"
#include "util.h"

int* merge_sort(int* unorderedArray, int length) {
    if (length == 1) {
        return unorderedArray;
    }

    int* copiedArray = copy_array(unorderedArray, 0, length);
    int separationIndex = length / 2;

    int* orderedArray1 = merge_sort(copy_array(copiedArray, 0, separationIndex), separationIndex);
    int* orderedArray2 = merge_sort(copy_array(copiedArray, separationIndex, length), length - separationIndex);

    return naive_merge(orderedArray1, orderedArray2, separationIndex, length - separationIndex);
}
