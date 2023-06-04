#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

class Vector
{
private:
    int x, y;
    std::string name;

public:
    Vector();
    Vector(std::string name, int xVal, int yVal);
    ~Vector();

    double module() const;
    int scalarProduct(const Vector& other) const;
    Vector sumWith(const Vector& other) const;
    Vector subtractWith(const Vector& other) const;
    Vector multiplyBy(int scalar) const;
    bool areCollinearWith(const Vector& other) const;
    bool areOrthogonalWith(const Vector& other) const;

    void setName(std::string newName);
    void setX(int newX);
    void setY(int newY);    

    std::string getName() const;
    int getX() const;
    int getY() const;    
    
    std::string toString() const;

    friend std::ostream& operator<<(std::ostream& os, const Vector& vec);
};

#endif