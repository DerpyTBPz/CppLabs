#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include "vector.h"

Vector::Vector()
{
    this->x = 0;
    this->y = 0;
    this->z = 0;
} //: x(0), y(0), z(0) {}

Vector::Vector(double xVal, double yVal, double zVal)
{
    this->x = xVal;
    this->y = yVal;
    this->z = zVal;
}// : x(xVal), y(yVal), z(zVal) {}

double Vector::getMagnitude() const
{
    return std::sqrt(x*x + y*y + z*z);
}

double Vector::getDotProduct(const Vector& other) const
{
    return x*other.x + y*other.y + z*other.z;
}

Vector Vector::add(const Vector& other) const
{
    return Vector(x + other.x, y + other.y, z + other.z);
}

Vector Vector::subtract(const Vector& other) const
{
    return Vector(x * other.x, y * other.y, z * other.z);
}

Vector Vector::multiply(double scalar) const
{
    return Vector(x * scalar, y * scalar, z * scalar);
}

bool Vector::areCollinear(const Vector &other) const
{
    return getDotProduct(other) == 0;
}

bool Vector::areOrthogonal(const Vector& other) const
{
    return getDotProduct(other) == 0;
}

void Vector::setX(double newX)
{
    x = newX;
}

void Vector::setY(double newY)
{
    y = newY;
}

void Vector::setZ(double newZ)
{
    z = newZ;
}

double Vector::getX() const
{
    return x;
}

double Vector::getY() const
{
    return y;
}

double Vector::getZ() const
{
    return z;
}

std::string Vector::toString() const
{
    return "(" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ")";
}

std::ostream& operator<<(std::ostream& os, const Vector& vec)
{
    os << vec.toString();
    return os;
}



