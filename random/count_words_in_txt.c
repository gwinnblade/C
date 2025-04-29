//Подсчет слов в txt файле

#include <stdio.h>
#include <ctype.h>

int countWords(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error of open file\n");
        return -1;
    }
    int wordCount = 0;
    int inWord = 0;
    char c;
    while ((c = fgetc(file)) != EOF) {
        if (isspace(c)) {
            if (inWord) {
                wordCount++;
                inWord = 0;
            }
        } else {
            inWord = 1;
        }
    }
    if (inWord) {
        wordCount++;
    }

    fclose(file);
    return wordCount;
}
int main() {
    const char* filename = "text.txt";
    int words = countWords(filename);
    printf("Count of words in file: %d\n", words);
    return 0;
}
