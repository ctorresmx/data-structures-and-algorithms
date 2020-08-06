//
// Created by Carlos Torres on 8/2/20.
//
#include <stdlib.h>
#include <string.h>

#include "merge_sort.h"

int* copy_array(int* array, int start, int end) {
    int length = end - start;
    int* copiedArray = malloc(sizeof(int) * length);

    memcpy(copiedArray, array + start, length * sizeof(int));
    return copiedArray;
}

int* merge(int* orderedArray1, int* orderedArray2, int length1, int length2) {
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

int* merge_sort(int* unorderedArray, int length) {
    if (length == 1) {
        return unorderedArray;
    }

    int* copiedArray = copy_array(unorderedArray, 0, length);
    int separationIndex = length / 2;

    int* orderedArray1 = merge_sort(copy_array(copiedArray, 0, separationIndex), separationIndex);
    int* orderedArray2 = merge_sort(copy_array(copiedArray, separationIndex, length), length - separationIndex);

    return merge(orderedArray1, orderedArray2, separationIndex, length - separationIndex);
}
