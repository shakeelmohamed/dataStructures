// Implementation file for Stack class, includes some tests in the main method

#include "stack.h"
#include "assert.h"
#include <iostream>
using namespace std;

int main()
{   
    Stack s;
    
    isTrue(s.isEmpty());
    isTrue(!s.isFull());
    s.push(1);
    s.push(2);
    s.push(7);
    s.push(5);
    s.push(2);
    s.push(8);
    s.push(9);
    s.push(4);
    s.push(3);
    s.push(1);

    s.push(5);
    s.push(2);
    
    isTrue(s.isFull());
    isTrue(!s.isEmpty());
    areEqualInts(1, s.pop());
    areEqualInts(3, s.pop());

    s.push(4);
    s.push(8);

    areEqualInts(8, s.pop());
    areEqualInts(4, s.pop());
    areEqualInts(4, s.pop());
    areEqualInts(9, s.pop());
    areEqualInts(8, s.pop());
    areEqualInts(2, s.pop());
    areEqualInts(5, s.pop());
    areEqualInts(7, s.pop());
    areEqualInts(2, s.pop());
    areEqualInts(1, s.pop());

    isTrue(s.isEmpty());
    isTrue(!s.isFull());

    return 0;
}

bool Stack::isFull()
{
    return this->index == this->size;
}

bool Stack::isEmpty()
{
    return 0 == this->index;
}

int Stack::pop()
{
    if (this->isEmpty()) {
        cout << "Couldn't pop because the stack is empty." << endl;
        return -1;
    }

    this->index--;
    int pop = this->data[this->index];
    return pop;
}

void Stack::push(unsigned value)
{
    if (this->isFull()) {
        cout << "Couldn't push because the stack is full." << endl;
        return;
    }

    data[index] = value;
    index++;
    return;
}