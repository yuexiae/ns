#include "sqlite/sqlite.h"
#include "sqlite/sqlite3.h"
#include "base/logging.h"

#define SqliteThrow(format, ...) do { \
	throw sqlite::Exception( \
		base::Util::Format("[%s:%d]", __FUNCTION__, __LINE__).append(base::Util::Format(format, __VA_ARGS__))); \
} while (0)


namespace sqlite {

Statement::Statement(sqlite3_stmt *stmt) {
    stmt_ = stmt;
}

Statement::~Statement() {
    if (stmt_) {
        int rc = sqlite3_finalize(stmt_);
        if (rc != SQLITE_OK) {
            LOGERROR("%s", sqlite3_errstr(rc));
        }

        stmt_ = NULL;
    }
}

bool Statement::Fetch() {
    int rc = sqlite3_step(stmt_);
	switch(rc) {
		case SQLITE_BUSY:
			SqliteThrow("Fecth() SQLITE_BUSY");
			return false;
		case SQLITE_DONE:
			return false;
		case SQLITE_ROW:
			return true;
		case SQLITE_ERROR:
			SqliteThrow(sqlite3_errstr(rc));
			return false;
		case SQLITE_MISUSE:
			SqliteThrow("Fetch() SQLITE_MISUSE");
			return false;
	}

	return false;
}


const char* Statement::GetColumnName(int column) {
    CheckColumnIndex(column);
	return sqlite3_column_name(stmt_, column);
}

int Statement::GetColumnBytes(int column) {
    CheckColumnIndex(column);
	return sqlite3_column_bytes(stmt_, column);
}


const char* Statement::GetColumnText(int column) {
	CheckColumnIndex(column);
	return reinterpret_cast<const char *>(sqlite3_column_text(stmt_, column));
}


const void* Statement::GetColumnBlob(int column) {
	CheckColumnIndex(column);
	return sqlite3_column_blob(stmt_, column);
}

void Statement::CheckColumnIndex(int column) {
    if(column < 0 || column >= sqlite3_column_count(stmt_)) {
        SqliteThrow("column '%d' does not exists", column);
    }
}


Connector::Connector() {
    db_ = NULL;
}

Connector::~Connector() {
    if (db_) {
        int rc = sqlite3_close(db_);
        if (rc != SQLITE_OK) {
            LOGERROR("%s", sqlite3_errstr(rc));
        }

        db_ = NULL;
    }
}

void Connector::Open(const char *filename, int flags) {
    sqlite3 *db = NULL;

    int rc = sqlite3_open_v2(filename, &db, flags, NULL);
    if (rc != SQLITE_OK) {
        const char *error = "Out of memory";
        if (db != NULL) {
            error = sqlite3_errmsg(db);
            sqlite3_close(db);
        }
        SqliteThrow(error);
    }

    db_ = db;
}

Statement Connector::Prepare(const char *sql) {
    CheckDataBase();

    const char* tail=0;
    sqlite3_stmt* stmt;

    int rc = sqlite3_prepare_v2(db_, sql, -1, &stmt, &tail);
    if (rc != SQLITE_OK) {
        SqliteThrow(sqlite3_errmsg(db_));
    }

    return Statement(stmt);
}

void Connector::CheckDataBase() {
    if (db_ == NULL) {
        SqliteThrow("db_ == NULL");
    }
}



}