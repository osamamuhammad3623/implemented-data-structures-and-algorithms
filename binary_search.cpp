#include <iostream>
#include <array>

using namespace std;

//binary search algorithm for searching for a value in a sorted array
//if it's found, the function returns its index, if not, the function returns -1

int binary_search(int sorted_array[], int value, int left_index, int right_index) {

	//checking if the value is out of the array boundaries
	if (sorted_array[left_index] > value || sorted_array[right_index] < value) {
		return -1;
	}

	int mid_point = (left_index + right_index) / 2;

	if (sorted_array[mid_point] == value){
		return mid_point;
	}
	else {
		if (sorted_array[mid_point] > value) {
			return binary_search(sorted_array, value, left_index, mid_point);
		}
		else if (sorted_array[mid_point] < value) {
			return binary_search(sorted_array, value, mid_point, right_index);
		}
	}

	// after all, if it's not found:
	return -1;
}

// testing the function
int main() {

	int arr[] = {1, 4, 8, 9, 12, 15, 18, 22, 25};

	// trying all possible tests (that came to my mind)
	cout << binary_search(arr, 12, 0, 8) << endl;
	cout << binary_search(arr, 8, 0, 8) << endl;
	cout << binary_search(arr, 18, 0, 8) << endl;
	cout << binary_search(arr, 0, 0, 8) << endl;
	cout << binary_search(arr, 30, 0, 8) << endl;

}