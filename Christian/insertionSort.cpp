// Christian Francis
// Lab 5, ECE 2161-001
// Sorts the numbers using insertion sort.

#include "insertionSort.h"

// sorts the numbers from smallest to largest.
void insertionSort(long data[], long size) {
    // put each number in the right spot among the sorted numbers.
    for (long i = 1; i < size; i++) {
        long key = data[i];
        long j = i - 1;

        // move bigger numbers to the right to make room.
        while (j >= 0 && data[j] > key) {
            data[j + 1] = data[j];
            j--;
        }

        data[j + 1] = key;
    }
}
