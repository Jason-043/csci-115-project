#include <iostream>
#include <vector>
#include <cmath>
//#include "heap_sort.h"
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

class priority_q{
	public:
	int p_size=0 ;
	vector<int> vecchio;
	Heap* p_heap;
	priority_q(vector<int> input_vec);
	void insert(int new_val);
	int extract_max(); 
	void print_maxq(); 
	void print_q(); 
	void increase_key(int index, int val);
};

priority_q::priority_q(vector<int> input_vec){
	int input_size=input_vec.size(); 

	for(int i =0; i<input_size;i++){	
		vecchio.push_back(input_vec.at(i)); 
	}
	this->p_heap = new Heap(input_vec,0);
	this->p_size = input_size; 

//	this->p_heap->printArray();
}	
void priority_q::print_q(){
	cout<<"PRIORITY QUEUE ";
	this->p_heap->printArray(); 

}

void priority_q::print_maxq(){
	this->p_heap->printMax();

}
void priority_q::insert(int new_val){
	this->p_heap->insert_value_maxHeap(new_val);
}

int priority_q::extract_max(){
	this->p_size--;
	return p_heap->extract_maximum();

}

void::priority_q::increase_key(int ind, int val){
	p_heap->modifyValMax(ind, val); 
}

int main() {
	vector<int> temp;
	vector<int> pq_vec;
	cout << "Input: ";
	int input=0;
	int max=0;
	int min=0;
	bool max_ = false;     
	bool min_ = false;
   	int insert=0;
	int mod_index=0;
	int mod_val=0;
	int pq_input=0;
	int pq_insert=0;
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

	if(input==1){
		le_heap->ascendingHeapSort();//min heappppppp, min, not max. min
		le_heap->printMin();
		min = le_heap->extract_minimum();
		min_=true; 

	}
	else{
		le_heap->descendingHeapSort();//maxxxxxxxxxxxxxxxxxxx heap , heapsort destroys heap object thats why  i made acopy
		le_heap->printMax();
		max = le_heap->extract_maximum();
		max_=true;//used a bool to display either max or min 
	}

	if(max_) cout <<"extracted max is: "<< max << endl;
	if (min_)cout <<"extracted min is: "<< min << endl;
	
	le_heap->printArray(); 

	if(min_){//   1) ascending sort
	cout<<"\n\nInput value to insert: \n"; 
	cin>> insert; 
	le_heap->insert_value_minHeap(insert);
	le_heap->printArray();
	cout<<"\n\nchoose element to modify, number to add"<<endl;
	cin>> mod_index >> mod_val;
       	le_heap->modifyValMin(mod_index, mod_val); 	
	}
	
	if(max_){//descending sort
	cout<<"\n\nInput value to insert: \n"; 
	cin>> insert; 
	le_heap->insert_value_maxHeap(insert);
	le_heap->printArray();
	cout<<"\n\nchoose element to modify, number to add"<<endl;
	cin>> mod_index >> mod_val; 
       	le_heap->modifyValMax(mod_index, mod_val); 	
	}

	le_heap->printArray();

	cout<<"PRIORITY QUEUE TIME\n";
	cout<<"input values for the queue\n";
     	while (1) {
                cin >> pq_input;
                if (!cin)break;
                pq_vec.push_back(pq_input);
	}



	priority_q* pq = new priority_q(pq_vec);
	pq->print_q(); 
	pq->print_maxq();
	cout<<"Extracting Max "<< pq->extract_max()<<endl;
	cout<<"insert a value into the queue\n";

	cin.clear(); 
	cin.ignore(10000, '\n');
	cin>> pq_insert; 
	cout<<"insert val is; "<<pq_insert<<endl;
	pq->insert(pq_insert); 
	pq->print_q(); 

	cout<<"\n\nchoose a queue element to modify, number to add"<<endl;
	cin>> mod_index>> mod_val;

	pq->increase_key(mod_index, mod_val);
	pq->print_q(); 

	return 0;



}
