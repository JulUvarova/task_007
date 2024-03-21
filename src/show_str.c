#include <sqlite3.h>
#include <stdio.h>

int main(void) {
    sqlite3 *db;
    sqlite3_open("./data-samples/task007.db", &db);
    char *sql = "SELECT id, name, age, email FROM students WHERE id = 7;";
    sqlite3_stmt *data = NULL;
    sqlite3_prepare_v2(db, sql, -1, &data, 0);
    sqlite3_step(data);
    printf("%d %s %d %s", sqlite3_column_int(data, 0), sqlite3_column_text(data, 1),
           sqlite3_column_int(data, 2), sqlite3_column_text(data, 3));
    sqlite3_finalize(data);
    sqlite3_close(db);
    return 0;
}