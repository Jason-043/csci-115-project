#include <iostream>
#include <array>
#include <time.h>
using namespace std; 

void printArray(int arr[], int size){
	for(int i=0; i<size;i++){
		cout<< arr[i]<<endl; 
	}
}
int partition( int unsorted[], int p , int r){
	
		int i = p; 
		int j =r;
	// PIVOT CHOICE NUMBER 1--------------------------------------------------------------------------------------------------
	
		int pivot = unsorted[p];
		while(i < j){
			while(unsorted[j] > pivot){
              	 	 j--;
        			}
       			while (unsorted[i] <= pivot){
                		i++;
       				}
			if(i <j){
                		int temp = unsorted[i];
                		unsorted[i]= unsorted[j];
                		unsorted[j] = temp;
       		 		}
				
			}
				int temp2= unsorted[p];
				unsorted[p]=unsorted[j];
				unsorted[j]= temp2; 
        			return j;
}
	// PIVOT CHOICE 2 ----------------------------------------------------------------------------------
int partition_random( int unsorted[], int p, int r){
		
	        int random = p+rand() % (r-p); //random index off the array
	//	cout<<"random #: "<< random;

		int temp = unsorted[random];//swap random element with PIVOT element in orig. partition function
		unsorted[random] = unsorted[p];
		unsorted[p] = temp; 
	
		return partition(unsorted,p, r); 	
							}

	// PIVOT CHOICE 3 ----------------------------------------------------------------------------------
int partition_median( int unsorted[], int p, int r){
	int middle =0; 
	int first = unsorted[p];
	int pivot =0; 	
	int pivot_index=0; 
	/*	if((r+1) % 2 ==0){		//if array size is even two middle elemtents, else 1 middle element
	middle = (unsorted[r/2] + unsorted[(r+1)/2])  / 2  ;      // add two middle numbers
		}
	else//odd */
		middle = unsorted[(p+r)/2]; 
	
	int last = unsorted[r]; 
 	
//	cout<<"1st,middle, last: "<< first<<", "<<middle<<", "<<last<<endl;
	if(first < middle && first > last || first > middle && first < last) pivot = first;
	else if(last > middle && last < first || last <middle && last >first) pivot = last;
	else pivot = middle; 

//	cout<<"pivot "<<pivot <<endl;
	
		if(pivot==first)pivot_index = p;
		else if(pivot==middle) pivot_index = ((p+r)/2);
		else pivot_index = r; 	


		int temp = unsorted[pivot_index];//swap random element with PIVOT element in orig. partition function
		unsorted[pivot_index] = unsorted[p];
		unsorted[p] = temp; 
	return	partition( unsorted, p, r) ; 	

}
void quickSort(int unsorted[],int p, int r, int pivot_choice){ 


	if(p < r){
		int q = 0;

		if(pivot_choice ==1)
		q = partition(unsorted,p, r); 
		else if(pivot_choice==2)
		q = partition_random(unsorted,p, r); 
		else {
		q= partition_median(unsorted, p, r); 	
	
		}
	//	cout<<"p: "<<p<<", q: "<<q<<", q+1: "<<q+1<<", r: "<<r<<endl; 
		quickSort(unsorted, p, q-1, pivot_choice); 
		quickSort(unsorted, q+1, r, pivot_choice); 
			}
}

//
//int main(){
//
//	srand(time(NULL));
//	int size = 1000'000'000;
//	int* unsorted = new int[size];
//	int p =0;
//	int r = size-1;
//	int pivot_choice=0;
//	clock_t start, end;
//       	double elapsedClocks= 0.0;
//	double elapsedSeconds = 0.0;
//
//	for(int i=0; i< size; i++){
//		unsorted[i] = rand() % 10000;
//
//	}
///*	cout<<"1) Pivot = 1st element\n2) Pivot = Random Element\n3) Pivot = Median Value\n";
//		while(true){
//		cin>> pivot_choice;
//		if(pivot_choice <1 || pivot_choice > 3)
//			continue;
//		else break;
//		}
//		*/
//	//	printArray(unsorted, size);
//		cout<<"SIZE = "<<size <<endl;
//		for(int i =1; i<4;i++){
//		pivot_choice=i;
//		start = clock();
//		quickSort(unsorted,p, r, pivot_choice);
//		end = clock();
//		elapsedClocks= (double) (end -start);
//		elapsedSeconds= elapsedClocks / CLOCKS_PER_SEC;
//		if(pivot_choice==1) cout<<"Pivot = 1st element running time: ";
//		else if(pivot_choice==2)cout<<"Pivot = Random element, running time: ";
//		else cout<<"Pivot = Median Value, running time: ";
//		cout<<elapsedSeconds<<" seconds"<<endl;
//		}
//	//	printArray(unsorted, size);
//
//
//}
