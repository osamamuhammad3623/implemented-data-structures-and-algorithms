#include <iostream>
using namespace std;

// the function returns the index of the first matching character (in successful match)
// or -1 (in unsuccessful match)
short string_match(string phrase, string sub) {

	for (short itr{}; itr <= phrase.size() - sub.size(); itr++) {

		short matching{};
		for (short sub_itr{}; sub_itr < sub.size(); sub_itr++) {
			if (phrase[itr + sub_itr] == sub[sub_itr]) {
				matching++;
			}
			else {
				break;
			}
		}
		if (matching == sub.size()) {
			return itr;
		}
	}
	return -1;
}

int main() {

	// some calls to test the function
	cout << string_match("This is C++", "is C") << endl;
	cout << string_match("my name is osama", "Osama") << endl;
	cout << string_match("my name is osama", "osaa") << endl;
	cout << string_match("my name is osama", "osama") << endl;
	cout << string_match("my name is osama", "is os") << endl;
}