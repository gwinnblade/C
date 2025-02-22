#include <stdio.h>

int main() {
    int c;
    int space_count = 0;
    int t_count = 0;
    int n_count = 0;

    printf("Input text:\n");
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            space_count++;
        } else if (c == '\t') {
            t_count++;
        } else if (c == '\n') {
            n_count++;
        }
    }

    printf("Spaces: %d\n", space_count);
    printf("Tab: %d\n", t_count);
    printf("New: %d\n", n_count);

    return 0;
}
