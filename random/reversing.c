#include <stdio.h>
#include <string.h>

void reverse_string(char *str) {
    if (!str) return;
    int left = 0;
    int right = strlen(str) - 1;
    while (left < right) {
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;
        left++;
        right--;
    }
}

int main() {
    char str[1000];
    printf("Введите строку: ");
    fgets(str, sizeof(str), stdin); 
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
    reverse_string(str);
    printf("Результат: %s\n", str);
    return 0;
}
