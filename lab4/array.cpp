#include "array.h"
#include <iostream>

Array::Array()
{
    this->initSize = initSize;
    this->step = 10;
    this->clArr = new int[10];
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
    //std::cout << getSize() << "\n"; 
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

Array::Array(const Array &other)
{
    size = other.size;
    elemSize = other.elemSize;
    initSize = other.initSize;
    step = other.step;
    index = other.index;

    clArr = new int[size];
    for (int i = 0; i < elemSize; i++)
    {
        clArr[i] = other.clArr[i];
    }
}

Array& Array::operator=(const Array &other)
{
    if (this == &other)
    {
        return *this;
    }

    delete[] clArr;

    size = other.size;
    elemSize = other.elemSize;
    initSize = other.initSize;
    step = other.step;
    index = other.index;

    clArr = new int[size];
    for (int i = 0; i < elemSize; i++)
    {
        clArr[i] = other.clArr[i];
    }

    return *this;
}

Array Array::operator+(const Array& other)
{
    Array result;
    result.initSize = initSize;
    result.size = size + other.size;
    result.elemSize = elemSize + other.elemSize;
    result.clArr = new int[result.size];

    for (int i = 0; i < elemSize; i++)
    {
        result.clArr[i] = clArr[i];
    }

    for (int i = 0; i < other.elemSize; i++)
    {
        result.clArr[elemSize + i] = other.clArr[i];
    }

    return result;
}

Array Array::operator+(int value)
{
    Array result(*this);

    for (int i = 0; i < elemSize; i++)
    {
        result.clArr[i] += value;
    }

    return result;
}

Array Array::operator-(int value)
{
    Array result(*this);

    for (int i = 0; i < elemSize; i++)
    {
        result.clArr[i] -= value;
    }

    return result;
}

bool Array::operator==(const Array& other)
{
    if (elemSize != other.elemSize)
    {
        return false;
    }

    for (int i = 0; i < elemSize; i++)
    {
        if (clArr[i] != other.clArr[i])
        {
            return false;
        }
    }

    return true;
}

bool Array::operator!=(const Array& other)
{
    return !(*this == other);
}

Array Array::operator++(int)
{
    Array result(*this);

    for (int i = 0; i < elemSize; i++)
    {
        clArr[i]++;
    }

    return result;
}

Array& Array::operator+=(int value)
{
    for (int i = 0; i < elemSize; i++)
    {
        clArr[i] += value;
    }

    return *this;
}

int& Array::operator[](int index)
{
    if (index >= 0 && index < elemSize)
    {
        return clArr[index];
    }
    else
    {        
        return clArr[0];
    }
}

std::ostream& operator<<(std::ostream& os, const Array& arr)
{
    for (int i = 0; i < arr.elemSize; i++)
    {
        os << arr.clArr[i] << " ";
    }
    return os;
}

Array operator+(int value, const Array& arr)
{
    Array result(arr);

    for (int i = 0; i < result.elemSize; i++)
    {
        result.clArr[i] += value;
    }

    return result;
}

