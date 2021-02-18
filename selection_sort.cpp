#include <iostream>
using namespace std;

void selection_sort(int arr[], int length) {

	for (int i = 0; i < length; i++) {

		int current_minimum = i;
		for (int j = i; j < length; j++) {

			if (arr[j] < arr[current_minimum]) {
				current_minimum = j;
			}
		}
		swap(arr[current_minimum], arr[i]);
	}
}

int main(){

	int arr[] = { 2,5,3,9,1 };
	for (int i = 0; i < 5; i++) {
		cout << arr[i] << " " ;
	}
	selection_sort(arr, 5);

	cout << endl;

	for (int i = 0; i < 5; i++) {
		cout << arr[i] << " ";
	}
}
