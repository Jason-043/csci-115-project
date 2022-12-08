#include <iostream>
using namespace std;


void countingSort(int* original, int div, int size){
    int maxValue = original[0];
    for(int i= 0; i < size; ++i ){
        if (original[i] > maxValue){
            maxValue = original[i];
        }
    }
    int* freq = new int [10];
    for (int i = 0; i < 10; ++i){
        freq[i] = 0;
    }
    for (int i = 0; i < size; ++i){
        freq[(original[i]/div)%10] += 1;
    }
    for(int j = 1; j < 10; ++j){
        freq[j] = freq[j-1] + freq[j];
    }
    int* output = new int [size];
    for (int i = 0; i < size; ++i){
        output[i] = 0;
    }
    for(int n = size-1; n >= 0; n--){
        output[freq[(original[n]/div)%10]-1] = original[n];

        freq[(original[n]/div)%10]--;
    }
    for (int i = 0; i < size; ++i){
        original[i] = output[i];
    }
}
void radixsort(int *original2 , int size){
    size = size;
    int maxValue = original2[0];
    for(int i= 0; i < size; ++i ){
        if (original2[i] > maxValue){
            maxValue = original2[i];
        }
    }

    for(int div=1; maxValue/div > 0; div *= 10){
        countingSort(original2, div, size);
    }

}
void bruteForceTwoSum(int* arr, int arrSize, int goal){
    for(int i = 0; i < arrSize; i++){
        for(int j = i; j < arrSize; j++){
            if(arr[i]+arr[j] == goal){
                cout << "found :)" << arr[i] << "+" << arr[j]<< endl;
                return;
            }
        }
    }
}

void twoSumSortPoint(int* arr, int arrSize, int goal){
    radixsort(arr, arrSize);
    bool found = false;
    int low, high;
    low = 0;
    high = arrSize-1;
    int sum = 0;
    while((!found) && (low != high)){
        sum = arr[low] + arr[high];
        if(sum == goal){
            found = true;
            cout << "found :)" << arr[low] << "+" << arr[high] << endl;
        }
        else{
            if(sum < goal){
                low++;
            }
            else if(sum > goal){
                high++;
            }
        }

    }
}

int main(){
    int userInput = 0;
    cout << "enter the size of your array: ";
    cin >> userInput;
    int arrSize = userInput;
    int arr[userInput];
    for(int i = 0; i < arrSize; i++){
        cout << "\nenter number for " << i << " index: ";
        cin >> userInput;
        arr[i] = userInput;
    }


    cout << "enter 1 for brute force method:" << endl;
    cout << "enter 2 for efficient method: \n";
    cin >> userInput;
    cout << "enter your target number: \n";
    int target= 0;
    cin >> target;
    if(userInput == 1){
        bruteForceTwoSum(arr, arrSize, target);
    }
    else if(userInput == 2){
        twoSumSortPoint(arr, arrSize, target);
    }
    else{
        cout << "invalid input" << endl;
    }

}