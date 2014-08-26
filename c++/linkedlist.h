// Header file for a linked list

#ifndef LINKEDLIST_DEF
#define LINKEDLIST_DEF

#include <string>

using namespace std;

struct Node
{
    unsigned value;
    Node* next;
};

class LinkedList
{
private:
    Node* head;

public:
    LinkedList()
    {
        head = 0;
    }

    LinkedList(const LinkedList &old) // TODO: test
    {
        // TODO: iterate the current list, deleting each node
        // TODO: copy over node, by node
    }

    ~LinkedList()
    {
        // TODO: iterate the current list, deleting each node
        Node* temp = 0;
        while (temp)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
    }

    void operator=(const LinkedList &old)
    {
        if (this != &old)
        {
            // TODO: implement
        }
    }

    bool isEmpty();
    unsigned size();
    void size(int);
    void insert(int);
    void remove(int);
    bool contains(int);
    string join(string);
};

#endif