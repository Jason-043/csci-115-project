#ifndef CSCI_115_PROJECT_SORT_TESTING_H
#define CSCI_115_PROJECT_SORT_TESTING_H

#include <iostream>
#include <iomanip>
#include "MergeSelect.h"
#include "heap_better.h"
#include "bubble.h"
#include "quickSorts.h"
#include "arr_func.h"
#include "Radix2.h"
#include <ctime>

using namespace std;

void testInsertionSort(int choice, int arrSize){ // choice is given in main
    cout << "TESTING MERGESORT WITH SIZE:" << arrSize << endl;
    double average = 0;
    cout << "   TESTING WITH SIZE: " << arrSize << endl;
    for (int i = 0; i < 3; i++) {// three times (three trials)
        clock_t start = clock();
        int *arr = array_choice(choice, arrSize); // create array of the choice (randomized, sorted, etc)
        insertionSort(arr,arrSize);
        clock_t end = clock();
        double timeElapsed = (double) (end - start);
        double elapsedSeconds = timeElapsed / CLOCKS_PER_SEC;
        average += elapsedSeconds;
        cout << "       time for trial " << i + 1 << ": " << elapsedSeconds << "\n";
    }
    cout << "       average of the trials: "<< average/3 << endl;
}

void testSelectionSort(int choice, int arrSize){
    cout << "TESTING MERGESORT WITH SIZE:" << arrSize << endl;
    double average = 0;
    cout << "   TESTING WITH SIZE: " << arrSize << endl;
    for (int i = 0; i < 3; i++) {// three times (three trials)
        clock_t start = clock();
        int *arr = array_choice(choice, arrSize);
        selectionSort(arr, arrSize);
        clock_t end = clock();
        double timeElapsed = (double) (end - start);
        double elapsedSeconds = timeElapsed / CLOCKS_PER_SEC;
        average += elapsedSeconds;
        cout << "       time for trial " << i + 1 << ": " << elapsedSeconds << "\n";
    }
    cout << "       average of the trials: "<< average/3 << endl;
}
void testBubbleSort(int choice, int arrSize){
    cout << "TESTING MERGESORT WITH SIZE:" << arrSize << endl;
    double average = 0;
    cout << "   TESTING WITH SIZE: " << arrSize << endl;
    for (int i = 0; i < 3; i++) {// three times (three trials)
        clock_t start = clock();
        int *arr = array_choice(choice, arrSize);
        bubbleSort(arr, arrSize);
        clock_t end = clock();
        double timeElapsed = (double) (end - start);
        double elapsedSeconds = timeElapsed / CLOCKS_PER_SEC;
        average += elapsedSeconds;
        cout << "       time for trial " << i + 1 << ": " << elapsedSeconds << "\n";
    }
    cout << "       average of the trials: "<< average/3 << endl;
}
void testQuickSortFirst(int choice, int arrSize){
    cout << "TESTING MERGESORT WITH SIZE:" << arrSize << endl;
    double average = 0;
    cout << "   TESTING WITH SIZE: " << arrSize << endl;
    for (int i = 0; i < 3; i++) {// three times (three trials)
        clock_t start = clock();
        int *arr = array_choice(choice, arrSize);
        quickSort(arr, 0, arrSize-1, 0); // partition is first
        clock_t end = clock();
        double timeElapsed = (double) (end - start);
        double elapsedSeconds = timeElapsed / CLOCKS_PER_SEC;
        average += elapsedSeconds;
        cout << "       time for trial " << i + 1 << ": " << elapsedSeconds << "\n";
    }
    cout << "       average of the trials: "<< average/3 << endl;
}
void testQuickSortMed(int choice, int arrSize){
    cout << "TESTING MERGESORT WITH SIZE:" << arrSize << endl;
    double average = 0;
    cout << "   TESTING WITH SIZE: " << arrSize << endl;
    for (int i = 0; i < 3; i++) {// three times (three trials)
        clock_t start = clock();
        int *arr = array_choice(choice, arrSize);
        quickSort(arr, 0, arrSize-1, 0); // partition is median
        clock_t end = clock();
        double timeElapsed = (double) (end - start);
        double elapsedSeconds = timeElapsed / CLOCKS_PER_SEC;
        average += elapsedSeconds;
        cout << "       time for trial " << i + 1 << ": " << elapsedSeconds << "\n";
    }
    cout << "       average of the trials: "<< average/3 << endl;
}
void testMergeSort(int choice, int arrSize){
    cout << "TESTING MERGESORT WITH SIZE:" << arrSize << endl;
    double average = 0;
        cout << "   TESTING WITH SIZE: " << arrSize << endl;
        for (int i = 0; i < 3; i++) {// three times (three trials)
            clock_t start = clock();
            int *arr = array_choice(choice, arrSize);
            mergeSort(arr, 0, arrSize - 1);
            clock_t end = clock();
            double timeElapsed = (double) (end - start);
            double elapsedSeconds = timeElapsed / CLOCKS_PER_SEC;
            average += elapsedSeconds;
            cout << "       time for trial " << i + 1 << ": " << elapsedSeconds << "\n";
        }
            cout << "       average of the trials: "<< average/3 << endl;
}

void testHeapSort(int choice, int arrSize){
    cout << "TESTING MERGESORT WITH SIZE:" << arrSize << endl;
    double average = 0;
    cout << "   TESTING WITH SIZE: " << arrSize << endl;
    for (int i = 0; i < 3; i++) {// three times (three trials)
        clock_t start = clock();
        int *arr = array_choice(choice, arrSize);
        heapSort(arr, arrSize);
        clock_t end = clock();
        double timeElapsed = (double) (end - start);
        double elapsedSeconds = timeElapsed / CLOCKS_PER_SEC;
        average += elapsedSeconds;
        cout << "       time for trial " << i + 1 << ": " << elapsedSeconds << "\n";
    }
    cout << "       average of the trials: "<< average/3 << endl;
}

void testCountingSort(int choice, int arrSize){
    cout << "TESTING MERGESORT WITH SIZE:" << arrSize << endl;
    double average = 0;
    cout << "   TESTING WITH SIZE: " << arrSize << endl;
    for (int i = 0; i < 3; i++) {// three times (three trials)
        clock_t start = clock();
        int *arr = array_choice(choice, arrSize);
        countingSort(arr, 0, arrSize);
        clock_t end = clock();
        double timeElapsed = (double) (end - start);
        double elapsedSeconds = timeElapsed / CLOCKS_PER_SEC;
        average += elapsedSeconds;
        cout << "       time for trial " << i + 1 << ": " << elapsedSeconds << "\n";
    }
    cout << "       average of the trials: "<< average/3 << endl;
}
void testRadixSort(int choice, int arrSize){
    cout << "TESTING MERGESORT WITH SIZE:" << arrSize << endl;
    double average = 0;
    cout << "   TESTING WITH SIZE: " << arrSize << endl;
    for (int i = 0; i < 3; i++) {// three times (three trials)
        clock_t start = clock();
        int *arr = array_choice(choice, arrSize);
        radixSort(arr, arrSize);
        clock_t end = clock();
        double timeElapsed = (double) (end - start);
        double elapsedSeconds = timeElapsed / CLOCKS_PER_SEC;
        average += elapsedSeconds;
        cout << "       time for trial " << i + 1 << ": " << elapsedSeconds << "\n";
    }
    cout << "       average of the trials: "<< average/3 << endl;
}
#endif //CSCI_115_PROJECT_SORT_TESTING_H
