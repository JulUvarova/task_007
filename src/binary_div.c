#include <stdio.h>
#include <string.h>
#define NMAX 256

void print_str(const char *str, int count);

int main(void) {
    char str[NMAX] = {0};
    scanf("%255s", str);
    int count = strlen(str);
    while (count > 1) {
        print_str(str, count);
        count = count / 2.0 + 0.5;
        printf("\n");
    }
    print_str(str, count);
    return 0;
}

void print_str(const char *str, int count) {
    for (int i = 0; i < count; i++) {
        printf("%c", str[i]);
    }
}