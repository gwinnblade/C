#include <stdio.h>
void remove_spaces(char *str) {
    int j = 0;
    for (int i = 0; str[i]; i++) {
        if (str[i] != ' ') {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}
int main() {
    char str[] = "Hello, world!";
    remove_spaces(str);
    printf("%s\n", str);
    return 0;
}
