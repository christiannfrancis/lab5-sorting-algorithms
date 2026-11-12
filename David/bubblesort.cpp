#include "BubbleSort.h"
#include <algorithm>
#include <vector>

void bubbleSort(std::vector<long int>& values) {

    int n = values.size();

    for (int i = 0; i < n - 1; i++) {

        bool flag = false;

        for (int j = 0; j < n - i - 1; j++) {

            if (values[j] > values[j + 1]) {
                std::swap(values[j], values[j + 1]);
                flag = true;
            }
        }

        if (!flag) {
            break;
        }
    }
}
