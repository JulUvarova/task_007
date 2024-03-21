#include "db_method.h"

void menu(sqlite3 *db) {
    char command[10];
    scanf("%9s", command);
    while (strcmp(command, "EXIT") != 0) {
        if (strcmp(command, "SHOW") == 0) {
            do_show(db);
        } else if (strcmp(command, "SHOWALL") == 0) {
            do_show_all(db);
        } else if (strcmp(command, "ADD") == 0) {
            do_add(db);
        } else if (strcmp(command, "REMOVE") == 0) {
            do_remove(db);
        } else {
            printf("UNKNOWN COMMAND");
        }
        scanf("%9s", command);
    }
}

void do_remove(sqlite3 *db) {
    int id = 0;
    if (scanf("%d", &id) != 1) exit_with_error();
    char sql[NMAX] = "DELETE FROM students WHERE id = ?";
    sqlite3_stmt *data = NULL;
    int is_read = sqlite3_prepare_v2(db, sql, -1, &data, 0);
    if (is_read == SQLITE_OK) {
        sqlite3_bind_int(data, 1, id);
    } else {
        fprintf(stderr, "Ошибка в запросе");
    }
    sqlite3_step(data);
    sqlite3_finalize(data);
}

void do_add(sqlite3 *db) {
    char sql[NMAX] = "INSERT INTO students (name, age, email) VALUES(?, ?, ?);";
    char name[NMAX] = {0}, surname[NMAX] = {0}, email[NMAX] = {0};
    int age = 0;
    if (scanf("%255s %255s %d %255s", name, surname, &age, email) != 4) exit_with_error();
    sqlite3_stmt *data = NULL;
    int is_read = sqlite3_prepare_v2(db, sql, -1, &data, 0);
    if (is_read == SQLITE_OK) {
        name[strlen(name)] = ' ';
        sqlite3_bind_text(data, 1, strcat(name, surname), -1, SQLITE_STATIC);
        sqlite3_bind_int(data, 2, age);
        sqlite3_bind_text(data, 3, email, -1, SQLITE_STATIC);
    } else {
        fprintf(stderr, "Ошибка в запросе");
    }
    sqlite3_step(data);
    sqlite3_finalize(data);
}

void do_show_all(sqlite3 *db) {
    char sql[NMAX] = "SELECT id, name, age, email FROM students ORDER BY id ASC;";
    sqlite3_stmt *data = NULL;
    sqlite3_prepare_v2(db, sql, -1, &data, 0);
    while (sqlite3_step(data) == SQLITE_ROW) {
        printf("%d %s %d %s\n", sqlite3_column_int(data, 0), sqlite3_column_text(data, 1),
               sqlite3_column_int(data, 2), sqlite3_column_text(data, 3));
    }
    sqlite3_finalize(data);
}

void do_show(sqlite3 *db) {
    int id = 0;
    if (scanf("%d", &id) != 1) exit_with_error();
    char sql[NMAX] = "SELECT id, name, age, email FROM students WHERE id = ?";
    sqlite3_stmt *data = NULL;
    int is_read = sqlite3_prepare_v2(db, sql, -1, &data, 0);
    if (is_read == SQLITE_OK) {
        sqlite3_bind_int(data, 1, id);
    } else {
        fprintf(stderr, "Ошибка в запросе");
    }
    is_read = sqlite3_step(data);
    if (is_read == SQLITE_ROW) {
        printf("%d %s %d %s\n", sqlite3_column_int(data, 0), sqlite3_column_text(data, 1),
               sqlite3_column_int(data, 2), sqlite3_column_text(data, 3));
    } else {
        printf("NO DATA");
    }
    sqlite3_finalize(data);
}

void open_db(sqlite3 **db) {
    int is_open = sqlite3_open("./data-samples/task007.db", db);  // 0 - true
    if (is_open != SQLITE_OK) {
        exit_with_error();
    }
}

void exit_with_error() {
    fprintf(stderr, "Puck you, Verter!");
    exit(EXIT_FAILURE);
}