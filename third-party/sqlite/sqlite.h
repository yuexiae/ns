#ifndef SQLITE_SQLITE_H_
#define SQLITE_SQLITE_H_

#include <exception>
#include "base/util.h"

struct sqlite3;
struct sqlite3_stmt;

namespace sqlite {

class Exception : public std::exception {
public:
    Exception(std::string &msg) : exception(msg.c_str()) {}
};


class Statement {
    friend class Connector;

    Statement(sqlite3_stmt *stmt);

public:
    ~Statement();

    Statement(Statement& rhs) {
        stmt_ = rhs.stmt_;
        rhs.stmt_ = NULL;
    }

    Statement& operator=(Statement& rhs) {
        this->~Statement();
        stmt_ = rhs.stmt_;
        rhs.stmt_ = NULL;
    }
    
    bool Fetch();

    const char* GetColumnName(int column);
    int GetColumnBytes(int column);
    const char* GetColumnText(int column);
    const void* GetColumnBlob(int column);

private:
    void CheckColumnIndex(int column);

    sqlite3_stmt *stmt_;
};

class Connector {
    Connector(Connector&);
    Connector& opeartor(Connector&);
public:
    Connector();

    virtual ~Connector();

    void Open(const char *filename, int flags);

    Statement Prepare(const char *sql);

private:
    void CheckDataBase();

    sqlite3 *db_;
};




}


#endif