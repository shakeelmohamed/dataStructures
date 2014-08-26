// Implementation file for a binary search tree

#include <iostream>
#include "bst.h"
#include "assert.h"

using namespace std;

int main()
{
    BST tree;

    areEqualInts(0, tree.size());

    tree.insert(5);
    areEqualInts(5, tree.root->value);
    areEqualInts(1, tree.size());

    tree.insert(3);
    areEqualInts(3, tree.root->left->value);
    areEqualInts(2, tree.size());

    tree.insert(4);
    areEqualInts(4, tree.root->left->right->value);
    areEqualInts(3, tree.size());

    tree.insert(7);
    areEqualInts(7, tree.root->right->value);
    areEqualInts(4, tree.size());

    tree.insert(6);
    areEqualInts(6, tree.root->right->left->value);
    areEqualInts(5, tree.size());

    tree.orderTraversal();
    cout << endl;
    tree.preTraversal();
    cout << endl;
    tree.postTraversal();

    return 0;
}

bool BST::contains(unsigned value)
{
    Node* temp = root;
    while(true)
    {
        if (!temp)
        {
            return false;
        }
        else if (temp->value == value)
        {
            return true;
        }
        else if (temp->value < value)
        {
            temp = temp->left;
        }
        else if (temp->value > value)
        {
            temp = temp->right;
        }
    }
}

void BST::insert(unsigned value)
{
    if (!root)
    {
        root = new Node;
        root->value = value;
    }
    else if (contains(value))
    {
        return; // Don't store duplicate values
    }
    else
    {
        Node* temp = root;
        while(true)
        {
            if (value < temp->value)
            {
                if (temp->left)
                {
                    temp = temp->left;
                    continue;
                }
                else
                {
                    temp->left = new Node;
                    temp->left->value = value;
                    return;
                }
            }
            else
            {
                if (temp->right)
                {
                    temp = temp->right;
                    continue;
                }
                else
                {
                    temp->right = new Node;
                    temp->right->value = value;
                    return;
                }
            }
        }
    }
}


unsigned BST::_countNodeDescendents(Node* target, unsigned currentCount)
{
    if (!target)
    {
        return currentCount;
    }
    else 
    {
        currentCount++; // Increment for the target existing
        currentCount += _countNodeDescendents(target->left, 0);
        currentCount += _countNodeDescendents(target->right, 0);
        return currentCount;
    }
}

unsigned BST::size()
{
    return _countNodeDescendents(root, 0);
}

void BST::preTraversal()
{
    // TODO: accept a string parameter
    _pre(root); 
}

void BST::_pre(Node* target)
{
    if (target)
    {
        cout << target->value << endl;
    }
    if (target->left)
    {
        _pre(target->left);
    }
    if (target->right)
    {
        _pre(target->right);
    }
}

void BST::orderTraversal()
{
    // TODO: accept a string parameter
    _order(root); 
}

void BST::_order(Node* target)
{
    if (target->left)
    {
        _order(target->left);
    }
    if (target)
    {
        cout << target->value << endl;
    }
    if (target->right)
    {
        _order(target->right);
    }
}
void BST::postTraversal()
{
    // TODO: accept a string parameter
    _post(root); 
}

void BST::_post(Node* target)
{
    if (target->left)
    {
        _post(target->left);
    }
    if (target->right)
    {
        _post(target->right);
    }
    if (target)
    {
        cout << target->value << endl;
    }
}