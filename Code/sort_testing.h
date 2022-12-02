#ifndef CSCI_115_PROJECT_SORT_TESTING_H
#define CSCI_115_PROJECT_SORT_TESTING_H

#include <iostream>
#include <iomanip>
#include "MergeSelect.h"
#include "heap_better.h"
#include "bubble.h"
#include "quickSorts.h"
#include "arr_func.h"
//#include "array_func.h"
#include "Radix2.h"
#include <ctime>

using namespace std;

void testInsertionSort(int choice, int sizeIncrement){
    cout << "TESTING INSERTION SORT" << endl;
    int counter = 0;
    int arrSize = 0;
    double average = 0;
    cout << endl;
    for(int i = 0; i < 10; i++){
        arrSize += sizeIncrement;
        for(int j = 0; j < 3; j++){ // three times for three trials
            clock_t start = clock();
            //sort goes here
            int* arr = array_choice(choice, arrSize);
            insertionSort(arr, arrSize);
            clock_t end = clock();

            double timeElapsed = (double) (end - start);
            double elapsedSeconds = timeElapsed / CLOCKS_PER_SEC;
            cout << elapsedSeconds << " ";
            counter++;
            if (counter % 3 == 0) cout << endl;
        }
    }
}

void testSelectionSort(int choice, int sizeIncrement){
    cout << "TESTING SELECTION SORT" << endl;
    int counter = 0;
    int arrSize = 0;
    double average = 0;
    cout << endl;
    for(int i = 0; i < 10; i++){
        arrSize += sizeIncrement;
        for(int j = 0; j < 3; j++){ // three times for three trials
            clock_t start = clock();
            //sort goes here
            int* arr = array_choice(choice, arrSize);
            insertionSort(arr, arrSize);
            clock_t end = clock();
            double timeElapsed = (double) (end - start);
            double elapsedSeconds = timeElapsed / CLOCKS_PER_SEC;

            cout << elapsedSeconds << " ";
            counter++;
            if (counter % 3 == 0) cout << endl;
        }
    }
}
void testBubbleSort(int choice, int sizeIncrement){
    cout << "TESTING BUBBLE SORT" << endl;
    int counter = 0;
    int arrSize = 0;
    double average = 0;
    cout << endl;
    for(int i = 0; i < 10; i++){
        arrSize += sizeIncrement;
        for(int j = 0; j < 3; j++){ // three times for three trials
            clock_t start = clock();
            //sort goes here
            int* arr = array_choice(choice, arrSize);
            insertionSort(arr, arrSize);
            clock_t end = clock();
            double timeElapsed = (double) (end - start);
            double elapsedSeconds = timeElapsed / CLOCKS_PER_SEC;

            cout << elapsedSeconds << " ";
            counter++;
            if (counter % 3 == 0) cout << endl;
        }
    }
}
void testQuickSortFirst(int choice, int sizeIncrement){
    cout << "TESTING  QUICKSORT -- P = FIRST ELEMENT" << endl;
    int counter = 0;
    int arrSize = 0;
    double average = 0;
    cout << endl;
    for(int i = 0; i < 10; i++){
        arrSize += sizeIncrement; // update the size
        for(int j = 0; j < 3; j++){ // three times for three trials
            clock_t start = clock();
            //sort goes here
            int* arr = array_choice(choice, arrSize);
            quickSort(arr, 0, arrSize-1, 0);
            clock_t end = clock();
            double timeElapsed = (double) (end - start);
            double elapsedSeconds = timeElapsed / CLOCKS_PER_SEC;

            cout << elapsedSeconds << " ";
            counter++;
            if (counter % 3 == 0) cout << endl;
        }

    }
}
void testQuickSortMed(int choice, int sizeIncrement){
    cout << "TESTING QUICKSORT -- P = MEDIAN" << endl;
    int counter = 0;
    int arrSize = 0;
    double average = 0;
    cout << endl;
    for(int i = 0; i < 10; i++){
        arrSize += sizeIncrement;
        for(int j = 0; j < 3; j++){ // three times for three trials
            clock_t start = clock();
            //sort goes here
            int* arr = array_choice(choice, arrSize);
            quickSort(arr, 0, arrSize-1, 1);
            clock_t end = clock();
            double timeElapsed = (double) (end - start);
            double elapsedSeconds = timeElapsed / CLOCKS_PER_SEC;

            cout << elapsedSeconds << " ";
            counter++;
            if (counter % 3 == 0) cout << endl;
        }
    }
}
void testMergeSort(int choice, int sizeIncrement){
    cout << "TESTING MERGESORT" << endl;
    int counter = 0;
    int arrSize = 0;
    double average = 0;
    cout << endl;
    for(int i = 0; i < 10; i++){
        arrSize += sizeIncrement;
        for(int j = 0; j < 3; j++){ // three times for three trials
            clock_t start = clock();
            //sort goes here
            int* arr = array_choice(choice, arrSize);
            mergeSort(arr, 0, arrSize-1);
            clock_t end = clock();
            double timeElapsed = (double) (end - start);
            double elapsedSeconds = timeElapsed / CLOCKS_PER_SEC;

            cout << elapsedSeconds << " ";
            counter++;
            if (counter % 3 == 0) cout << endl;
        }
//        cout << "TESTING WITH SIZE: " << arrSize << endl;
//        for (int i = 0; i < 3; i++) {// three times (three trials)
//            clock_t start = clock();
//            int *arr = array_choice(choice, arrSize);
//            mergeSort(arr, 0, arrSize - 1);
//            clock_t end = clock();
//            double timeElapsed = (double) (end - start);
//            double elapsedSeconds = timeElapsed / CLOCKS_PER_SEC;
//            average += elapsedSeconds;
//            cout << "       time for trial " << i + 1 << ": " << elapsedSeconds << "\n";
//        }
//            cout << "       average of the trials: "<< average/3 << endl;
//            average = 0;
    }
}
void testHeapSort(int choice, int sizeIncrement){
    cout << "TESTING HEAPSORT" << endl;
    int counter = 0;
    int arrSize = 0;
    double average = 0;
    for(int i = 0; i < 10; i++){
        arrSize += sizeIncrement;
        for(int j = 0; j < 3; j++){ // three times for three trials
            clock_t start = clock();
            //sort goes here
            int* arr = array_choice(choice, arrSize);
            heapSort(arr, arrSize);
            clock_t end = clock();
            double timeElapsed = (double) (end - start);
            double elapsedSeconds = timeElapsed / CLOCKS_PER_SEC;

            cout << elapsedSeconds << " ";
            counter++;
            if (counter % 3 == 0) cout << endl;
        }
    }
}

