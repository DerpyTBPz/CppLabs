#include <iostream>
#include "vector.h"
#include "filehandler.h"

int main()
{
    Vector v1(1, 2, 3);
    Vector v2(4, 5, 6);

    std::cout << "Magnitude of v1: " << v1.getMagnitude() << std::endl;
    std::cout << "Magnitude of v2: " << v2.getMagnitude() << std::endl;

    std::cout << "Dot product of v1 and v2: " << v1.getDotProduct(v2) << std::endl;

    Vector sum = v1.add(v2);
    std::cout << "Sum of v1 and v2: " << sum << std::endl;

    Vector difference = v1.subtract(v2);
    std::cout << "Difference between v1 and v2: " << difference << std::endl;

    Vector multiplied = v1.multiply(2.5);
    std::cout << "Multiplication of v1 by 2.5: " << multiplied << std::endl;

    if (v1.areCollinear(v2)) {
        std::cout << "v1 and v2 are collinear." << std::endl;
    } else {
        std::cout << "v1 and v2 are not collinear." << std::endl;
    }

    if (v1.areOrthogonal(v2)) {
        std::cout << "v1 and v2 are orthogonal." << std::endl;
    } else {
        std::cout << "v1 and v2 are not orthogonal." << std::endl;
    }
    
    std::string v1Data = v1.toString();
    std::string v2Data = v2.toString();

    std::string encryptedV1Data = FileHandler::encryptData(v1Data);
    std::string encryptedV2Data = FileHandler::encryptData(v2Data);

    FileHandler::saveData("vector1.txt", encryptedV1Data);
    FileHandler::saveData("vector2.txt", encryptedV2Data);

    return 0;
    
}