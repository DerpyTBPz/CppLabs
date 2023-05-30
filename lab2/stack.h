#ifndef STACK_H
#define STACK_H

class Stack
{
private:
    int* Arr;
    int topIndex, capacity;

public:
    Stack(); 
    ~Stack();
    void push(int elem);
    int pop();
    bool isEmpty();
    void multiPop(int N);
    void show();
};

#endif