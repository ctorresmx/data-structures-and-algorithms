//
// Created by Carlos Torres on 8/1/20.
//
#include <stdio.h>

#include "bubble_sort.h"
#include "merge_sort.h"
#include "merge_sort_pthread.h"
#include "util.h"

#define ARRAY_SIZE 5

const Algorithm algorithms[3] = {
        { .name = "Bubble Sort", .sortingFunction = &bubble_sort },
        { .name = "Merge Sort", .sortingFunction = &merge_sort },
        { .name = "Merge Sort with pthreads", .sortingFunction = &merge_sort_pthread },
};

int main() {
    int *unorderedArray = createRandomArray(ARRAY_SIZE);

    printf("Starting sorting array functions...");
    printArray(unorderedArray, ARRAY_SIZE);
    printf("\n");

    for (int i = 0; i < sizeof(algorithms) / sizeof(Algorithm); ++i) {
        runSortingFunction(algorithms[i], unorderedArray, ARRAY_SIZE);
    }

    return 0;
}
