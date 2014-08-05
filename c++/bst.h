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
private:
    // void balance(); // TODO: implement
    unsigned _countNodeDescendents(Node*, unsigned);
    void _pre(Node*);
    void _order(Node*);
    void _post(Node*);    

public:
    BST()
    {
        root = 0; // Null out the root pointer
    }

    ~BST()
    {
        // TODO: postOrder traversal, deleting each node along the way
    }

    // TODO: assignment operator

    // TODO: copy constructor

    Node* root;
    void insert(unsigned);
    // bool remove(unsigned); // TODO: implement
    bool contains(unsigned);
    unsigned size();
    void preTraversal();
    void orderTraversal();
    void postTraversal();
};

#endif