#include <iostream>
#include "BST.h"
using namespace std;

// insertion
Node *BST::insertKey(Node *root, int data)
{
	if (root == NULL)
	{
		Node *newNode = new Node(data);
		root = newNode;
	}
	else if (data < root->data)
		root->left = insertKey(root->left, data);
	else if (data > root->data)
		root->right = insertKey(root->right, data);
	else if (data == root->data)
		cout << data << " already exists!" << endl;
	return root;
}

// search
Node *BST::search(Node *root, int key)
{
	if (root == NULL)
	{
		cout << "\nNot found!" << endl;
		exit(1);
	}
	else if (key < root->data)
		search(root->left, key);
	else if (key > root->data)
		search(root->right, key);
	return root;
}

// delete
Node *BST::deleteKey(Node *root, int key)
{
	if (key < root->data)
		root->left = deleteKey(root->left, key);
	else if (key > root->data)
		root->right = deleteKey(root->right, key);
	else if (key == root->data)
	{
		// case 1: has a single child
		if (root->left == NULL)
		{
			Node *temp = root->right;
			delete (root);
			return temp;
		}
		else if (root->right == NULL)
		{
			Node *temp = root->left;
			delete (root);
			return temp;
		}
		// case 2: has two children
		else if (root->left && root->right)
		{
			Node *temp = inorderSucc(root);
			root->data = temp->data;
			root->right = deleteKey(root->right, temp->data);
		}
		// case 3: leaf node
		return root;
	}
	return NULL;
}

// finds inorder successor ->
// Note: this is potentially a very bad implementation
// as it heavily depends on the fact that we will never
// encounter leaf nodes
Node *BST::inorderSucc(Node *root)
{
	if (root == NULL)
		exit(1);
	if (root->right)
	{
		if (root->right->left)
		{
			Node *curr = root->right->left;
			while (curr->left != NULL)
				curr = curr->left;
			return curr;
		}
		return root->right;
	}
	return root;
}
// traversal
void BST::in_order_trav(Node *root)
{
	if (root == NULL)
		return;
	in_order_trav(root->left);
	cout << root->data << " ";
	in_order_trav(root->right);
}

// int main()
// {
// 	BST bst;
// 	Node *root = bst.insertKey(NULL, 23);
// 	bst.insertKey(root, 45);
// 	bst.insertKey(root, 67);
// 	bst.insertKey(root, 423);
// 	bst.insertKey(root, 4);
// 	bst.insertKey(root, 45);
// 	bst.in_order_trav(root);
// 	cout << "\nFound 4 at Node: " << bst.search(root, 4) << endl;
// 	bst.deleteKey(root, 4);
// 	bst.deleteKey(root, 45);
// 	bst.deleteKey(root, 67);
// 	bst.in_order_trav(root);
// }