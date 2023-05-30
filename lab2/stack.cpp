#include <iostream>
#include "stack.h"

#define STACK_SIZE 10

Stack::Stack() 
{
    Arr = new int[STACK_SIZE];
    topIndex = -1;
}

Stack::~Stack() 
{
    delete[] Arr;
}

void Stack::push(int elem) 
{
    if (topIndex == STACK_SIZE - 1) 
    {
        std::cout << "Stack is full. Cannot push element." << std::endl;
        return;
    }
    topIndex++;
    Arr[topIndex] = elem;
}

int Stack::pop() 
{
    if (isEmpty()) 
    {
        std::cout << "Stack is empty. Cannot pop element." << std::endl;
        return 0;
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
    for (int i = 0; i <= topIndex; i++) 
    {
        std::cout << Arr[i] << " ";
    }
    std::cout << std::endl;
}

