// Программа "Шифр Цезаря"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void caesar_encrypt(char *str, int shift) {
    shift %= 26; //Если дает остаток значит сдвиг правильно введен
    for (int i = 0; str[i]; i++) {
        if (isupper(str[i])) { // isupper возвращает True если буква заглавная
            str[i] = 'A' + (str[i] - 'A' + shift + 26) % 26; // Идет подсчет какая буква будет
        } else if (islower(str[i])) { // islower возвращает True если буква строчная
            str[i] = 'a' + (str[i] - 'a' + shift + 26) % 26;
        }
    }
}

int main() {
    char text[1024];
    int shift;

    printf("input text: ");
    fgets(text, sizeof(text), stdin);
    
    text[strcspn(text, "\n")] = '\0'; // "Стандартное" удаление символа \n

    printf("input shift: ");
    scanf("%d", &shift);

    caesar_encrypt(text, shift);
    printf("crypted massage: %s\n", text);

    return 0;
}
