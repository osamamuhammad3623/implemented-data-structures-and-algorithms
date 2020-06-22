#include <iostream>

using namespace std;


//BASIC implementation for stack DS with insertion, poping,
// showing elements, checking if the stack is empty or have a specific value


struct Node {
	short value{};
	Node* next = nullptr;
};

struct Stack {
	Node* head = nullptr;
	short node_count{};

	bool is_empty() {

		return head == nullptr;
	}

	void insert(short val) {

		Node* new_node = new Node;
		new_node->value = val;
		new_node->next = head;
		head = new_node;
		node_count++;
	}

	void view_elements() {

		Node* new_node = head;
		while (new_node != nullptr) {
			cout << new_node->value << endl;
			new_node = new_node->next;
		}
	}

	void pop() {
		Node* pointer = head;
		head = (head->next);
		pointer->next = nullptr;
		node_count--;
	}

	bool is_contain(short check) {

		if (is_empty() == 1) {
			cout << "Stack is empty anyway" << endl;
		}
		else {
			Node* new_node = head;
			while (new_node->value != check) {

				if (new_node->next == nullptr) {
					return 0;
				}
				else {
					new_node = new_node->next;
				}
			}
			return 1;
		}
	}
};

//testing all functions in Main:

int main() {

	Stack s1;
	cout << s1.is_empty() << endl;
	s1.insert(10);
	s1.insert(15);
	s1.insert(20);
	s1.insert(200);
	cout << s1.is_empty() << endl;
	s1.view_elements();
	cout << s1.node_count << endl;
	cout << s1.is_contain(200) << endl;
	cout << s1.is_contain(10) << endl;
	s1.pop();
	s1.view_elements();
	cout << s1.node_count << endl;
	cout << s1.is_contain(200) << endl;
	cout << s1.is_contain(10) << endl;

}