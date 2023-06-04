#include <iostream>
#include <cmath>
#include "vector.h"

Vector::Vector()
{
    
}

Vector::Vector(std::string name, int xVal, int yVal)
{
    this->name = name;
    this->x = xVal;
    this->y = yVal;   
}

Vector::~Vector()
{

}

double Vector::module() const
{
    return std::sqrt((x * x) + (y * y));
}

int Vector::scalarProduct(const Vector& other) const
{   
    return (x * other.x) + (y * other.y);
}

Vector Vector::sumWith(const Vector& other) const
{
    return Vector(name + "+" + other.name,x + other.x, y + other.y);
}

Vector Vector::subtractWith(const Vector& other) const
{
    return Vector(name + "-" + other.name,x - other.x, y - other.y);
}

Vector Vector::multiplyBy(int scalar) const
{
    return Vector(name + "*" + std::to_string(scalar), x * scalar, y * scalar);
}

bool Vector::areCollinearWith(const Vector &other) const
{
    double a, b;
    if ((x/other.x) == (y/other.y))
    {
        return true;
    }
    else 
    {
        return false;
    }
    
}

bool Vector::areOrthogonalWith(const Vector& other) const
{
    if (((((x * other.x) + (y * other.y)) / (module()*other.module())) == 90) || (scalarProduct(other) == 0))
    {
        return true;
    }
    else 
    {    
        return false;   
    }   
}


void Vector::setName(std::string newName)
{
    name = newName;
}

void Vector::setX(int newX)
{
    x = newX;
}

void Vector::setY(int newY)
{
    y = newY;
}

std::string Vector::getName() const
{
    return name;
}
int Vector::getX() const
{
    return x;
}

int Vector::getY() const
{
    return y;
}


std::string Vector::toString() const
{
    return name + "(" + std::to_string(x) + ",\t" + std::to_string(y) + ")";
}

std::ostream& operator<<(std::ostream& os, const Vector& vec)
{
    os << vec.toString();
    return os;
}



