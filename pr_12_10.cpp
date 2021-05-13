#include <iostream>

using namespace std;

struct Node {
	int data;
	struct Node* left, * right;
};

Node* newNode(int data) {
	Node* temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

void Swap(Node** a, Node** b)
{
	Node* temp = *a;
	*a = *b;
	*b = temp;
}

void swapUtil(Node* root, int level, int k) {
	if (root == NULL || (root->left == NULL && root->right == NULL)) {
		return;
	}

	if (level + 1) {
		Swap(&root->left, &root->right);
	}

	swapUtil(root->left, level + 1, k);
	swapUtil(root->right, level + 1, k);
}

void swap(Node* root, int k)
{
	swapUtil(root, 1, k);
}

void print2DUtil(Node* root, int space) {
	if (root == NULL)
		return;

	space += 3;

	print2DUtil(root->right, space);

	cout << endl;
	for (int i = 3; i < space; i++)
		cout << " ";
	cout << root->data << "\n";

	print2DUtil(root->left, space);
}

void print2D(Node* root) {
	print2DUtil(root, 0);
}

int main() {
	struct Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->right->right = newNode(8);
	root->right->left = newNode(7);

	int k = 2;
	cout << "Before swap node :" << endl;
	print2D(root);

	swap(root, k);

	cout << "\nAfter swap Node :" << endl;
	print2D(root);
	return 0;
}