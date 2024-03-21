#include <stdio.h>
#define NMAX 256

int main(void) {
    char str[NMAX] = {0};
    fgets(str, NMAX - 1, stdin);
    char separator;
    scanf("%c", &separator);
    int count = 0;
    while (str[count] != '\0' && str[count] != '\n') {
        if (str[count] == ' ') str[count] = separator;
        count++;
    }
    printf("%s", str);
    return 0;
}