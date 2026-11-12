// Christian Francis
// Lab 5, ECE 2161-001
// Sorts the numbers using heap sort.

#include "heapSort.h"

// Fixes the heap so the parent is bigger than its children
static void heapify(long data[], long size, long root) {
    long largest = root;
    long left = 2 * root + 1;
    long right = 2 * root + 2;

    // Find the biggest of the three values
    if (left < size && data[left] > data[largest]) {
        largest = left;
    }

    if (right < size && data[right] > data[largest]) {
        largest = right;
    }

    // Swap if needed, then fix the heap below it
    if (largest != root) {
        long temp = data[root];
        data[root] = data[largest];
        data[largest] = temp;

        heapify(data, size, largest);
    }
}

// Sorts the numbers from smallest to largest
void heapSort(long data[], long size) {
    // Set up the heap with the biggest number at the top
    for (long i = size / 2 - 1; i >= 0; i--) {
        heapify(data, size, i);
    }

    // Move the biggest number to the end, then fix the remaining heap
    for (long i = size - 1; i > 0; i--) {
        long temp = data[0];
        data[0] = data[i];
        data[i] = temp;

        heapify(data, i, 0);
    }
}
