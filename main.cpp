
// Christian Francis, David Cunha, Erela Braddom
// Lab 5, ECE 2161-001
// Reads numbers, runs the selected sort, reports CPU time,
// and saves the sorted results.
// Adapted from the framework supplied by Dr. Sarvesh Kulkarni.

#include <iostream>
#include <ctime>
#include <limits>
#include <vector>
#include "myheaders.h"
#include "Christian/insertionSort.h"
#include "Christian/heapSort.h"
#include "David/bubblesort.h" 
#include "David/mergesort.h" 
#include "Erela/selectionSort.h"
#include "Erela/quickSort.h"

using namespace std;

// Does the menu, input data, sorting timers, and output files
int main() {
    int choice;
    int sz = 0;
    long data[MAXSIZE], wData[MAXSIZE];

    double begin_time, end_time, cpu_time_used;
    string ofilename;

    while (true) {
        printmenu();

        // Check the user's menu selection
        if (!(cin >> choice)) {
            if (cin.eof()) {
                return 0;
            }

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter a menu number.\n";
            continue;
        }

        if (choice == 0) {
            cout << "Exiting program.\n";
            return 0;
        }

        if (choice < 1 || choice > 7) {
            cout << "Invalid selection.\n";
            continue;
        }

        if (choice == 1) {
            sz = readfile("lab5_input.txt", data);

            if (sz < 0) {
                cout << "Could not read the input file. Check the "
                     << "filename, contents, and array capacity.\n";
                sz = 0;
            } else {
                cout << "File size is: " << sz << '\n';
            }

            continue;
        }

        if (sz == 0) {
            cout << "Read a nonempty input file using option 1 first.\n";
            continue;
        }

        // Make sure to give every sort the same unsorted data.
        for (int i = 0; i < sz; i++) {
            wData[i] = data[i];
        }

        // Time only the selected sorting function
        switch (choice) {
            case 2:
                begin_time = clock();
                insertionSort(wData, sz);
                end_time = clock();

                ofilename = "lab5_A_out.txt";
                break;

            case 3:
                begin_time = clock();
                heapSort(wData, sz);
                end_time = clock();

                ofilename = "lab5_B_out.txt";
                break;
           
            //bubble sort 
            case 4: {
                vector<long int> sortData(wData, wData + sz);

                begin_time = clock();
                bubbleSort(sortData);
                end_time = clock();

                for (int i = 0; i < sz; i++) {
                    wData[i] = sortData[i];
                }

                ofilename = "lab5_C_out.txt";
                break;
            }

            //merge sort 
            case 5: {
                vector<long int> sortData(wData, wData + sz);

                begin_time = clock();
                mergeSort(sortData, 0, sz - 1);
                end_time = clock();

                for (int i = 0; i < sz; i++) {
                    wData[i] = sortData[i];
                }

                ofilename = "lab5_D_out.txt";
                break;
            }

            // Selection Sort - Erela
            case 6:
                begin_time = clock();
                selectionSort(wData, sz);
                end_time = clock();
                ofilename = "lab5_E_out.txt";
                break;

            // Quicksort - Erela
            case 7:
                begin_time = clock();
                quickSort(wData, 0, sz - 1);
                end_time = clock();
                ofilename = "lab5_F_out.txt";
                break;

            default:
                continue;
        }

        // CPU time in seconds.
        cpu_time_used = (end_time - begin_time) / CLOCKS_PER_SEC;
        cout << "Sort ran for " << cpu_time_used << " seconds.\n";

        // Save the sorted data after stopping the timer.
        if (writefile(wData, sz, ofilename) == -1) {
            cout << "Could not write the output file.\n";
        } else {
            cout << "Output written to " << ofilename << '\n';
        }
    }

    return 0;
}
