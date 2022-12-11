#include <iostream>
#include "AVL.h"
using namespace std;

// height O(n)
int AVL::height(Node *root)
{
    if (root == NULL)
        return -1;
    int lheight = height(root->left);
    int rheight = height(root->right);
    if (lheight > rheight)
        return (lheight + 1);
    else
        return (rheight + 1);
}

// determines balance factor
int AVL::balFact(Node *root)
{
    if (root == NULL)
        exit(1);
    cout << "Left Height = " << height(root->left) << endl
         << "Right Height = " << height(root->right) << endl
         << "BF = " << height(root->left) - height(root->right) << endl;
    return height(root->left) - height(root->right);
}

// rotations
Node *AVL::leftRotate(Node *root)
{
    Node *temp = root;

    root = root->right;
    root->left = temp;

    return root;
}

Node *AVL::rightRotate(Node *root)
{
    Node *temp = root;

    root = root->left;
    root->right = temp;

    return root;
}
// insertion
Node *AVL::insertKey(Node *root, int key)
{
    if (root == NULL)
    {
        Node *newNode = new Node(key);
        root = newNode;
    }
    else if (key < root->data)
        root->left = insertKey(root->left, key);
    else if (key > root->data)
        root->right = insertKey(root->right, key);
    return root;
}

int main()
{
    AVL avl;
    Node *root = avl.insertKey(NULL, 23);
    // avl.insertKey(root, 34);
    // avl.insertKey(root, 44);
    avl.insertKey(root, 4);
    avl.insertKey(root, 3);
    // avl.insertKey(root, 2);
    // avl.insertKey(root, 64);
    // avl.insertKey(root, 74);
    // avl.insertKey(root, 84);
    cout << avl.height(root->left) << endl;
    cout << avl.balFact(root) << endl;
}