#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iconv.h>

void convert_cp1251_to_utf8(char *in, char *out, size_t out_size);
int strncmp_cp1251(const char *s1, const char *s2, size_t n);
struct BookNode {
    char author[100];
    char title[100];
    char publisher[100];
    char year[10];
    char isbn[20];
    struct BookNode *lchild, *rchild;
};
struct BookNode *insert(struct BookNode *p, char *author, char *title, char *publisher) {
    if (p == NULL) {
        p = (struct BookNode *)malloc(sizeof(struct BookNode));
        if (!p) {
            printf("Cannot allocate memory\n");
            exit(1);
        }
        strcpy(p->author, author);
        strcpy(p->title, title);
        strcpy(p->publisher, publisher);
        p->lchild = p->rchild = NULL;
        return p;
    }
    if (strcmp(author, p->author) < 0)
        p->lchild = insert(p->lchild, author, title, publisher);
    else
        p->rchild = insert(p->rchild, author, title, publisher);
    return p;
}
struct BookNode *readBibFiles(const char *filename, struct BookNode *root) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file: %s\n", filename);
        return root;
    }
    char line[256];
    char author[100] = "", title[100] = "", publisher[100] = "";

    while (fgets(line, sizeof(line), file)) {
        char *key = strtok(line, "=");
        char *value = strtok(NULL, "\n");
        if (value) {
            while (*value == ' ' || *value == '{') value++;
            char *end = value + strlen(value) - 1;
            while (*end == '}' || *end == ',' || *end == ' ') *end-- = '\0';

            if (strstr(key, "author")) strcpy(author, value);
            else if (strstr(key, "title")) strcpy(title, value);
            else if (strstr(key, "publisher")) strcpy(publisher, value);
        }
    }
    fclose(file);
    char utf8_author[200];
    convert_cp1251_to_utf8(author, utf8_author, sizeof(utf8_author));
    if (strlen(utf8_author) > 0 && strlen(title) > 0 && strlen(publisher) > 0) {
        printf("Add Author: %s | title: %s | publisher: %s\n", utf8_author, title, publisher);
        root = insert(root, utf8_author, title, publisher);
    } else {
        printf("Error: Not Enough Data %s\n", filename);
    }
    return root;
}
void inorderPrint(struct BookNode *p, FILE *output) {
    if (p) {
        inorderPrint(p->lchild, output);
        fprintf(output, "%s | %s | %s\n", p->author, p->title, p->publisher);
        inorderPrint(p->rchild, output);
    }
}
struct BookNode *searchByPrefix(struct BookNode *p, const char *prefix) {
    if (!p) return NULL;
    int cmp = strncmp_cp1251(p->author, prefix, 5);
    if (cmp == 0) return p;
    if (cmp > 0) return searchByPrefix(p->lchild, prefix);
    return searchByPrefix(p->rchild, prefix);
}

int strncmp_cp1251(const char *s1, const char *s2, size_t n) {
    for (size_t i = 0; i < n; i++) {
        if (s1[i] == '\0' || s2[i] == '\0') break;
        if ((unsigned char)s1[i] != (unsigned char)s2[i])
            return (unsigned char)s1[i] - (unsigned char)s2[i];
    }
    return 0;
}
void convert_cp1251_to_utf8(char *in, char *out, size_t out_size) {
    iconv_t cd = iconv_open("UTF-8", "CP1251");
    if (cd == (iconv_t)-1) {
        printf("Error of inicialization iconv\n");
        return;
    }

    char *in_buf = in;
    char *out_buf = out;
    size_t in_bytes = strlen(in);
    size_t out_bytes = out_size - 1;

    if (iconv(cd, &in_buf, &in_bytes, &out_buf, &out_bytes) == (size_t)-1) {
        printf("Error: Conversation string: %s\n", in);
    }
    *out_buf = '\0';
    iconv_close(cd);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <bib_files>\n", argv[0]);
        return 1;
    }

    struct BookNode *root = NULL;
    for (int i = 1; i < argc; i++) {
        root = readBibFiles(argv[i], root);
    }

    FILE *output = fopen("sorted_books.txt", "w");
    if (!output) {
        printf("Error creating output file\n");
        return 1;
    }


    inorderPrint(root, output);
    fclose(output);
    char prefix[6];
    printf("Input first 5 letters of author: ");
    scanf("%5s", prefix);
    struct BookNode *found = searchByPrefix(root, prefix);
    if (found)
        printf("Find: %s - %s\n", found->author, found->title);
    else
        printf("Not find.\n");

    printf("Complete: Result - sorted_books.txt\n");
    return 0;
}
