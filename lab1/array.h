#ifndef ARRAY_H
#define ARRAY_H

class Array
{
private:
    int initSize, step, index, size, elemSize;    
    int *clArr;   

public:
    Array();
    ~Array();
    void showElements();
    void expandArray(int size);
    int getSize();
    int getElemSize();
    void setValue(int val);
    void setArray(int *pArr, int size);  
};

#endif