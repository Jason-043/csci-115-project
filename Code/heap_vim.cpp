#include <iostream>
#include <vector>
#include <cmath>
//#include "heap_sort.h"
using namespace std;
class Heap {
	public:
		int n=0; // number of elements in the heap
		vector<int> Arr; // Vector to store the elements
		Heap(vector<int> a); // Constructor
		Heap(vector<int> a, int flag); // Constructor with flag for max or min initialization
		void printArray(); // Prints the array
				   // Max heap
		void modifyValMax(int i, int val); //Modify value
		void insert_value_maxHeap(int val); //Adds value at the end of array and calls max_heapify
		void max_heapify(int i); //Maintains the max heap property
		int extract_maximum(); //Return the maximum element in heap and swap last element with first element
		void ascendingHeapSort(); //Prints the array in ascending order
		void buildMaxHeap(); //Heapifies entire list
		void printMax(); 

		//Min Heap
		void modifyValMin(int i, int val); //Modify value
		void insert_value_minHeap(int val); // Adds value at the end of array and calls min_heapify
		void min_heapify(int i); //Maintains min heap property
		int extract_minimum(); //Return the minimum element in heap and swap last element with first element
		void descendingHeapSort(); //Prints the array in descending order
		void buildMinHeap(); //Heapifies entire list
		void printMin(); 
};
void Heap::printArray() {
	cout<<"\nHEAP CONTENTS\n\n"; 
	for (int i = 0; i < this->n;i++) {
		cout << Arr[i] << " ";
	}
	cout<<endl;
}
void Heap::printMax(){
	cout<<"\n\nMax is : "<<this->Arr.at(0)<<endl;
}
void Heap::printMin(){
	cout<<"\n\nMin is : "<<this->Arr.at(0)<<endl;
}

// cout << Arr[n - 1] << endl;
Heap::Heap(vector<int> a) {
	for (int i = 0; i < a.size(); ++i) { // Equivalent to this->Arr = a; for vectors, cannot use assignment operator for arrays
		this->Arr.push_back(a[i]);
		this->n += 1;
	}
	this->buildMaxHeap();
}
Heap::Heap(vector<int> a, int flag) { // constructor copies vector from input into object
	for (int i = 0; i < a.size(); ++i) {
		//Arr.at(i) = a.at(i); 
		this->Arr.push_back(a.at(i));
		// this->Arr.push_back(a[i]);
		this->n += 1;                 // increase objects size by 1 
	}
	if (flag == 1) { // Ascending order, Build min heap
		this->buildMinHeap();
	}
	else { // Descending order,  Build max heap
		this->buildMaxHeap();
	}
}
void Heap::min_heapify(int i) {
	int left_child = (2 * i) + 1; // left index (this assumes that the vector starts at index 0)
	int right_child = 2 * i + 2; // right index
	int smallestIndex = i; // Index of largest element (so far)


	if (left_child < this->n && this->Arr[left_child] < this->Arr[smallestIndex]) {
		smallestIndex = left_child;
	}
	if (right_child < this->n && this->Arr[right_child] < this->Arr[smallestIndex]) {
		smallestIndex = right_child;
	}
	if (smallestIndex != i) {
		int temp = this->Arr[i];
		this->Arr[i] = this->Arr[smallestIndex];
		this->Arr[smallestIndex] = temp;
		min_heapify(smallestIndex);
	}
}

// Max Heapify
void Heap::max_heapify(int i) {
	int left_child = (2 * i) + 1; // left index (this assumes that the vector starts at index 0)
	int right_child = (2 * i) + 2; // right index
	int largestIndex = i; // Index of largest element (so far)


	if (left_child < this->n && this->Arr[left_child] > this->Arr[largestIndex]) {
		largestIndex = left_child;
	}
	if (right_child < this->n && this->Arr[right_child] > this->Arr[largestIndex]) {
		largestIndex = right_child;
	}
	if (largestIndex != i) {
		int temp = this->Arr[i];
		this->Arr[i] = this->Arr[largestIndex];
		this->Arr[largestIndex] = temp;
		this->max_heapify(largestIndex);
	}
}
void Heap::buildMaxHeap() {
	int vec_size = this->Arr.size(); // Size of the array
	for (int i = floor(this->n / 2.0); i >= 0; i--) {
		this->max_heapify(i);// finding parent node and max_heapifying
	}
}
// Build Min Heap
void Heap::buildMinHeap() {
	int vec_size = this->n; // Size of the vector
	for (int i = floor(vec_size / 2.0); i >= 0; --i) {
		this->min_heapify(i);
	}

}
void Heap::ascendingHeapSort() {
	vector<int> le_sorted;

	int vec_size = this->n; // Size of the vector
	for(int i=this->n-1;i>=0;i--){
		int temp = this->Arr.at(0);  //ROOT NODE
		le_sorted.push_back(temp); 
		this->Arr.at(0)=this-> Arr.at(i);//SWAP ROOT WITH LAST NODE
		this->Arr.at(i)= temp; //LAST NODE IS NOW THE SMALLEST
		this->n--;
		min_heapify(0); 
	}
	cout<<"\nAscending Heapsort: \n";
	for(int i=0; i< le_sorted.size();i++){
		cout<<le_sorted.at(i)<<" ";
	}
	cout<<endl;
	//	return le_sorted; 
}

