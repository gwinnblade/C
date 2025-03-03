#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];
    
    max = 0;
    while ((len = getline(line, MAXLINE)) > 0) {
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0)
        printf("%s", longest);
    return 0;
}

int getline(char s[], int lim)
{
    int c, i;
    
    for (i = 0; i < lim - 1; ++i) {
        c = getchar();
        if (c == EOF) {
            break;
        }
        if (c == '\n') {
            s[i] = c;
            ++i;
            break;
        }
        s[i] = c;
    }
    
    if (i == lim - 1) {
        s[i] = '\0';
        while ((c = getchar()) != '\n' && c != EOF) {
        }
    } else {
        s[i] = '\0';
    }
    
    return i;
}

void copy(char to[], char from[])
{
    int i;
    
    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
