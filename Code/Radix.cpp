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
    /*
    for (int i = 0; i < originalSize; ++i){
        cout << "Original at "<< i <<": "<< original[i] << endl;
    }
    */
    //cout << original[8];
   /* if (maxValue > 0 ){
        maxValue += 1;
    }
    */
    //maxValue+1;
    int freq[maxValue+1] ;
    for (int i = 0; i <= maxValue; ++i){
        freq[i] = 0;
    }
    /*for (int i = 0; i < maxValue; ++i){
        cout << "Freq at "<< i <<": "<< freq[i] << endl;
    }*/
    //cout <<"-------"<<endl;
    for (int i = 0; i < originalSize; ++i){
        freq[original[i]] += 1;
    }
    /*Print Freq
    for (int i = 0; i <= maxValue; ++i){
        cout << "Freq at "<< i <<": "<< freq[i] << endl;
    }

    cout <<"-------"<<endl;
    */
    //cout << "Freq at "<< 6 <<": "<< freq[maxValue] << endl;
    int summ[maxValue+1];
    summ[0] = freq[0];
    for(int j = 1; j <= maxValue; ++j){
        summ[j] = summ[j-1] + freq[j];
    }
    /*
    for (int i = 0; i <= maxValue; ++i){
        cout << "Summ at "<< i <<": "<< summ[i] << endl;
    }
    */
    int output[originalSize];

//Lines 9-11 of suedo code
    for (int i = 0; i < originalSize; ++i){
        output[i] = 0;
    }
    //cout <<"-------"<<endl;
    /*
    cout <<"-------1"<<endl;
    cout << output[0]<<endl;
    cout << output[1]<<endl;
    cout << output[2]<<endl;
    cout << output[3]<<endl;
    cout << output[4]<<endl;
    cout << output[5]<<endl;
    cout << output[6]<<endl;
    cout << output[7]<<endl;
    cout <<"-------1"<<endl;
    */
    //output[summ[original[7]]] = original[7];
    //cout << output[7] <<endl;
    for(int n = originalSize-1; n >= 0; n--){
        output[summ[original[n]]-1] = original[n];

        summ[original[n]] -= 1;
    }
    /*
    for (int i = 0; i < originalSize; ++i){
        cout << "Output at "<< i <<": "<< output[i] << endl;
    }
    */
    //cout << output[8]<<endl;

    /*
    for (int i = 0; i < originalSize; ++i){
        cout << "Output at "<< i <<": "<< output[i] << endl;
    }*/
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
void radixsort(int original2[]){
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

//int main(){
//
//    cout << "Size of Input array (Counting) : ";
//    cin >> originalSize;
//    int a1[originalSize];
//    cin.clear();
//    cin.ignore();
//    string input;
//    for(int i = 0; i < originalSize;++i ){
//        getline(cin, input);
//        a1[i] = stoi(input);
//    }
//    /*Sample Input
//    originalSize = 8;
//    int a2[8] = {2,5,3,0,2,3,0,3};
//    int a3[8] = {3,6,4,1,3,4,1,4};
//    */
//    cout << "--------"<<endl;
//    auto start = chrono::high_resolution_clock::now();
//    countingSort(a1);
//    auto end  = chrono::high_resolution_clock::now();
//    for (int i = 0; i < originalSize; ++i){
//        cout << "Output at "<< i <<": "<< a1[i] << endl;
//    }
//    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - start);
//    cout << "Time: " << elapsed.count()/1000.0 << endl;
//    //Radix
//    cout << "--------"<<endl;
//    cout << "Size of Input array (Radix) : ";
//    cin >> originalSize;
//    int a4[originalSize];
//    cin.clear();
//    cin.ignore();
//    for(int i = 0; i < originalSize;++i ){
//        getline(cin, input);
//        a4[i] = stoi(input);
//    }
//    //originalSize = 8;
//    //int a4[8] = {326,453,608,835,751,435,704,690};
//    cout << "--------"<<endl;
//     start = chrono::high_resolution_clock::now();
//    radixsort(a4);
//     end  = chrono::high_resolution_clock::now();
//    for (int i = 0; i < originalSize; ++i){
//        cout << "Output at "<< i <<": "<< a4[i] << endl;
//    }
//     elapsed = chrono::duration_cast<chrono::nanoseconds>(end - start);
//    cout << "Time: " << elapsed.count()/1000.0 << endl;
//
//
//    return 0;
//}
