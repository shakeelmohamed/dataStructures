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
    areEqual(1, s.pop());
    areEqual(3, s.pop());

    s.push(4);
    s.push(8);

    areEqual(8, s.pop());
    areEqual(4, s.pop());
    areEqual(4, s.pop());
    areEqual(9, s.pop());
    areEqual(8, s.pop());
    areEqual(2, s.pop());
    areEqual(5, s.pop());
    areEqual(7, s.pop());
    areEqual(2, s.pop());
    areEqual(1, s.pop());

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