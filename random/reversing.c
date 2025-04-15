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
    char str[] = "Hello, world!";
    reverse_string(str);
    printf("%s\n", str); // Вывод: "!dlrow ,olleH"
    return 0;
}
