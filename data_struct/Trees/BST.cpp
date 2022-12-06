// a minimal implementation of a binary search tree
#include<iostream>
using namespace std;

struct Node{
	int data;
	Node *left, *right;
	Node(int data): data(data), left(NULL), right(NULL){}
};

Node* insertBST(Node* root, int data){
	if(root == NULL)
		return new Node(data);
	if(data < root->data)
		root->left = insertBST(root->left, data);
	else if(data > root->data)
		root->right = insertBST(root->right, data);
	return root;
}

void traverse_in_order(Node* root){
	if(root == NULL)
			return;
	traverse_in_order(root->left);
	cout << root->data << " ";
	traverse_in_order(root->right);
}

int main(){
	Node* root = NULL;
	root = 	insertBST(root, 12); //This is our root node
	insertBST(root, 34);
	insertBST(root, 45);
	insertBST(root, 4);
	insertBST(root, 0);
	traverse_in_order(root);
}
