#include "insertionSort.h"

void insertionSort(long data[], long size) {
    for (long i = 1; i < size; i++) {
        long key = data[i];
        long j = i - 1;

        while (j >= 0 && data[j] > key) {
            data[j + 1] = data[j];
            j--;
        }

        data[j + 1] = key;
    }
}
