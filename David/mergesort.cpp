//merge sort
#include "mergesort.h"
#include <vector>

//Function to merge two subarrays of arr[]
void merge(std::vector<long int>& arr, int left, int mid, int right) {

    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<long int> L(n1), R(n2);
//Loop for copying data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;

//loop for merging the temporary arrays back into arr[]
    while (i < n1 && j < n2) {

        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }

        k++;
    }

//loop for copying the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
//loop for copying the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

//Function to implement merge sort
void mergeSort(std::vector<long int>& arr, int left, int right) {

    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    merge(arr, left, mid, right);
}
