#include "array.h"
#include <iostream>

Array::Array()
{
    this->initSize = 20;
    this->step = 20;
    this->clArr = new int[20];
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
    int* tmp = new int[size + step];
    int k = 0;
    if (size > this->size)
    {
        expandArray(size);
    }
    for (int i = 0; i < size; i++)
    {
        clArr[i] = pArr[i];
    }

    for (int i = 0; i < size; i++)
    {
        tmp[i] = pArr[i];
        k++;
    }
    for (int i = 0; i < size; i++)
    {
        tmp[k + i] = clArr[i];
    }
    delete[] clArr;
    clArr = tmp;
    delete[] tmp;

    index = size;
    elemSize = size;
}