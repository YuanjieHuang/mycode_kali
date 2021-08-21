#include <sqlite3.h>
#include <stdio.h>

int main(void)
{
sqlite3 *db;
char *err_msg=0;

//打开数据库
if(sqlite3_open("test.db", &db) != SQLITE_OK)
    {
        fprintf(stderr, "Cannot open databases:%s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }
    //设置SQL语句字符串
    char *sql = "DROP TABLE IF EXISTS Cars;"
                "CREATE TABLE Cars(Id INT, Name TEXT, Price INT);"
                "INSERT INTO Cars VALUES(1, 'Audi', 300000);"
                "INSERT INTO Cars VALUES(2, 'Mercedes', 333400);"
                "INSERT INTO Cars VALUES(3, 'Volvo', 200000);";
    //编译并执行sql语句字符串
    if(sqlite3_exec(db, sql, 0, 0, &err_msg) != SQLITE_OK)
        {
            fprintf(stderr, "SQL error: %s\n", err_msg);
            sqlite3_free(err_msg);
            sqlite3_close(db);
            return 1;
        }
    sqlite3_close(db);
    return 0;
}
