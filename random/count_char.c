#include <stdio.h>
#include <ctype.h>

void count_chars(const char *str) {
    int counts[256] = {0};

    for (int i = 0; str[i]; i++) {
        char c = tolower(str[i]);
        counts[(unsigned char)c]++;
    }

    for (int i = 0; i < 256; i++) {
        if (counts[i] > 0 && isprint(i)) {
            printf("'%c': %d\n", i, counts[i]);
        }
    }
}

int main() {
    const char *text = "Hello, World!";
    count_chars(text);
    return 0;
}
