#ifndef HEAPBETTER
#define HEAPBETTER

#include <iostream>
#include <vector>
#include <cmath>

class Heap {
public:
    int size = 0; // number of elements in the heap
    int* Arr; // array to store the elements
    Heap(int* a, int size); // constructor
    void max_heapify(int i); //Maintains the max heap property
    void heapSort(); //Prints the array in ascending order (sorts the array smallest to largest)
    void buildMaxHeap(); //makes a max heap from unsorted array
};

Heap::Heap(int* a, int size) {
    this->size = size;
    Arr = a;
    buildMaxHeap();
}

void Heap::buildMaxHeap() {
    int n = size;
    for(int i = floor((n-1)/2); i >= 0; i--){
        max_heapify(i);
    }
}


void Heap::max_heapify(int i) {
    int largest = i;
    int leftIndex = i*2 + 1;
    int rightIndex = i*2 + 2;
    if( (leftIndex < size) && (Arr[i] < Arr[leftIndex]) ){
        largest = leftIndex;
    }
    if((rightIndex < size) && (Arr[largest] < Arr[rightIndex])){
        largest = rightIndex;
    }
    if(largest != i){
        swap(Arr[i], Arr[largest]);
        max_heapify(largest);
    }
}
void Heap::heapSort() {
    buildMaxHeap();
    int n = size-1;
    for (int i = n; i >= 0; i--){
        int temp = Arr[i];
        Arr[i] = Arr[0];
        Arr[0] = temp;
        size--;
        max_heapify(0);
    }
}

void heapSort(int* arr, int n){
    Heap h(arr, n); // create heap using array
    h.heapSort();// call heapsort on array
}


#endif