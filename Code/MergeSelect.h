#ifndef MERGESELECT
#define MERGESELECT

#include <iostream>
#include <ctime>
#include<vector>

using namespace std;

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
void merge(int arr[], int l, int mid, int end) {
    //cout << "in merge\n";
    int size_1 = mid - l + 1;
    int size_2 = end - mid;

    int* left_arr = new int[size_1];
    int* right_arr = new int[size_2];


    for (int i = 0; i < size_1; i++) {
        left_arr[i] = arr[l + i];}

    for (int j = 0; j < size_2; j++) {
        right_arr[j] = arr[mid + 1 + j];
    }
    int i, j, k;
    i = 0;
    j = 0;
    k = l;

    while (i < size_1 && j < size_2) {
        if (left_arr[i] <= right_arr[j]) {
            arr[k] = left_arr[i];
            i++;
        }
        else {
            arr[k] = right_arr[j];
            j++;
        }
        k++;
    }
    while (i < size_1) {
        arr[k] = left_arr[i];
        i++;
        k++;
    }

    while (j < size_2) {
        arr[k] = right_arr[j];
        j++;
        k++;
    }
    delete[] left_arr;
    delete[] right_arr;
}

void merge_sort(int unmerged[], int l, int h) {
    //cout << " l is: " << l << " and h is: " << h << endl;
    if (l >= h) return;
    int mid = (l+ h) / 2;

    merge_sort(unmerged,l, mid);
    merge_sort(unmerged,mid+1, h);
    merge(unmerged,l,mid,h);
}



#endif