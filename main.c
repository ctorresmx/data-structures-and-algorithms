//
// Created by Carlos Torres on 8/1/20.
//
#include <stdio.h>

#include "bubble_sort.h"
#include "util.h"

#define ARRAY_SIZE 50000

int main() {
    int *unorderedArray = createRandomArray(ARRAY_SIZE);

    printf("We will sort the following array ");
    printArray(unorderedArray, ARRAY_SIZE);
    printf("\n");

    runSortingFunction(&bubble_sort, "Bubble Sort", unorderedArray, ARRAY_SIZE);

    return 0;
}
