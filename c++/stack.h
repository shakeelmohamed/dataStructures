// Header file for Stack class definition

#ifndef STACK_DEF
#define STACK_DEF

class Stack
{
    int size;
    unsigned *data;
    int index;
    void resize();
public:
    Stack();
    ~Stack();
    bool isFull();
    bool isEmpty();
    int pop();
    void push(unsigned value);
};

#endif