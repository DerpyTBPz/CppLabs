#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <iostream>

class FileHandler
{
public:
    static void saveData(const std::string& filename, const std::string& data);
    static std::string encryptData(const std::string& data);

    static void encryptFile(const std::string& filename);
    static void decryptFile(const std::string& filename);

private:
    static std::string encrypt(const std::string& data);
    static std::string decrypt(const std::string& data);
};

#endif