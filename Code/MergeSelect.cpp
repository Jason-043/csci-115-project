#include <iostream>
#include <ctime>
#include<vector>

using namespace std;

void selectionSort(int a[], int n);

vector<int> mergeFunction(vector<int> a);
vector<int> mergeTogether(vector<int> a, vector<int> b);
//
//int main() {
//	clock_t start, end;
//	int ar1[5] = { 2, 8, 1, 6, 3 };
//	int ar2[5] = { 7, 6, 4,2 ,1 };
//	int ar3[5] = { 1, 2, 5,4 ,3 };
//	start = clock();
//	selectionSort(ar1, 5);
//	end = clock();
//	double elapsedClocks = (double)(end - start);
//	double elapsedSeconds = elapsedClocks / CLOCKS_PER_SEC;
//	cout << "\nTime Taken (Selection): " << elapsedSeconds << endl;
//
//	vector<int> items3 = { 4, 1, 5, 7, 2, 9,12, 3 , 6, 8 };
//	vector<int> items = { 10,9,8, 7, 5, 4, 2, 1 };
//	vector<int> items2 = { 1, 3, 4, 5, 10, 8, 7, 11, 22, 6 };
//
//	vector<int> arg2;
//
//	for (int i = 0; i < 30; i++) {
//		arg2.push_back(rand() % 30);
//	}
//
//
//	cout << endl;
//	start = clock();
//	arg2 = mergeFunction(arg2);
//	end = clock();
//	for (int i = 0; i < arg2.size(); i++) {
//		cout << arg2[i] << " ";
//	}
//	double elapsedClocks2 = (double)(end - start);
//	double elapsedSeconds2 = elapsedClocks2 / CLOCKS_PER_SEC;
//	cout << "\nTime Taken (Recursive): " << elapsedSeconds2 << endl;
//
//
//	return 0;
//}

void selectionSort(int a[], int n)
{

	int ar2[5] = { 0, 0,0 ,0, 0 };

	int min = a[0];
	int index = 0;

	int j = 0;
	int i = 0;


	while (j < 5) {

		for (int i = 0; i < 5; i++) {
			if (a[i] != 0) {
				min = a[i];
				index = i;
				break;
			}


		}

		for (int i = 0; i < 5; i++) {

			if (min > a[i] && a[i] != 0) {
				min = a[i];
				index = i;

			}
			if (i == 4) {

				ar2[j] = min;
				a[index] = 0;



			}
		}

		j++;

	}

	cout << "Selection sorted list: ";
	for (int i = 0; i < 5; i++) {
		cout << ar2[i] << " ";


	};

}

vector<int> mergeFunction(vector<int> a)
{
	if (a.size() <= 1) {
		return a;
	}
	vector<int> right, left, result;

	int middle = ((int)a.size() + 1) / 2;

	for (int i = 0; i < middle; i++) {
		left.push_back(a[i]);
	}
	for (int i = middle; i < (int)a.size(); i++) {
		right.push_back(a[i]);
	}

	left = mergeFunction(left);
	right = mergeFunction(right);
	result = mergeTogether(left, right);

	return result;
}

vector<int> mergeTogether(vector<int> left, vector<int> right)
{
	vector<int> result;
	while ((int)left.size() > 0 || (int)right.size() > 0) {
		if ((int)left.size() > 0 && (int)right.size() > 0) {
			if ((int)left.front() <= (int)right.front()) {
				result.push_back((int)left.front());
				left.erase(left.begin());
			}
			else {
				result.push_back((int)right.front());
				right.erase(right.begin());
			}
		}
		else if ((int)left.size() > 0) {
			for (int i = 0; i < (int)left.size(); i++)
				result.push_back(left[i]);
			break;
		}
		else if ((int)right.size() > 0) {
			for (int i = 0; i < (int)right.size(); i++)
				result.push_back(right[i]);
			break;
		}
	}
	return result;
}
