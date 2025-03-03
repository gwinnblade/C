#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int maxline);
void reverse(char s[]);

int main()
{
    char line[MAXLINE];
    while (getline(line, MAXLINE) > 0) {
        reverse(line);
        printf("%s", line);
    }
    return 0;
}
int getline(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
void reverse(char s[])
{
    int i, j;
    char temp;
    for (j = 0; s[j] != '\0'; ++j)
        ;
    --j;

    if (j > 0 && s[j] == '\n') {
        --j;
    }

    for (i = 0; i < j; ++i, --j) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}