void testCountingSort(int choice, int sizeIncrement){
    cout << "TESTING COUNTING SORT" << endl;
    int counter = 0;
    int arrSize = 0;
    double average = 0;
    cout << endl;
    for(int i = 0; i < 10; i++){
        arrSize += sizeIncrement;
        for(int j = 0; j < 3; j++){ // three times for three trials
            clock_t start = clock();
            //sort goes here
            int* arr = array_choice(choice, arrSize, arrSize/100); // final parameter indicates the range of the randomized array
            countingSort(arr, arrSize);
            clock_t end = clock();
            double timeElapsed = (double) (end - start);
            double elapsedSeconds = timeElapsed / CLOCKS_PER_SEC;

            cout << elapsedSeconds << " ";
            counter++;
            if (counter % 3 == 0) cout << endl;
        }
    }
}
void testRadixSort(int choice, int sizeIncrement){
    cout << "TESTING RADIX SORT" << endl;
    int counter = 0;
    int arrSize = 0;
    double average = 0;
    cout << endl;
    for(int i = 0; i < 10; i++){
        arrSize += sizeIncrement;
        for(int j = 0; j < 3; j++){ // three times for three trials
            clock_t start = clock();
            //sort goes here
            int* arr = array_choice(choice, arrSize, arrSize);
            radixSort(arr, arrSize);
            clock_t end = clock();
            double timeElapsed = (double) (end - start);
            double elapsedSeconds = timeElapsed / CLOCKS_PER_SEC;

            cout << elapsedSeconds << " ";
            counter++;
            if (counter % 3 == 0) cout << endl;
        }
    }
}
#endif //CSCI_115_PROJECT_SORT_TESTING_H
