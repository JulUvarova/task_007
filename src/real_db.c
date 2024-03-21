#include "db_method.h"

int main(void) {
    sqlite3 *db = NULL;
    open_db(&db);
    menu(db);
    sqlite3_close(db);
    exit(EXIT_SUCCESS);
}
