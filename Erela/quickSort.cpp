// Erela Braddom
// Lab 5, ECE 2161-001
// Quicksort implementation.

#include "quickSort.h"
#include <utility>

// Place the pivot in its sorted position and return its index.
int partition(long data[], int low, int high) {
    long pivot = data[high];
    int i = low - 1;

    // Move numbers less than or equal to the pivot to the left.
    for (int j = low; j < high; ++j) {
        if (data[j] <= pivot) {
            ++i;
            long temp = data[i];
            data[i] = data[j];
            data[j] = temp;
        }
    }

    // Put the pivot between the two sections.
    long temp = data[i + 1];
    data[i + 1] = data[high];
    data[high] = temp;
    return i + 1;
}

// Recursively sort the sections on either side of the pivot.
void quickSort(long data[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(data, low, high);

        quickSort(data, low, pivotIndex - 1);
        quickSort(data, pivotIndex + 1, high);
    }
}
