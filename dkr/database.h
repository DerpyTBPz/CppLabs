#ifndef DB_H
#define DB_H

#include <sqlite3.h>

#include "vector.h"

class DB
{
private:
    sqlite3* db;

public:
    DB();
    ~DB();
    void insertInDB(Vector* vectors, int number, int i);
    void clearDB();
};

class Log
{
private:
    sqlite3* log;
    int num;

public:
    Log();
    ~Log();  
    void Add(std::string text);
    void clearLog();
};

#endif