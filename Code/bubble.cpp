//
// Created by Jason Yang on 10/21/22.
//

void bubbleSort(int* arr, size) {
    cout << "Bubble sort in progress " << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}
