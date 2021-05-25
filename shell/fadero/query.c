#include <sqlite3.h>
#include <stdio.h>

int main(void) 
{
    sqlite3 *db;
    sqlite3_stmt *pStmt;

    // 打开数据库
    if (sqlite3_open(":memory:", &db) != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    // 编译 SQL 语句
    if (sqlite3_prepare_v2(db, "SELECT SQLITE_VERSION()", -1, &pStmt, 0) != SQLITE_OK) {
        fprintf(stderr, "Failed to fetch data: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    // 执行 SQL 语句
    if (sqlite3_step(pStmt) == SQLITE_ROW) 
        printf("%s\n", sqlite3_column_text(pStmt, 0));
    
    // 释放 SQL 语句句柄并关闭数据库
    sqlite3_finalize(pStmt);
    sqlite3_close(db);
    
    return 0;
}
