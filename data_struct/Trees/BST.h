struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int data) : data(data), left(nullptr), right(nullptr){};
};
class BST
{
public:
    virtual Node *insertKey(Node *, int);
    Node *search(Node *, int);
    virtual Node *deleteKey(Node *, int);
    Node *inorderSucc(Node *);
    void in_order_trav(Node *);
};