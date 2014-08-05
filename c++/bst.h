// Header file for a binary search tree

#ifndef BST_DEF
#define BST_DEF

struct Node
{
    unsigned value;
    Node* left;
    Node* right;
};

class BST
{
    // void balance();
    unsigned countNodeDescendents(Node*, unsigned);
public:
    BST()
    {
        root = 0;
    }

    ~BST()
    {
        // TODO: postOrder traversal, deleting each node along the way
    }

    // TODO: assignment operator

    // TODO: copy constructor

    Node* root;
    void insert(unsigned);
    // void insert(&Node);
    // bool remove(unsigned);
    bool contains(unsigned);
    unsigned size();
    // void preTraversal();
    // void orderTraveral();
    // void postTraveral();
};

#endif