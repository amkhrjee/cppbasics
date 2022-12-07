#include "BST.h"
int max(int, int);
class AVL : public BST
{
    //  Balance Factor = |H(left_subtree) - H(right_subtree)| = {-1,0,1}
public:
    int height(Node *);
    int balanceFactor(Node *);
    Node *leftRotate(Node *);
    Node *rightRotate(Node *);
};