#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void merge_(vector<int> vector1, vector <int> vector2, vector<int> result) {

	int pos1{}, pos2{};
	int size1 = vector1.size();
	int size2 = vector2.size();
	
	//merge 2 arrays in case they are same size.
	while (pos1 < size1 && pos2 < size2) {
		if (vector1[pos1] < vector2[pos2]) {
			result.push_back(vector1[pos1]);
			pos1++;
		}
		else if (vector1[pos1] > vector2[pos2]) {
			result.push_back(vector2[pos2]);
			pos2++;
		}
		else {
			result.push_back(vector1[pos1]);
			result.push_back(vector2[pos2]);
			pos1++, pos2++;
		}
	}
	
	//the following if statements in case all elements in one array are merged and 
	//there are some elements in the second array that aren't merges yet, so they're directly pushed
	//into the merged vector
	if (pos1 == size1) {
		for (pos2; pos2 < size2; pos2++) {
			result.push_back(vector2[pos2]);
		}
	}
	else if (pos2 == size2) {
		for (pos1; pos1 < size1; pos1++) {
			result.push_back(vector1[pos1]);
		}
	}
	for (int i = 0; i < result.size(); i++) { cout << result[i] << " "; }
}

int main() {

	vector<int> vector1 = { 1,2,5,8,9,15,21,22,23 };
	vector<int> vector2 = { 0,3,7,12,16,17,19 };
	vector<int> vector3;
	merge_(vector1, vector2,vector3);
}
