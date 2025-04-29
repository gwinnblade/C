#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

void generate_password(char* password, int length, bool use_upper, bool use_digits, bool use_special) {
    const char lower[] = "abcdefghijklmnopqrstuvwxyz";
    const char upper[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char digits[] = "0123456789";
    const char special[] = "!@#$%^&*()";
    
    char charset[100] = "";
    strcat(charset, lower);
    
    if (use_upper) strcat(charset, upper);
    if (use_digits) strcat(charset, digits);
    if (use_special) strcat(charset, special);
    
    int charset_length = strlen(charset);
    
    for (int i = 0; i < length; i++) {
        password[i] = charset[rand() % charset_length];
    }
    password[length] = '\0';
}

bool is_strong(const char* password) {
    bool has_upper = false, has_digit = false, has_special = false;
    
    for (int i = 0; password[i] != '\0'; i++) {
        if (isupper(password[i])) has_upper = true;
        if (isdigit(password[i])) has_digit = true;
        if (!isalnum(password[i])) has_special = true;
    }
    
    return has_upper && has_digit && has_special;
}

int main() {
    srand(time(NULL));
    char password[50];
    int length;
    char choice;
    
    printf("Password length: ");
    scanf("%d", &length);
    getchar();
    
    printf("upper char (y/n)? ");
    choice = getchar();
    bool use_upper = (choice == 'y' || choice == 'Y');
    getchar();
    
    printf("digits (y/n)? ");
    choice = getchar();
    bool use_digits = (choice == 'y' || choice == 'Y');
    getchar();
    
    printf("special_chars? (y/n)? ");
    choice = getchar();
    bool use_special = (choice == 'y' || choice == 'Y');
    
    generate_password(password, length, use_upper, use_digits, use_special);
    printf("\npassword: %s\n", password);
    
    if (is_strong(password)) {
        printf("ur password strong!\n");
    } else {
        printf("password can be stronger\n");
    }
    
    return 0;
}
