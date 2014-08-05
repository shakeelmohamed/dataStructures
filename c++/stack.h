// Header file for Stack class definition

#ifndef STACK_DEF
#define STACK_DEF

class Stack
{
    int size;
    unsigned* data;
    int index;
    void resize();
public:
    Stack(const Stack &old) // TODO: test
    {
        this->index = 0;
        this->size = old.size;
        delete this->data;
        this->data = new unsigned[this->size];
        
        for (int i = 0; i < old.size; ++i)
        {
            this->data[i] = old.data[i];
        }
    }

    ~Stack()
    {
        delete this->data;
    }

    Stack(const unsigned s = 10)
    {
        this->index = 0;
        this->size = s;
        this->data = new unsigned[this->size];
    }

    void operator=(const Stack &old) // TODO: test
    {
        if (this != &old)
        {
            this->index = 0;
            this->size = old.size;
            delete this->data;
            this->data = new unsigned[this->size];
            
            for (int i = 0; i < old.size; ++i)
            {
                this->data[i] = old.data[i];
            }       
        }
    }


    bool isFull();
    bool isEmpty();
    int pop();
    void push(unsigned);
};

#endif