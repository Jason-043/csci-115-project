#include <iostream>
#include "MergeSelect.h"
//#include "heap_better.h"
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
//cout yo
int main(){
    int thousand = 1000;
    int tent = 10000;
    int forty = 40000;
    int seven = 75000;
    int hund = 100000;
    int twoHundo = 200000;
    int mil = 1000000;
	int tenmil= 10000000;
	int hunned= 100000000;
	int abilli= 1000000000; 

	float average =0.00; 
    const int arrSize = tenmil;
	int* temp; 

    cout << "testing with size " << arrSize << endl;
//    for( int r = 0; r < 5; r ++){
    for(int k = 0; k < 4; k++) { // k represents the type of array 0-sorted, 1-random, 2-half, other-reverse
        // make array of choice k
        // vector <int> vecchio;
        // for(int i = 0; i < arrSize; i++){ // fill in vecchio with arr
        //     vecchio.push_back(arr[i]);
        // }
		if(k==0)cout<<"SORTED ARRAY\n";
		else if(k==1)cout<<"RANDOM ARRAY\n";
		else if(k==2)cout<<"PARTIALLY SORTED ARRAY\n";
		else cout<<"REVERSE ARRAY\n";
		
		temp= array_choice(k, arrSize); 
        for (int i = 0; i < 4; i++) {// three times (three trials)
//            merge_sort(arr, 0, arrSize - 1); // working
//            bubbleSort(arr, arrSize); // working
//            selectionSort(arr, arrSize);
//            radixsort(arr, arrSize); // working
//            countingSort(arr, arrSize); // working
//            quickSort(arr, 0, arrSize-1, 0); // working
//            Heap * heapTest = new Heap(vecchio, 1); //flag 1 indicates ascending order
//            heapTest->ascendingHeapSort();
//            heapsort broken with random array
//           heapsort broken with random array//      heapsort broken with random array//      heapsort broken with random array
            clock_t start = clock();
           // insertionSort(temp, arrSize); // working
            //merge_sort(temp, 0, arrSize-1); // working
            countingSort(temp, arrSize); // working
            //radixsort(temp, arrSize); // SEGFAULT
            //countingSort(temp, arrSize); // SEGFAULT
           // selectionSort(temp, arrSize); //WORKING WITH 75K 
           //bubbleSort(temp, arrSize); // working
            clock_t end = clock();
			temp = array_choice(k, arrSize); 
            double timeElapsed = (double) (end - start);
            double elapsedSeconds = timeElapsed / CLOCKS_PER_SEC;
			average += elapsedSeconds; 	
           // cout << "time " << i+1 << ": " << elapsedSeconds << endl;
           	if(i ==3)
			cout << "---AVERAGE--- = " << double(average/3.00) << endl<<endl;
        }
		//cout<<"clocks_per_sec "<< CLOCKS_PER_SEC<<endl; 
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

// testing testing 123
    return 0;
}
