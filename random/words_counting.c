#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int count_words(const char *str) {
    int count = 0;
    bool in_word = false;
    while (*str) {
        if (*str == ' ' || *str == '\t' || *str == '\n') {
            if (in_word) {
                in_word = false;
            }
        } else {
            if (!in_word) {
                count++;
                in_word = true;
            }
        }
        str++;
    }
    return count;
}
int main() {
    char text[1000];
    printf("Input text: ");
    fgets(text, sizeof(text), stdin); 
    size_t len = strlen(text);
    if (len > 0 && text[len - 1] == '\n') {
        text[len - 1] = '\0';
    }
    printf("Count of words: %d\n", count_words(text));
    return 0;
}
