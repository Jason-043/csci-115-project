
#include <iostream>
#include "MergeSelect.h"
#include "heap_better.h"
#include "bubble.h"
#include "quickSorts.h"
#include "Radix2.h"


using namespace std;
void print(int *arr, int size){
    for(int i = 0; i < size; i++){
        cout << arr[i] <<" ";
    }
    cout << endl;
}

int main(){
    const int arrSize = 10;
    vector <int> vecchio(arrSize);

    int arr[arrSize];
    int range = 100; // range of possible numbers in the array
    for(int i = 0; i < arrSize; i++){
        vecchio[i] = rand() % range;
        arr[i] = rand() % range;
    }
    // build a half sorted array
    for(int i = 0; i < arrSize; i++){
        vecchio[i] = rand() % range;
        arr[i] = rand() % range;
    }
    // build a sorted array
    for(int i = 0; i < arrSize; i++){
        vecchio[i] = i;
        arr[i] = i;
    }
    // Reverse Sorted
    for(int i = arrSize-1; i>=0 ; i--){
        vecchio[i] = i;
        arr[i] = i;
    }
   //  0 1 2 ..9
    print(arr, arrSize);
//    bubbleSort(arr, arrSize); // working
//    MergeSort(arr, 0, arrSize-1); // working
//    selectionSort(arr, arrSize); // working
//    radixsort(arr, arrSize); // working
//    countingSort(arr, arrSize); // working
//    insertionSort(arr, arrSize); // working
//    quickSort(arr, 0, arrSize-1, 0); // working
    print(arr, arrSize);

//    cout << "vector heap test" << endl; // working
//    Heap * heapTest = new Heap(vecchio, 1); //flag 1 indicates ascending order
//    heapTest->printArray();
//    heapTest->ascendingHeapSort();
//


    return 0;
}
