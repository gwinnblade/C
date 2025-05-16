#include <stdio.h>
#include <string.h>

int main() {
    FILE* in = fopen("input.txt", "r");
    FILE* out = fopen("output.txt", "w");

    if (!in || !out) {
        printf("error of open file.\n");
        return 1;
    }

    char line[256];
    while (fgets(line, sizeof(line), in)) {
        int len = strlen(line);
        if (line[len - 1] == '\n') len--;
        for (int i = len - 1; i >= 0; i--) {
            fputc(line[i], out);
        }
        fputc('\n', out);
    }

    fclose(in);
    fclose(out);
    printf("Reverse complete.\n");
    return 0;
}
