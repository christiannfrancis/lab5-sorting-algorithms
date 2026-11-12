// Erela Braddom
// Lab 5, ECE 2161-001
// Selection Sort implementation.

#include "selectionSort.h"

// Sort numbers by selecting the smallest remaining item.
void selectionSort(long data[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i;

        // Find the smallest item in the unsorted section.
        for (int j = i + 1; j < size; ++j) {
            if (data[j] < data[minIndex]) {
                minIndex = j;
            }
        }

        // Move the smallest item into position.
        long temp = data[i];
        data[i] = data[minIndex];
        data[minIndex] = temp;
    }
}
