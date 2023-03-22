#include <iostream>
#include "functions.h"

int main()
{
    int size1, size2;

    std::cout << "Enter array size1:";
    std::cin >> size1;
    std::cout << "Enter array size2:";   
    std::cin >> size2; 

    int *A = new int[size1];
    int *B = new int[size2];

    for(int i = 0; i < size1; i++)
    {
        std::cin >> A[i];
    }
    
    for(int i = 0; i < size2; i++)
    {
        std::cin >> B[i];
    }
    
    findSameElements(A, size1, B, size2);
    return 0;
}