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
void print(int *arr, int size){
    for(int i = 0; i < size; i++){
        cout << arr[i] <<" ";
    }
    cout << endl;
}
//cout yo


int main(){
//    cout << setprecision(10);
    char tab = 9;
    int thousand = 1000;
    int tent = 10000;
    int forty = 40000;
    int seven = 75000;
    int hund = 100000;
    int twoHundo = 200000;
    int mil = 1000000;
    double average = 0;

    int arrSize = twoHundo;
//    for( int r = 0; r < 6; r ++) { // r is size: 0->1,000 | 1->10,000 | 2->40,000 | 3->75,000 | 4->100,000 | 5->200,000
//        if(r == 0) arrSize = 1000;
//        else if (r == 1) arrSize = 10000;
//        else if(r == 2) arrSize = 40000;
//        else if(r == 3) arrSize = 75000;
//        else if(r == 4) arrSize = 100000;
//        else arrSize = 200000;
        cout << "\nTESTING WITH SIZE " << arrSize << endl;
        for (int k = 0; k < 4; k++) { // k represents the type of array 0-sorted, 1-random, 2-half, other-reverse
            // make array of choice k
            // vector <int> vecchio;
            // for(int i = 0; i < arrSize; i++){ // fill in vecchio with arr
            //     vecchio.push_back(arr[i]);
            // }
//          merge_sort(array_choice(k, arrSize, i), 0, arrSize - 1); // working
//
//          radixsort(array_choice(k, arrSize, i), arrSize); // working
//          countingSort(arr, arrSize); // working
            for (int i = 0; i < 3; i++) {// three times (three trials)
//            radixsort(arr, arrSize); // working
//
//            quickSort(arr, 0, arrSize-1, 0); // working
//            Heap * heapTest = new Heap(vecchio, 1); //flag 1 indicates ascending order
//            heapTest->ascendingHeapSort();
//            heapsort broken with random array
//           heapsort broken with random array//      heapsort broken with random array//      heapsort broken with random array
                clock_t start = clock();
                //sort goes here
//                radixsort(array_choice(k, arrSize, i), arrSize);
//                QuickSort(array_choice(k, arrSize, i),0, arrSize-1, 0);
                clock_t end = clock();
                double timeElapsed = (double) (end - start);
                double elapsedSeconds = timeElapsed / CLOCKS_PER_SEC;
                average += elapsedSeconds;
                cout << /*tab << tab<< "time for trial " << i + 1 << ": " <<*/ elapsedSeconds << " ";
            }
            cout << tab << tab<< "average of the trials: "<< average/3 << endl;
            average = 0;
        }
//    }


//    print(arr, arrSize);
//    selectionSort(randArr, arrSize);
//    merge_sort(randArr, 0, arrSize-1); // working
//    MergeSort(arr, 0, arrSize-1); // working
//    print(arr, arrSize);

//    cout << "vector heap test" << endl; // working
//    heapTest->printArray();
//    heapTest->ascendingHeapSort();

//    int s = 1000000000;
//    int* arr = array_choice(1, s, 0);

//    print(arr, 10);
//    merge_sort(arr, 0, s-1); // working yes
//    QuickSort(arr, 0, s-1, 4); // working yes
//    radixsort(arr, s); // working yes


//    vector<int> vecchio;
//    Heap * heapTest = new Heap(vecchio, 1); //flag 1 indicates ascending order
//    heapTest->printArray();
//    heapTest->ascendingHeapSort();
//    print(arr, 10);
// testing testing 123

//heapsort not working with sorted, p = first, size 2hundo
    return 0;
}
