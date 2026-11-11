#include "heapSort.h"

void heapify(long data[], long size, long root) {
    long largest = root;
    long left = 2 * root + 1;
    long right = 2 * root + 2;

    if (left < size && data[left] > data[largest]) {
        largest = left;
    }

    if (right < size && data[right] > data[largest]) {
        largest = right;
    }

    if (largest != root) {
        long temp = data[root];
        data[root] = data[largest];
        data[largest] = temp;

        heapify(data, size, largest);
    }
}

void heapSort(long data[], long size) {
    for (long i = size / 2 - 1; i >= 0; i--) {
        heapify(data, size, i);
    }

    for (long i = size - 1; i > 0; i--) {
        long temp = data[0];
        data[0] = data[i];
        data[i] = temp;

        heapify(data, i, 0);
    }
}
