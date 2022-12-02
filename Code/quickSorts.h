#ifndef CSCI_115_PROJECT_QUICKSORTS_H
#define CSCI_115_PROJECT_QUICKSORTS_H
#include <iostream>
#include <array>
using namespace std;

int partition(int *arr, int low, int high, int partition){
    int middleIndex = (high + low) / 2;
    int medianIndex = 0;
    if(arr[middleIndex] < arr[low] && arr[low] < arr[high]){ // find median index
        medianIndex = low;
    }
    else if(arr[low] < arr[high] && arr[high] < arr[middleIndex]){
        medianIndex = high;
    }
    else{
        medianIndex = middleIndex;
    }

    int random = (rand() % (high - low)) + low; //for random pivot

    int x = arr[low]; // pivot selection
    if(partition == 0) // first element
        x = arr[low];
    else if(partition == 1) { // median element
        swap(arr[medianIndex], arr[low]);
    }
    x = arr[low]; // actual pivot selection
    int i = low - 1;
    int j = high + 1;
    while (true){
        do{
            j--;
        } while(arr[j] > x);
        do{
            i++;
        } while(arr[i] < x);
        if(i < j){
            swap(arr[i], arr[j]);
        }
        else return j;
    }
}

void quickSort(int *arr, int p, int r, int part){ // 0 = first, 1 = median, else random
    int q = 0;
    static int flag = part;
    if(p < r){
        q = partition(arr, p, r, flag);
        quickSort(arr, p, q, flag);
        quickSort(arr, q + 1, r, flag);
    }
}


#endif //CSCI_115_PROJECT_QUICKSORTS_H
