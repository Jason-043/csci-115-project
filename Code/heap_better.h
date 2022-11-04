#ifndef HEAPBETTER
#define HEAPBETTER

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
class Heap {
	public:
		int n=0; // number of elements in the heap
		vector<int> Arr; // Vector to store the elements
		Heap(); 
		Heap(vector<int> a); // Constructor
		Heap(vector<int> a, int flag); // Constructor with flag for max or min initialization
		void printArray(); // Prints the array
				   // Max heap
		void modifyValMax(int i, int val); //Modify value
		void insert_value_maxHeap(int val); //Adds value at the end of array and calls max_heapify
		void max_heapify(int i); //Maintains the max heap property
		int extract_maximum(); //Return the maximum element in heap and swap last element with first element
		void ascendingHeapSort(); //Prints the array in ascending order
        void ascendingHeapSort1();
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
Heap::Heap(){
	this->n=0; 
}
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
void Heap::buildMinHeap() {//Build min heap
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
	this->n = vec_size; 
	this->buildMinHeap(); 
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

	this->n = vec_size;
	this->buildMaxHeap(); 
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
	this->buildMinHeap();//when swimming use buildheap cause buildheap gets the parent node. need parent node to compare to children
}
void Heap:: insert_value_maxHeap(int val){
	this->n++;
	this->Arr.at(this->n-1)=val;;
	this->buildMaxHeap();
}
void Heap:: modifyValMax(int i, int val){
	
 	if(i<0 || i>=this->n){
	       	cout<< "------INVALID INPUT- OUT OF RANGE---------\n"; 
		return;}
	if(i==0){
	    this->Arr.at(i)= val;
		max_heapify(i);
	}
	else if( i >0 ){
		this->Arr.at(i)= val;
		this->buildMaxHeap(); 
	
	}
}

void Heap:: modifyValMin(int i, int val){
	if(i<0 || i>=this->n){
	       	cout<< "------INVALID INPUT- OUT OF RANGE---------\n"; 
        	        return;}
        if(i==0){
            this->Arr.at(i)= val;
                min_heapify(i);
        }
        else if( i >0 ){
                this->Arr.at(i)= val;
                this->buildMinHeap();

        }
}
#endif