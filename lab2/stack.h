#ifndef STACK_H
#define STACK_H

class Stack
{
private:
    int* Arr;
    int topIndex, capacity;

public:
    Stack(int capacity);
    Stack(const Stack& oStack);
    Stack& operator = (const Stack& oStack);
    ~Stack();
    void push(int elem);
    int pop();
    bool isEmpty();
    void multiPop(int N);
    void show();
};

#endif