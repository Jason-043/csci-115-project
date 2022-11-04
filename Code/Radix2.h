#ifndef CSCI_115_PROJECT_RADIX2_H
#define CSCI_115_PROJECT_RADIX2_H
#include <iostream>
#include <chrono>
using namespace std;
int originalSize;
void countingSort(int original[]){
    int maxValue = original[0];
    for(int i= 0; i < originalSize; ++i ){
        if (original[i] > maxValue){
            maxValue = original[i];
        }
    }
    int freq[maxValue+1] ;
    for (int i = 0; i <= maxValue; ++i){
        freq[i] = 0;
    }
    for (int i = 0; i < originalSize; ++i){
        freq[original[i]] += 1;
    }
    int summ[maxValue+1];
    summ[0] = freq[0];
    for(int j = 1; j <= maxValue; ++j){
        summ[j] = summ[j-1] + freq[j];
    }
    int output[originalSize];
    for (int i = 0; i < originalSize; ++i){
        output[i] = 0;
    }
 
    for(int n = originalSize-1; n >= 0; n--){
        output[summ[original[n]]-1] = original[n];

        summ[original[n]] -= 1;
    }
    for (int i = 0; i < originalSize; ++i){
        original[i] = output[i];
    }

}
void countingSort2(int original[], int div){
    int maxValue = original[0];
    for(int i= 0; i < originalSize; ++i ){
        if (original[i] > maxValue){
            maxValue = original[i];
        }
    }
    int freq[10]={0};
    for (int i = 0; i < 10; ++i){
        freq[i] = 0;
    }
    for (int i = 0; i < originalSize; ++i){
        freq[(original[i]/div)%10] += 1;
    }
    for(int j = 1; j < 10; ++j){
        freq[j] = freq[j-1] + freq[j];
    }
    int output[originalSize];
    for (int i = 0; i < originalSize; ++i){
        output[i] = 0;
    }
    for(int n = originalSize-1; n >= 0; n--){
        output[freq[(original[n]/div)%10]-1] = original[n];

        freq[(original[n]/div)%10]--;
    }
    for (int i = 0; i < originalSize; ++i){
        original[i] = output[i];
    }
}
void radixsort(int *original2 , int size){
    originalSize = size;
    int maxValue = original2[0];
    for(int i= 0; i < originalSize; ++i ){
        if (original2[i] > maxValue){
            maxValue = original2[i];
        }
    }

    for(int div=1; maxValue/div > 0; div *= 10){
        countingSort2(original2, div);
    }

}
#endif //CSCI_115_PROJECT_RADIX2_H
