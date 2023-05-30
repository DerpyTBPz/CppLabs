#include <iostream>
#include "stack.h"

Stack::Stack(int capacity)
{
    this->Arr = new int[capacity];
    this->topIndex = -1;
    this->capacity = capacity;
}

Stack::Stack(const Stack& oStack)
{
    this->capacity = oStack.capacity;
    this->topIndex = oStack.topIndex;
    this->Arr = new int[capacity];
    for (int i = 0; i <= topIndex; i++)
    {
        this->Arr[i] = oStack.Arr[i];
    }
}

Stack& Stack::operator = (const Stack& oStack)
{
    if (this == &oStack)
    {
        return *this;
    }
    delete[] Arr;
    this->capacity = oStack.capacity;
    this->topIndex = oStack.topIndex;
    this->Arr = new int[capacity];
    for (int i = 0; i <= topIndex; i++)
    {
        this->Arr[i] = oStack.Arr[i];
    }
    return *this;
}

Stack::~Stack()
{
    delete[] Arr;
}

void Stack::push(int elem)
{
    if (topIndex == capacity - 1)
    {
        int *tmp = new int[capacity * 2];
        for (int i = 0; i <= topIndex; i++)
        {
            tmp[i] = Arr[i];
        }
        delete[] Arr;
        capacity *= 2;
    }
    topIndex++;
    Arr[topIndex] = elem;
}

int Stack::pop()
{
    if (isEmpty())
    {
        std::cout << "Stack is empty" << std::endl;
        return -1;
    }
    int elem = Arr[topIndex];
    topIndex--;
    return elem;
}

bool Stack::isEmpty()
{
    return (topIndex == -1);
}

void Stack::multiPop(int N)
{
    while (N > 0 && !isEmpty())
    {
        pop();
        N--;
    }
}

void Stack::show()
{
    for (int i = topIndex; i >= 0; i--)
    {
        std::cout << Arr[i] << " ";
    }
    std::cout << std::endl;
}

