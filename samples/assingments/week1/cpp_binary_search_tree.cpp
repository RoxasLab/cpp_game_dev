#include <iostream>


struct Node {
	int data;
	Node* left;
	Node* right;

	Node(int value) {
		data = value;
		left = nullptr;
		right = nullptr;
	}
};

class Binary{
private:
	Node * root;

	Node* insert(Node* node, int value) {
		if (node == nullptr) {
			return new Node(value);
		}

		if (value < node->data) {
			node->left = insert(node->left, value);
		}

		else if (value > node->data) {
			node->right = insert(node->right, value);
		}

		return node;
	}

	void inorder(Node* node) {
		if (node == nullptr) {
			return;
		}

		inorder(node->left);
		std::cout << node->data << " ";
		inorder(node->right);
	}

public:
	Binary() {
		root = nullptr;
	}

	void insert(int value) {
		root = insert(root, value);
	}

	void print() {
		inorder(root);
		std::cout << std::endl;
	}
};

int main() {
	Binary tree;

	tree.insert(8);
	tree.insert(3);
	tree.insert(10);
	tree.insert(1);
	tree.insert(6);

	tree.print();

	return 0;
}