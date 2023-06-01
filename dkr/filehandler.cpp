#include <iostream>
#include <fstream>
#include "filehandler.h"

void FileHandler::encryptFile(const std::string& filename) {
    std::ifstream inputFile(filename);
    if (!inputFile) {
        std::cout << "Failed to open file: " << filename << std::endl;
        return;
    }

    std::string encryptedData;
    std::string line;
    while (std::getline(inputFile, line)) {
        encryptedData += encrypt(line) + "\n";
    }

    inputFile.close();

    std::ofstream outputFile(filename);
    if (!outputFile) {
        std::cout << "Failed to open file: " << filename << std::endl;
        return;
    }

    outputFile << encryptedData;
    outputFile.close();

    std::cout << "File encrypted successfully: " << filename << std::endl;
}

void FileHandler::decryptFile(const std::string& filename) {
    std::ifstream inputFile(filename);
    if (!inputFile) {
        std::cout << "Failed to open file: " << filename << std::endl;
        return;
    }

    std::string decryptedData;
    std::string line;
    while (std::getline(inputFile, line)) {
        decryptedData += decrypt(line) + "\n";
    }

    inputFile.close();

    std::ofstream outputFile(filename);
    if (!outputFile) {
        std::cout << "Failed to open file: " << filename << std::endl;
        return;
    }

    outputFile << decryptedData;
    outputFile.close();

    std::cout << "File decrypted successfully: " << filename << std::endl;
}

std::string FileHandler::encrypt(const std::string& data) {
    // Implement your encryption algorithm here
    // For demonstration purposes, let's just reverse the string
    std::string encryptedData = data;
    std::reverse(encryptedData.begin(), encryptedData.end());
    return encryptedData;
}

std::string FileHandler::decrypt(const std::string& data) {
    // Implement your decryption algorithm here
    // For demonstration purposes, let's just reverse the string
    std::string decryptedData = data;
    std::reverse(decryptedData.begin(), decryptedData.end());
    return decryptedData;
}
}