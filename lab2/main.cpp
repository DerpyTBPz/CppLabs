#include <iostream>
#include "stack.h"

#include "stack.h"

int main() 
{
    Stack myStack(5); 
    Stack anotherStack(10); 
    

    myStack.push(10); 
    myStack.push(20); 
    myStack.push(30);    

    std::cout << "Stack elements after pushing: ";
    myStack.show(); 

    int poppedElement = myStack.pop(); 
    std::cout << "Popped element: " << poppedElement << std::endl;

    std::cout << "Stack elements after popping: ";
    myStack.show(); 

    std::cout << "Is stack empty? " << (myStack.isEmpty() ? "Yes" : "No") << std::endl;

    myStack.multiPop(2); 

    std::cout << "Stack elements after multi-pop: ";
    myStack.show(); 

    Stack copiedStack = myStack; 

    std::cout << "Copied stack elements: ";
    copiedStack.show(); 

    anotherStack = myStack; 

    std::cout << "Another stack elements: ";
    anotherStack.show(); 

    return 0;
}