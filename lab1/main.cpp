#include <iostream>
#include "array.h"


int main()
{      
    Array arr(5, 5);
    int A[9] = {6, 6, 6, 6, 6, 6, 6, 6, 6};

    arr.setValue(10);
    arr.setValue(20);
    arr.setValue(30);
    arr.setArray(A, 9);

    std::cout << "Array size: " << arr.getSize() << std::endl;
    std::cout << "Element size: " << arr.getElemSize() << std::endl;

    std::cout << "Elements: ";
    arr.showElements(); 

    return 0;
}