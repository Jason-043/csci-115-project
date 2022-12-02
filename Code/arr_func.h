#ifndef ARR_FU_H
#define ARR_FU_H

#include <iostream>
using namespace std; 
void print_arr(int* arr,int size){
	for(int i=0; i<size; i++){
		cout<<arr[i]<<endl;
	}	
}

int* array_choice(int choice, int size, int range = 100){
    char tab = 9;
	int* arr_choice= new int[size]; // MAKE ARRAY

	if(choice==0){
		for(int i=0; i< size; i++){
		arr_choice[i]= (i%range); // SORTED
		}
	}
	else if(choice ==1){
		for(int i=0; i< size; i++){
			arr_choice[i]= rand() % range; // RANDOM ARRAY
		}
	}
	else if(choice==2){ // half sorted
		for(int i=0; i< size; i++){
			if(i < (size/2))
			arr_choice[i]= (i%range);
			else
			arr_choice[i]= rand()% range;
		}
	}
	else{
		int j =0;
		for(int i= size-1; i>=0; i--){
			arr_choice[j]= (i%range);
				j++;
		}
	}
return arr_choice; // RETURN THE PROPER ARRAY
}
/*
int main(){
int size =10; 
int* array= new int[size];
int arr_choice=0; 

cout<<" which array do you want bro\n"; 
	cin>> arr_choice; 

print_arr(array_choice(arr_choice, size), size); 
for(int i=0; i<4;i++){
//	mergesort(array_choice(i, size), SIZE);// HOW YOU CALL ARR_FUNC IN MAIN 

}

*/
//}

//    int range = 100; // range of possible numbers in the array
//    for(int i = 0; i < arrSize; i++){
//        vecchioRand[i] = rand() % range;
//        randArr[i] = rand() % range;
//    }
//     build a half sorted array
//    for(int i = 0; i < arrSize; i++){
//        vecchioHalf[i] = rand() % range;
//        halfArr[i] = rand() % range;
//    }
//     build a sorted array
//    for(int i = 0; i < arrSize; i++){
//        vecchioSort[i] = i;
//        sortedArr[i] = i;
//    }
// Reverse Sorted
//    int j = 0;
//    for(int i = arrSize-1; i>=0; i--){
//        vecchioRev[j] = i;
//        revArr[j++] = i;
//    }
//  0 1 2 ..9
#endif