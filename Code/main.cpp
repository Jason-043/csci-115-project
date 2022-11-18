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
    char tab = 9;

    int arrSize = forty;
    for( int r = 0; r < 6; r ++) { // r decides size: 0->1,000 | 1->10,000 | 2->40,000 | 3->75,000 | 4->100,000 | 5->200,000
        if(r == 0) arrSize = 1000;
        else if(r == 1) arrSize = 10000;
        else if(r == 2) arrSize = 40000;
        else if(r == 3) arrSize = 75000;
        else if (r == 4) arrSize = 100000;
        else arrSize = 200000;
        cout << "TESTING WITH SIZE: " << arrSize << endl;
        for (int k = 0; k < 4; k++) { // k represents the type of array 0-sorted, 1-random, 2-half, other-reverse
            int *arr = array_choice(k, arrSize); // make array of choice k
            vector<int> vecchio;
            for (int i = 0; i < arrSize; i++) { // fill in vecchio with arr
                vecchio.push_back(arr[i]);
            }
            for (int i = 0; i < 3; i++) {// three times (three trials)
                start = clock();
                // sort
            merge_sort(arr, 0, arrSize - 1); // working
//            bubbleSort(arr, arrSize); // working
//            selectionSort(arr, arrSize); // working
//            insertionSort(arr, arrSize); // working
//            radixsort(arr, arrSize); // working
//            countingSort(arr, arrSize); // working

//            quickSort(arr, 0, arrSize-1, 0); // broken
//            Heap * heapTest = new Heap(vecchio, 1); //flag 1 indicates ascending order
//            heapTest->ascendingHeapSort();
//      heapsort broken with random array
//      heapsort broken with random array//      heapsort broken with random array//      heapsort broken with random array
                end = clock();
                double timeElapsed = (double) (end - start);
                double elapsedSeconds = timeElapsed / CLOCKS_PER_SEC;
                cout << tab << tab << "time for trial " << i + 1 << ": " << elapsedSeconds << endl;
            }
        }
    }


//    print(arr, arrSize);
//    selectionSort(randArr, arrSize);
//    merge_sort(randArr, 0, arrSize-1); // working
//    MergeSort(arr, 0, arrSize-1); // working
//    radixsort(arr, arrSize); // working
//    print(arr, arrSize);

//    cout << "vector heap test" << endl; // working
//    heapTest->printArray();
//    heapTest->ascendingHeapSort();
//


    return 0;
}
