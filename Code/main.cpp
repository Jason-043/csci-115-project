#include <iostream>
#include "MergeSelect.h"
#include "heap_better.h"
#include "bubble.h"
#include "quickSorts.h"
#include "arr_func.h"
#include "Radix2.h"
#include <ctime>


using namespace std;
void print(int *arr, int size){
    for(int i = 0; i < size; i++){
        cout << arr[i] <<" ";
    }
    cout << endl;
}

int main(){

    clock_t start;
    clock_t end;
    int thousand = 1000;
    int tent = 10000;
    int forty = 40000;
    int seven = 75000;
    int hund = 100000;
    int twoHundo = 200000;
    int mil = 1000000;
    const int arrSize = twoHundo;

    vector <int> vecchioRand(arrSize);
    vector <int> vecchioHalf(arrSize);
    vector <int> vecchioSort(arrSize);
    vector <int> vecchioRev(arrSize);

    int* randArr = new int[arrSize];
    int* halfArr = new int[arrSize];
    int* sortedArr = new int [arrSize];
    int* revArr = new int [arrSize];
    int range = 100; // range of possible numbers in the array
    for(int i = 0; i < arrSize; i++){
        vecchioRand[i] = rand() % range;
        randArr[i] = rand() % range;
    }
//     build a half sorted array
//    for(int i = 0; i < arrSize; i++){
//        vecchioHalf[i] = rand() % range;
//        halfArr[i] = rand() % range;
//    }
//     build a sorted array
//    for(int i = 0; i < arrSize; i++){
//        vecchioSort[i] = i;
//        sortedArr[i] = i;
//    }
    // Reverse Sorted
//    int j = 0;
//    for(int i = arrSize-1; i>=0; i--){
//        vecchioRev[j] = i;
//        revArr[j++] = i;
//    }
   //  0 1 2 ..9

    start = clock();
//     sort goes here
    bubbleSort(halfArr, arrSize); // working
//    selectionSort(randArr, arrSize);
//    merge_sort(randArr, 0, arrSize-1); // working

    end = clock();
    double timeElapsed = (double)(end-start);
    double elapsedSeconds = timeElapsed / CLOCKS_PER_SEC;
    cout << "time: " << elapsedSeconds << endl;

//    print(arr, arrSize);
//    MergeSort(arr, 0, arrSize-1); // working
//    selectionSort(arr, arrSize); // working
//    radixsort(arr, arrSize); // working
//    countingSort(arr, arrSize); // working
//    insertionSort(arr, arrSize); // working
//    quickSort(arr, 0, arrSize-1, 0); // working
//    print(arr, arrSize);

//    cout << "vector heap test" << endl; // working
//    Heap * heapTest = new Heap(vecchio, 1); //flag 1 indicates ascending order
//    heapTest->printArray();
//    heapTest->ascendingHeapSort();
//


    return 0;
}
