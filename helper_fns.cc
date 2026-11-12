// Christian Francis, Erela Braddom, David Cunha
// Lab 5, ECE 2161-001
// Menu and file functions adapted from the supplied framework.

#include <iostream>
#include <fstream>
#include "myheaders.h"

using namespace std;

// SHows the menu
void printmenu() {
    cout << "\nPlease choose from the following menu:\n";
    cout << "1: Read data from input file\n";
    cout << "2: Insertion Sort\n";
    cout << "3: Heap Sort\n";
    cout << "4: Bubble Sort\n";
    cout << "5: Merge Sort\n";
    cout << "6: Selection Sort\n";
    cout << "7: Quick Sort\n";
    cout << "0: Exit\n";
    cout << "Enter your choice: ";
}

// Reads numbers into the array and returns the count, or -1 when there's an error
int readfile(string filename, long data[]) {
    ifstream input(filename.c_str());

    if (!input) {
        return -1;
    }

    int size = 0;
    long value;

    // Read each number without going over the number of items
    while (input >> value) {
        if (size == MAXSIZE) {
            return -1;
        }

        data[size] = value;
        size++;
    }

    // Reject invalid data or a file-reading failure
    if (!input.eof() || input.bad()) {
        return -1;
    }

    return size;
}

// Writes the sorted array to a file and returns 0 when it succeeds or -1 when an error occurs
int writefile(long data[], long size, string filename) {
    ofstream output(filename.c_str());

    if (!output) {
        return -1;
    }

    // Write all sorted numbers
    for (long i = 0; i < size; i++) {
        output << data[i] << '\n';
    }

    output.close();

    if (!output) {
        return -1;
    }

    return 0;
}
