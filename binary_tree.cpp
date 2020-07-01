#include <iostream>

using namespace std;


//Basic binary tree implementation with a varity of methods:

struct Node {
	int value{};
	Node* right = nullptr;
	Node* left = nullptr;
};

struct Binary_Tree {

	int node_counter{ 1 };

	void insertNode(Node* root, int val) {

		if (root == nullptr) {
			root = new Node;
			root->value = val;
			node_counter++;
		}
		else {
			if (val < root->value) {
				if (root->left == nullptr) {
					root->left = new Node;
					(root->left)->value = val;
					node_counter++;
				}
				else {
					insertNode(root->left, val);
				}
			}
			if (val > root->value) {
				if (root->right == nullptr) {
					root->right = new Node;
					(root->right)->value = val;
					node_counter++;
				}
				else {
					insertNode(root->right, val);
				}
			}
		}
	}

	int maxNode(Node* root) {
		if (root->right == nullptr) {
			return root->value;
		}
		else {
			maxNode(root->right);
		}
	}

	int minNode(Node* root) {
		if (root->left == nullptr) {
			return root->value;
		}
		else {
			minNode(root->left);
		}
	}

	bool searchNode(Node* root, int check_val) {
		if (check_val == root->value) { return 1; }
		else {
			if (check_val < root->value) {
				if (root->left != nullptr) {
					searchNode(root->left, check_val);
				}
				else {
					return 0;
				}
			}
			else if (check_val > root->value) {
				if (root->right != nullptr) {
					searchNode(root->right, check_val);
				}
				else {
					return 0;
				}
			}
		}
	}

	/*int countNode(Node* root) {
		if (root == nullptr) { return 0; }
		else {
			return 1 + countNode(root->left) + countNode(root->right);
		}
	}*/
	// this method can be used instead of node_counter member

	void depth_first_view(Node* root) {
		if (root == nullptr) {
			cout << "There is no tree anyway" << endl;
		}
		else {

			if (root->left != nullptr) {
				depth_first_view(root->left);
			}

			cout << root->value << endl;

			if (root->right != nullptr) {
				depth_first_view(root->right);
			}
		}
	}

	bool has_left_child(Node* root, int check_val) {

		if (check_val == root->value) { return root->left != nullptr; }
		else {

			if (check_val < root->value) {

				if (root->left != nullptr) {
					has_left_child(root->left, check_val);
				}
				else {
					return 0;
				}
			}
			else if (check_val > root->value) {
				if (root->right != nullptr) {
					has_left_child(root->right, check_val);
				}
				else {
					return 0;
				}
			}
		}
	}

	bool has_right_child(Node* root, int check_val) {

		if (check_val == root->value) { return root->right != nullptr; }
		else {

			if (check_val < root->value) {

				if (root->left != nullptr) {
					has_right_child(root->left, check_val);
				}
				else {
					return 0;
				}
			}
			else if (check_val > root->value) {
				if (root->right != nullptr) {
					has_right_child(root->right, check_val);
				}
				else {
					return 0;
				}
			}
		}
	}

	void path_from_root(Node* root, int check_val) {
		cout << root->value << " --> ";
		if (check_val == root->value) {
			cout << "(Found !)" << endl;
		}
		else {
			if (check_val < root->value) {
				if (root->left != nullptr) {

					path_from_root(root->left, check_val);
				}
				else {
					cout << "(Not found !)" << endl;
				}
			}
			else if (check_val > root->value) {
				if (root->right != nullptr) {
					path_from_root(root->right, check_val);
				}
				else {
					cout << "(Not found !)" << endl;
				}
			}
		}
	}
};

// testing the functions

int main() {
	Node root_test;
	root_test.value = 7;

	Binary_Tree b1;
	b1.insertNode(&root_test, 3);
	b1.insertNode(&root_test, 2);
	b1.insertNode(&root_test, 5);
	b1.insertNode(&root_test, 15);
	b1.insertNode(&root_test, 10);
	b1.insertNode(&root_test, 19);

	cout << b1.maxNode(&root_test) << endl;
	cout << b1.minNode(&root_test) << endl;
	cout << b1.searchNode(&root_test, 15) << endl;
	cout << b1.searchNode(&root_test, 31) << endl;
	cout << b1.node_counter << endl;
	b1.depth_first_view(&root_test);

	cout << b1.has_left_child(&root_test, 3) << endl;
	cout << b1.has_right_child(&root_test, 2) << endl;
	cout << b1.has_left_child(&root_test, 15) << endl;
	cout << b1.has_right_child(&root_test, 15) << endl;
	b1.path_from_root(&root_test, 15);
	b1.path_from_root(&root_test, 5);

}
