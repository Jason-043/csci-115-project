#include<iostream>


using namespace std; 
void print_arr(int* arr,int size){
	for(int i=0; i<size; i++){
		cout<<arr[i]<<endl;
	}	
}	

int* array_choice(int choice, int size){

	int * arr_choice= new int[size]; // MAKE ARRAY 
	
	if(choice==0){
		cout<<"0 SORTED ARAY\n"; 
		for(int i=0; i< size; i++){
		arr_choice[i]= i; // SORTED 
		}
	}
	else if(choice ==1){
		cout<<"1 RANDOM ARAY\n"; 
		for(int i=0; i< size; i++){
			arr_choice[i]= rand() %100; // RANDOM ARRAY
		}
	}	
	else if(choice==2){
		cout<<"2 PARTIALLY SORTED ARAY\n"; 
		for(int i=0; i< size; i++){
			if(i < (size/2))
			arr_choice[i]= i;
			else
			arr_choice[i]= rand()% 100; 
		}
	}
	else{
		int j =0; 
		cout<<"REVERSE ARRAY\n";
		for(int i= size-1; i>=0; i--){
			arr_choice[j]= i;
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
}

