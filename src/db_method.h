#include <sqlite3.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NMAX 256

void exit_with_error();
void open_db(sqlite3 **db);
void menu(sqlite3 *db);
void do_show(sqlite3 *db);
void do_show_all(sqlite3 *db);
void do_add(sqlite3 *db);
void do_remove(sqlite3 *db);