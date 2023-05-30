#pragma once

class Array
{
private:
    int initSize, step, index, size, elemSize;    
    int *clArr;   

public:
    Array(int size, int step);
    ~Array();
    void showElements();
    void expandArray(int size);
    int getSize();
    int getElemSize();
    void setValue(int val);
    void setArray(int *pArr, int size);  
};

