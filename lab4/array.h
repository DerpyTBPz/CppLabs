#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>

class Array
{
private:
    int initSize, step, index, size, elemSize;    
    int *clArr;   

public:
    //constructor
    Array();
    ~Array();
    Array(const Array& other);    

    //function
    void showElements();
    void expandArray(int size);
    int getSize();
    int getElemSize();
    void setValue(int val);
    void setArray(int *pArr, int size); 

    //operators
    Array& operator=(const Array& other);
    Array operator+(const Array& other);                                    // operator+
    Array operator+(int value);                                             // operator+
    Array operator-(int value);                                             // operator-
    bool operator==(const Array& other);                                    // operator==
    bool operator!=(const Array& other);                                    // operator!=
    Array operator++(int);                                                  // operator++
    Array& operator+=(int value);                                           // operator+=
    int& operator[](int index);                                             // operator[]
    friend std::ostream& operator<<(std::ostream& os, const Array& arr);    // operator<<
    friend Array operator+(int value, const Array& arr);                    // operator+ (friend)

};

#endif