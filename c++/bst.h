// Header file for a binary search tree

#ifndef BST_DEF
#define BST_DEF

struct Node
{
    unsigned value;
    Node *left;
    node *right;
};

Class BST
{
    void balance();
    unsigned items;

public:
    BST()
    {
        items = 0;
    }

    ~BST()
    {
        // TODO: postOrder traversal, deleting each node along the way
    }

    // TODO: assignment operator

    // TODO: copy constructor

    Node *root;
    void insert(unsigned);
    void insert(&Node);
    bool remove(unsigned);
    bool contains(unsigned);
    unsigned size();
    void preTraversal();
    void orderTraveral();
    void postTraveral();
};

#endif