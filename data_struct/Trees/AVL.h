#include "BST.h"
class AVL : public BST
{
public:
    int height(Node *);
    int balFact(Node *);
    Node *balance(Node *);
    Node *leftRotate(Node *);
    Node *rightRotate(Node *);
    virtual Node *insertKey(Node *, int);
};
