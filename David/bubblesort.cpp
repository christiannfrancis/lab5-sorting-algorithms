//bubble sort
#include "BubbleSort.h"
#include <algorithm>
#include <vector>

//Method to perform bubble sort on a vector of long integers
void bubbleSort(std::vector<long int>& values) {
int n = values.size();

//loop to iterate through the vector and perform bubble sort
for (int i = 0; i < n - 1; i++) {
bool flag = false;

//loop to compare adjacent elements and swap them if they are in the wrong order
for (int j = 0; j < n - i - 1; j++) {
if (values[j] > values[j + 1]) {
flag = true;
}
}

if (!flag) {
break;
}
}
} 
