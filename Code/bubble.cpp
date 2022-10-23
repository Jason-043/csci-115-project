#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
void bubbleSort(int* arr, int size) {
    cout << "Bubble sort in progress " << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
