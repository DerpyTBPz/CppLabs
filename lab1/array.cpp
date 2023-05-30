#include "array.h"
#include <iostream>

// ----------------------------<array.h>----------------------------
// class array                                                      |
// {                                                                |
// public:                                                          |
//     void showElements();                                         +
//     void expandArray(int size);                                  |
//     int getSize();                                               +
//     int getElemSize();                                           +
//     void setValue(int val);                                      |
//     void setArray(int *pArr, int size);                          +
// private:                                                         |
//     int* clArr;                                                  |
//     int clK, clI, clSize;                                        |
// };                                                               |
// -------------------------------------------------------------------

Array::Array(int size, int step)
{
    this->initSize = initSize;
    this->step = step;
    this->clArr = new int[size];
    this->index = 0;
    this->size = initSize;
    this->elemSize = 0;
}

Array::~Array()
{
    delete[] clArr;
}

void Array::showElements()
{
    for(int i = 0; i < elemSize; i++)
    {
        std::cout << clArr[i] << " ";
    }
    std::cout << std::endl;
}

void Array::expandArray(int size)
{        
    int *tmp = new int[size];    
    for(int i = 0; i < elemSize; i++)
    {
        tmp[i] = clArr[i];
    }  
    
    delete[] clArr;
    clArr = tmp;    
    this->size = size;
    std::cout << getSize() << "\n"; 
}

int Array::getSize()
{  
    return size;
}

int Array::getElemSize()
{
    return elemSize;
}

void Array::setValue(int val)
{
    if (index == size)
    {
        expandArray(size + step);
    }
    clArr[index] = val;
    index++;
    elemSize++;
}

void Array::setArray(int *pArr, int size)
{    
    if (size > this->size)
    {
        expandArray(size);
    }
    for (int i = 0; i < size; i++)
    {
        clArr[i] = pArr[i];
    }
    index = size;
    elemSize = size;
}