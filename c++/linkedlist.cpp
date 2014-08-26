// Implementation file for a linked list class, includes some tests in the main method

#include <iostream>
#include <sstream>
#include <string>
#include "./linkedlist.h"
#include "./assert.h"

using namespace std;

int main()
{
    LinkedList l;
    unsigned inserted = 0;

    l.insert(4);
    areEqualInts(++inserted, l.size());
    isFalse(l.isEmpty());

    l.insert(6);
    areEqualInts(++inserted, l.size());

    l.insert(3);
    areEqualInts(++inserted, l.size());

    l.insert(5);
    areEqualInts(++inserted, l.size());

    areEqualStrings(string("4, 6, 3, 5"), l.join(", "));

    l.remove(1);
    areEqualInts(inserted, l.size());

    l.remove(4);
    areEqualInts(--inserted, l.size());

    l.remove(6);
    areEqualInts(--inserted, l.size());

    areEqualStrings(string("3, 5"), l.join(", "));

    return 0;
}

bool LinkedList::isEmpty()
{
    return !this->head;
}

unsigned LinkedList::size()
{
    unsigned ret = 0;
    Node* temp = head;
    while (temp)
    {
        ret++;
        temp = temp->next;
    }
    return ret;
}

void LinkedList::insert(int value)
{
    Node* v = new Node;
    v->value = value;

    if (!this->head)
    {
        this->head = v;
        return;
    }

    Node* temp = this->head;
    while(temp)
    {
        if (temp->next)
        {
            temp = temp->next;
        }
        else
        {
            break;
        }
    }
    temp->next = v;
    return;
}

void LinkedList::remove(int value)
{
    Node* temp = this->head;
    Node* backup = 0;
    while (temp)
    {
        if (temp->value == value)
        {
            if (backup)
            {
                backup->next = temp->next;    
            }
            else
            {
                this->head = temp->next;
            }
            delete temp;
            return;
        }
        backup = temp;
        temp = temp->next;
    }
}

string LinkedList::join(string seperator)
{
    stringstream ss;
    Node* temp = this->head;
    while (temp)
    {   
        ss << temp->value;
        if (temp->next)
        {
            ss << seperator;
        }
        temp = temp->next;
    }
    return ss.str();
}