void Heap::descendingHeapSort(){
	vector<int> le_sorted;

	int vec_size = this->n; // Size of the vector
				//      cout<<"size of the vector is : "<< vec_size<<endl;
	for(int i=this->n-1;i>=0;i--){
		int temp = this->Arr.at(0);  //ROOT NODE
		le_sorted.push_back(temp);
		this->Arr.at(0)=this->Arr.at(i);//SWAP ROOT WITH LAST NODE
		this->Arr.at(i)= temp; //LAST NODE IS NOW THe largest
		this->n--;
		max_heapify(0);
	}
	cout<<"\nDescending Heapsort: \n";
	for(int i=0; i< le_sorted.size();i++){
		cout<<le_sorted.at(i)<<" ";
	}
	cout<<endl;


}

int Heap::extract_minimum(){ //Return the minimum element in heap and swap last element with first elemen
	int min = this->Arr.at(0);// first element in the heap , MIN
	this->Arr.at(0)=Arr.at(this->n-1);//swap last node w/1st node
	min_heapify(0);//maintain heap properties, call heapify on 0th node
	this->n --;
	return min;

}
int Heap::extract_maximum(){ //Return the maximum element in heap and swap last element with first elemen
	int max = this->Arr.at(0);	
	this->Arr.at(0)=Arr.at(this->n-1);
	max_heapify(0); 
	this->n --;
	return max; 			
}

void Heap:: insert_value_minHeap(int val){
	this->n++;
	this->Arr.at(this->n-1)=val;//insert at the end 
//	this->min_heapify(this->n-1);
	this->buildMinHeap();//when swimming use buildheap cause buildheap gets the parent node. need parent node to compare to children
}
void Heap:: insert_value_maxHeap(int val){
	this->n++;
	this->Arr.at(this->n-1)=val;;
	this->buildMaxHeap();
//	this->max_heapify(this->n-1);
//	this->max_heapify(0);

}
void Heap:: modifyValMax(int i, int val){
	
	while(1) {
	if (i<= this->n && i>=0) {
		this->Arr.at(i)= val;
		if(val > Arr.at(floor(i/2.0))){
			Arr.at(floor(i/2.0)) = val; 
			Arr.at(i) =this->Arr.at(floor(i/2.0));  
			}
	//	this->buildMaxHeap();
	//	max_heapify(i);
		return;
		}
	
	else {
		cout<<"Invalid position, try again\n";
		int position=-1, value=-1;
		cin>>position>>value;
		i= position;
		val= value; 
		cout<<"position is: "<<position<<", value is: "<<value<<endl;
		continue;
	//continue;
	}
		}
}

void Heap:: modifyValMin(int i, int val){
	if(i<= this->n && i>0)this->Arr.at(i-1)= val;      

}
int main() {
	vector<int> temp;
	cout << "Input: ";
	int input=0;
	int max=0;
	int min=0;
	bool max_ = false;     
	bool min_ = false;
   	int insert=0;
	int mod_index=0;
	int mod_val=0;
	while (1) {
		cin >> input;
		if (!cin)break;
		temp.push_back(input);
	}



	cout << "1. Ascending Sort(Min_heap) 2. Descending Sort(Max_heap)" << endl;

	cin.clear(); 
	cin.ignore(10000, '\n');
	cin >> input;
	Heap* le_heap = new Heap(temp,input);//constructor, with flag
	Heap* le_copy= new Heap(temp,input);   
	Heap* le_copy1= new Heap(temp,input);   
	Heap* le_copy2= new Heap(temp,input);   

	if(input==1){
		le_copy->ascendingHeapSort();//min heappppppp, min, not max. min
		le_heap->printMin();
		min = le_heap->extract_minimum();
		le_copy1->extract_minimum();// was casuing a out of bounds w.out decrementing the copy1 heap also 
		min_=true; 

	}
	else{
		le_copy->descendingHeapSort();//maxxxxxxxxxxxxxxxxxxx heap , heapsort destroys heap object thats why  i made acopy
		le_heap->printMax();
		max = le_heap->extract_maximum();
		le_copy1->extract_maximum();
		max_=true;//used a bool to display either max or min 
	}

	if(max_) cout <<"extracted max is: "<< max << endl;
	if (min_)cout <<"extracted min is: "<< min << endl;
	
	if(min_){//   1) ascending sort
	cout<<"\n\nInput value to insert: \n"; 
	cin>> insert; 
	le_heap->insert_value_minHeap(insert);
	le_copy1->insert_value_minHeap(insert);//make sure to decrement also 
	le_copy1->ascendingHeapSort();
	cout<<"\n\nchoose element to modify, number to add"<<endl;
	cin>> mod_index >> mod_val; 
	le_copy2->modifyValMin(mod_index,mod_val);
	le_copy2->printArray();
	//le_copy2->ascendingHeapSort();
//	le_heap->printArray();
	}
	
	if(max_){//descending sort
	cout<<"\n\nInput value to insert: \n"; 
	cin>> insert; 
	le_heap->insert_value_maxHeap(insert);
	le_copy1->insert_value_maxHeap(insert);
	le_copy1->descendingHeapSort();
	cout<<"\n\nchoose element to modify, number to add"<<endl;
	cin>> mod_index >> mod_val; 
	le_copy2->modifyValMax(mod_index,mod_val);
	le_copy2->printArray();
	}

	//le_heap->printArray();
	return 0;



}
// need to fix mod val functions. not sure im printing them okay. im able to insert a numnber at the index(make sure its the correct index)0 but maybe i shoulndt sort after? im not sure about that
