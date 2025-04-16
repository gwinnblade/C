#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void caesar_encrypt(char *str, int shift) {
    shift %= 26;
    for (int i = 0; str[i]; i++) {
        if (isupper(str[i])) {
            str[i] = 'A' + (str[i] - 'A' + shift + 26) % 26;
        } else if (islower(str[i])) {
            str[i] = 'a' + (str[i] - 'a' + shift + 26) % 26;
        }
    }
}

int main() {
    char text[1024];
    int shift;

    printf("input text: ");
    fgets(text, sizeof(text), stdin);
    
    text[strcspn(text, "\n")] = '\0';

    printf("input shift: ");
    scanf("%d", &shift);

    caesar_encrypt(text, shift);
    printf("crypted massage: %s\n", text);

    return 0;
}
