//
// Created by Carlos Torres on 8/22/20.
//
#include <pthread.h>
#include <stdlib.h>

#include "merge_sort_pthread.h"
#include "util.h"

typedef struct sortParameters {
    int* unorderedArray;
    int* orderedArray;
    int length;
} SortParameters;

void *serial_merge_sort(void* parameters) {
    SortParameters* input = (SortParameters*) parameters;
    if (input->length == 1) {
        input->orderedArray = input->unorderedArray;
        return NULL;
    }

    input->orderedArray = copy_array(input->unorderedArray, 0, input->length);
    int separationIndex = input->length / 2;

    SortParameters* left = malloc(sizeof(SortParameters));
    left->length = separationIndex;
    left->unorderedArray = copy_array(input->unorderedArray, 0, separationIndex);
    serial_merge_sort(left);

    SortParameters* right = malloc(sizeof(SortParameters));
    right->length = input->length - separationIndex;
    right->unorderedArray = copy_array(input->unorderedArray, separationIndex, input->length);
    serial_merge_sort(right);

    input->orderedArray = naive_merge(left->orderedArray, right->orderedArray, separationIndex, input->length - separationIndex);
}

int* merge_sort_pthread(int* unorderedArray, int length) {
    if (length == 1) {
        return unorderedArray;
    }

    pthread_t threads[2];

    int* copiedArray = copy_array(unorderedArray, 0, length);
    int separationIndex = length / 2;

    SortParameters* left = malloc(sizeof(SortParameters));
    left->unorderedArray = copy_array(copiedArray, 0, separationIndex);
    left->length = separationIndex;

    SortParameters* right = malloc(sizeof(SortParameters));
    right->unorderedArray = copy_array(copiedArray, separationIndex, length);
    right->length = length - separationIndex;

    pthread_create(&threads[0], NULL, serial_merge_sort, (void*) left);
    pthread_create(&threads[1], NULL, serial_merge_sort, (void*) right);

    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);

    return naive_merge(left->orderedArray, right->orderedArray, separationIndex, length - separationIndex);
}
