#include <iostream>
#include <sqlite3.h>
  
int main(int argc, char** argv)
{
    sqlite3* DB;
    int exit = 0;
    exit = sqlite3_open("AIdb.db", &DB);

    if (exit) {
        std::cerr << "Error open DB " << sqlite3_errmsg(DB) << std::endl;
        return (-1);
    }
    else
        std::cout << "Opened Database Successfully!" << std::endl;
    
    std::string sql = "CREATE TABLE MovesForX("
                      "ID INT PRIMARY KEY     NOT NULL, "
                      "M1 INT NULL, "
                      "M2 INT NULL, "
                      "M3 INT NULL, "
                      "M4 INT NULL, "
                      "M5 INT NULL, "
                      "M6 INT NULL, "
                      "M7 INT NULL, "
                      "M8 INT NULL, "
                      "M9 INT NULL);";
    exit = 0;
    exit = sqlite3_open("AIdb.db", &DB);
    char* messaggeError;
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
  
    if (exit != SQLITE_OK) {
        std::cerr << "Error Create Table" << std::endl;
        sqlite3_free(messaggeError);
    }
    else
        std::cout << "Table created Successfully" << std::endl;
    


        exit = 0;
    exit = sqlite3_open("AIdb.db", &DB);

    if (exit) {
        std::cerr << "Error open DB " << sqlite3_errmsg(DB) << std::endl;
        return (-1);
    }
    else
        std::cout << "Opened Database Successfully!" << std::endl;
    
    sql = "CREATE TABLE MovesForY("
                      "ID INT PRIMARY KEY     NOT NULL, "
                      "M1 INT NULL, "
                      "M2 INT NULL, "
                      "M3 INT NULL, "
                      "M4 INT NULL, "
                      "M5 INT NULL, "
                      "M6 INT NULL, "
                      "M7 INT NULL, "
                      "M8 INT NULL, "
                      "M9 INT NULL);";
    exit = 0;
    exit = sqlite3_open("AIdb.db", &DB);
    messaggeError==NULL;
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
  
    if (exit != SQLITE_OK) {
        std::cerr << "Error Create Table" << std::endl;
        sqlite3_free(messaggeError);
    }
    else
        std::cout << "Table created Successfully" << std::endl;
    
    
    sqlite3_close(DB);
    return (0);


}