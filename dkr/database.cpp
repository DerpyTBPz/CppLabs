#include <iostream>
#include <sqlite3.h>
#include <string>

#include "database.h"
#include "vector.h"

DB::DB()
{
    sqlite3_open("database.db", &db);
    char* errMsg;
    const std::string query = "DELETE FROM Vectors";
    sqlite3_exec(db, query.c_str(), 0, 0, &errMsg);
}

DB::~DB()
{
    sqlite3_close(db);
}

void DB::insertInDB(Vector* vectors, int number, int i)
{
    char* errMsg;
    const std::string query = "INSERT INTO Vectors (Num, Name, Coordinates) "
                              "VALUES (" + std::to_string(i) + ", '" + 
                              vectors[i].getName() + "', '(" + std::to_string(vectors[i].getX()) + ", " 
                              + std::to_string(vectors[i].getY()) + ")');";
    sqlite3_exec(db, query.c_str(), 0, 0, &errMsg);
}

void DB::clearDB()
{
    char* errMsg;
    const std::string query = "DELETE FROM Vectors";
    sqlite3_exec(db, query.c_str(), 0, 0, &errMsg);
}


Log::Log()
{
    this->num = 1;
    sqlite3_open("database.db", &log);
    char* errMsg;
    const std::string query = "DELETE FROM Log";
    sqlite3_exec(log, query.c_str(), 0, 0, &errMsg);
}

Log::~Log()
{
    sqlite3_close(log);
}

void Log::Add(std::string text)
{
    char* errMsg;
    const std::string query = "INSERT INTO Log (Num, Action) "
                              "VALUES (" + std::to_string(num) + ", '" + text + "');";
    this->num++;                          
    sqlite3_exec(log, query.c_str(), 0, 0, &errMsg);
}

void Log::clearLog()
{
    char* errMsg;
    this->num = 1;
    const std::string query = "DELETE FROM Log";
    sqlite3_exec(log, query.c_str(), 0, 0, &errMsg);
}