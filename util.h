//
// Created by Carlos Torres on 8/1/20.
//

#ifndef DATASTRUCTURES_AND_ALGORITHMS_UTIL_H
#define DATASTRUCTURES_AND_ALGORITHMS_UTIL_H

typedef struct algorithm {
    const char* name;
    int *(*sortingFunction) (int*, int);
} Algorithm;

int *createRandomArray(int);
void printArray(const int*, int);
void runSortingFunction(Algorithm, int*, int);

#endif //DATASTRUCTURES_AND_ALGORITHMS_UTIL_H
