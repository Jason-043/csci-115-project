
#include <iostream>
#include "MergeSelect.h"
#include "heap_better.h"
#include "bubble.h"
#include "quicksort.h"
#include "Radix2.h"
using namespace std;

void print(int arr[], int size){
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
    print(arr, arrSize);
//    bubbleSort(arr, arrSize);
//    MergeSort(arr, 0, arrSize-1);
//    selectionSort(arr, arrSize);
    //cout << "vecotr heap test" << endl;
   //Heap * heapTest = new Heap(vecchio);
   // heapTest->printArray();
   // heapTest->ascendingHeapSort();
    radixsort(arr);
    print(arr, arrSize);
    return 0;
}
