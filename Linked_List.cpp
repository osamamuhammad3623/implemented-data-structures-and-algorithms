#include <iostream>

using namespace std;

//BASIC Linked List implementation with a variety of functions:
//insertion, back insertion, deleting, showing elements
//and checking if the list is empty or have a specific value

struct Node {
	short value{};
	Node* next = nullptr;

	void set_next(Node* next_node) {
		next = next_node;
	}
};

struct Linked {
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

	void back_insert(short val) {
		
		if (is_empty() == 1) {
			insert(val);
		}
		else {
			Node* new_node = head;
			while (new_node->next != nullptr) {
				new_node = new_node->next;
			}
			new_node->next = new Node;
			(new_node->next)->value = val;
			node_count++;
		}
	}

	void view_elements() {

		Node* new_node = head;
		while (new_node != nullptr) {
			cout << new_node->value << endl;
			new_node = new_node->next;
		}
	}

	void delete_by_index(short index) {

		if (is_empty() == 1) {
			cout << "process can't be performed" << endl;
		}
		else {
			Node* pointer = head;
			short counter = 1;
			while (counter != (index - 1)) {
				pointer = pointer->next;
				counter++;
			}
			pointer->set_next( (pointer->next)->next );
			node_count--;
		}
	}

	bool is_contain(short check_val) {
		
		if (is_empty() == 1) {
			cout << "Linked List is empty anyway" << endl;
		}
		else {
			Node* pointer = head;
			while ( pointer->value != check_val ) {

				if (pointer->next == nullptr) {
					return 0;
				}
				else {
					pointer = pointer->next;
				}
			}
			return 1;
			
		}
	}
};


//testing all functions in Main:

int main() {

	Linked l1;
	cout << l1.is_empty() << endl;
	l1.insert(10);
	l1.insert(15);
	l1.back_insert(20);
	l1.back_insert(200);
	l1.back_insert(23);
	l1.back_insert(98);
	cout << l1.is_contain(200) << endl;
	cout << l1.is_empty() << endl;
	cout << l1.node_count << endl;
	l1.view_elements();
	l1.delete_by_index(4);
	l1.view_elements();
	cout << l1.node_count << endl;
	cout << l1.is_contain(200) << endl;
}