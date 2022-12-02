#ifndef CSCI_115_PROJECT_BUBBLE_H
#define CSCI_115_PROJECT_BUBBLE_H
#include <iostream>
using namespace std;

void bubbleSort(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void selectionSort(int* arr, int size) {
    for (int i = 0; i < size-1; i++) {
        int min = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        if (min != i) {
            swap(arr[i], arr[min]);
        }
    }
}

void insertionSort(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        int j = i;
        while (j > 0 && (arr[j - 1] > arr[j])) {
            swap(arr[j], arr[j - 1]);
            j--;
        }
    }
}


#endif //CSCI_115_PROJECT_BUBBLE_H
