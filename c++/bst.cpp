#include <iostream>
#include "bst.h"
#include "assert.h"

using namespace std;

int main()
{
    BST tree;

    areEqual(0, tree.size());

    tree.insert(5);
    areEqual(5, tree.root->value);
    areEqual(1, tree.size());

    tree.insert(3);
    areEqual(3, tree.root->left->value);
    areEqual(2, tree.size());

    tree.insert(4);
    areEqual(4, tree.root->left->right->value);
    areEqual(3, tree.size());

    tree.insert(7);
    areEqual(7, tree.root->right->value);
    areEqual(4, tree.size());

    tree.insert(6);
    areEqual(6, tree.root->right->left->value);
    areEqual(5, tree.size());

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

unsigned BST::countNodeDescendents(Node* target, unsigned currentCount)
{
    if (!target)
    {
        return currentCount;
    }
    else 
    {
        currentCount++; // Increment for the target existing
        currentCount += countNodeDescendents(target->left, 0);
        currentCount += countNodeDescendents(target->right, 0);
        return currentCount;
    }
}

unsigned BST::size()
{
    return countNodeDescendents(root, 0);
}