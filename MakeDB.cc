#include <iostream>
#include <sqlite3.h>
#include <iostream>
#include <sstream>
#include<string>
using namespace std;

    //This is fixed code //
static int callback(void* data, int argc, char** argv, char** azColName)
{
    int i;
    fprintf(stderr, "%s: ", (const char*)data);
  
    for (i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
  
    printf("\n");
    return 0;
}
  

    //This main creates all the Database we want
    // And make the tables we want for this project

int main(int argc, char** argv)
{
    sqlite3* DB;
    int exit = 0;

        //Making the database! //
    exit = sqlite3_open("TictactoeAI.db", &DB);

    if (exit) {
        std::cerr << "Error open DB " << sqlite3_errmsg(DB) << std::endl;
        return (-1);
    }
    else
        std::cout << "Opened Database Successfully!" << std::endl;
    

        // Table for the X //

    std::string sql2 = "CREATE TABLE X( ID INTEGER PRIMARY KEY AUTOINCREMENT, M1 INTEGER,M2 INTEGER,M3 INTEGER,M4 INTEGER ,M5 INTEGER,M6 INTEGER,M7 INTEGER,M8 INTEGER ,M9 INTEGER);";
    exit = 0;
    exit = sqlite3_open("TictactoeAI.db", &DB);
    char* messaggeError;
    exit = sqlite3_exec(DB, sql2.c_str(), NULL, 0, &messaggeError);
  
    if (exit != SQLITE_OK) {
        std::cerr << "Error Create Table" << std::endl;
        sqlite3_free(messaggeError);
    }
    else
        std::cout << "Table created Successfully" << std::endl;
    
        //Tables for Y // 

    std::string sql = "CREATE TABLE Y( ID INTEGER PRIMARY KEY AUTOINCREMENT, M1 INTEGER,M2 INTEGER,M3 INTEGER,M4 INTEGER ,M5 INTEGER,M6 INTEGER,M7 INTEGER,M8 INTEGER ,M9 INTEGER);";
    exit = 0;
    exit = sqlite3_open("TictactoeAI.db", &DB);
    char* messaggeError2;
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError2);
  
    if (exit != SQLITE_OK) {
        std::cerr << "Error Create Table" << std::endl;
        sqlite3_free(messaggeError);
    }
    else
        std::cout << "Table created Successfully" << std::endl;


    
    string query2 = "SELECT * FROM Y;";
  
  
    sqlite3_exec(DB, query2.c_str(), callback, NULL, NULL);

        query2 = "SELECT * FROM X;";
  
  
    sqlite3_exec(DB, query2.c_str(), callback, NULL, NULL);

    exit = sqlite3_open("TictactoeAI.db", &DB);

    std::string line;

while (std::getline(std::cin, line))
{
    // This is seeted because i use gnome-termin
    std::cout << line << std::endl;
}


    return (0);


}