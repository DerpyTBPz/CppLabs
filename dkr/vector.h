#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

class Vector
{
private:
    double x, y, z;

public:
    Vector();
    Vector(double xVal, double yVal, double zVal);

    double getMagnitude() const;
    double getDotProduct(const Vector& other) const;
    Vector add(const Vector& other) const;
    Vector subtract(const Vector& other) const;
    Vector multiply(double scalar) const;
    bool areCollinear(const Vector& other) const;
    bool areOrthogonal(const Vector& other) const;
    void setX(double newX);
    void setY(double newY);
    void setZ(double newZ);
    double getX() const;
    double getY() const;
    double getZ() const;
    std::string toString() const;
    friend std::ostream& operator<<(std::ostream& os, const Vector& vec);
};

#endif