#include "sort_testing.h"



void print(int *arr, int size){
    for(int i = 0; i < size; i++){
        cout << arr[i] <<" ";
    }
    cout << endl;
}

int main(){
    char tab = 9;
    double average = 0;
    int size = 0;
    int counter = 0;

for (int k = 0; k < 4; k++) { // k represents the type of array 0-sorted, 1-random, 2-half, other-reverse
    cout << endl;
    if (k == 0) {
        cout << "SORTED ARRAY" << endl;
    }
    else if (k == 1) {
        cout << "RANDOMIZED ARRAY" << endl;
    }
    else if (k == 2) {
        cout << "HALF SORTED ARRAY" << endl;
    }
    else {
        cout << "REVERSE SORTED ARRAY" << endl;
    }
//    testInsertionSort(k, 20000);
//    testSelectionSort(k, 20000);
//    testBubbleSort(k, 20000);
//    testQuickSortFirst(k, 17000); // partition = first element
//    testQuickSortMed(k, 5000000); // partition = middle element
//    testMergeSort(k, 5000000);
//    testHeapSort(k, 5000000);
//    testCountingSort(k, 10000000);
    testRadixSort(k, 10000000);
}



//    below is code that you can use to test each sort to check that they are working properly
//    int s = 15;
//    int* arr = array_choice(1, s, 100); // create randomized array
//    cout << "before sort: ";
//    print(arr, s);
//    insertionSort(arr, s);
//    selectionSort(arr, s);
//    bubbleSort(arr, s);
//    quickSort(arr, 0, s-1, 1);
//    mergeSort(arr, 0, s-1);
//    heapSort(arr, s);
//    countingSort(arr, s);
//    radixSort(arr, s);
//    cout << "after sort:  ";
//    print(arr, s);
// testing testing 123
    return 0;
}


//int arrSize = 150000;
//for( int r = 0; r < 6; r ++) { // r is size: 0->1,000 | 1->10,000 | 2->40,000 | 3->75,000 | 4->100,000 | 5->200,000
//if(r == 0) arrSize = 10000;
//else if (r == 1) arrSize = 100000;
//else if(r == 2) arrSize = 500000;
//else if(r == 3) arrSize = 1000000;
//else if(r == 4) arrSize = 2000000;
//else arrSize = 100000000;
//cout << "\nTESTING WITH SIZE " << arrSize << endl;
//for (int k = 0; k < 4; k++) { // k represents the type of array 0-sorted, 1-random, 2-half, other-reverse
////
////          radixsort(array_choice(k, arrSize, i), arrSize); // working
////          countingSort(arr, arrSize); // working
//for (int i = 0; i < 3; i++) {// three times (three trials)
////            radixsort(arr, arrSize); // working
//clock_t start = clock();
////sort goes here
////                radixsort(array_choice(k, arrSize, i, 100*arrSize), arrSize); // last parameter in arrchoice is range of numbers for random
////                countingSort(array_choice(k, arrSize, i, 10*arrSize), arrSize);
//
//
//clock_t end = clock();
//double timeElapsed = (double) (end - start);
//double elapsedSeconds = timeElapsed / CLOCKS_PER_SEC;
//average += elapsedSeconds;
//cout << tab << tab<< "time for trial " << i + 1 << ": " << elapsedSeconds << "\n";
//}
//cout << tab << tab<< "average of the trials: "<< average/3 << endl;
//average = 0;
//}
//}