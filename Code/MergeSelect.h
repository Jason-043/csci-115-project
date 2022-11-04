#ifndef MERGESELECT
#define MERGESELECT

#include <iostream>
#include <ctime>
#include<vector>

using namespace std;

void selectionSort(int* arr, int size) {
    cout << "Selection sort in progress " << endl;
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

void Merge(int A[], int start, int mid, int end){ //makes the two subarrays
    int tempLeft = start; // starting index for left subarray
    int leftSize = (mid-start) + 1; // size of left subarray
    int* leftArray = new int[leftSize]; // make the left subarray
    for (int i = 0; i < leftSize; i++){ // fill in arrays
        leftArray[i] = A[tempLeft];
        tempLeft++;
    }
    int tempRight = mid+1; // starting index for right subarray
    int rightSize = end - mid; // size of right subarray
    int * rightA = new int[rightSize]; // make the right subarray
    for(int i = 0; i < rightSize; i++){ // fill in arrays
        rightA[i] = A[tempRight];
        tempRight++;
    }
    tempLeft = 0; // make them 0 to be able to iterate through left and right arrays
    tempRight = 0; // tempLeft and tempRight are now indexes
    for(int i = start; i <= end; i++) {
        if (leftArray[tempLeft] <= rightA[tempRight] && (tempLeft < leftSize)) {// if left is smaller
            A[i] = leftArray[tempLeft];
            tempLeft++;
        }
        else if (leftArray[tempLeft] > rightA[tempRight] && (tempRight < rightSize)) {//if right is smaller
            A[i] = rightA[tempRight++];
        }
        else if (tempLeft >= leftSize) { // if left is "empty"
            for (tempRight; tempRight < rightSize; tempRight++) {
                A[i] = rightA[tempRight];
                i++;
            }
        }
        else if (tempRight >= rightSize) { // if right is "empty"
            for (tempRight; tempLeft < leftSize; tempLeft++) {
                A[i] = leftArray[tempLeft];
                i++;
            }
        }

    }
}
void MergeSort(int array[], int start, int end){
    int midPoint = 0;
    if(start < end){
        midPoint = (start + end) / 2;
        MergeSort(array, start, midPoint);
        MergeSort(array, midPoint + 1, end);
        Merge(array, start, midPoint, end);
    }
}



#endif