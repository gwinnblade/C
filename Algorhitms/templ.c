#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

typedef struct word {
  int count;
  char *Word;
} WORD;
int cmpword_alpha(const void *a, const void *b);
int cmpword_quant(const void *a, const void *b);
WORD words[100000];
int totalw = 0;
char *getword(FILE *F);
int main(int ac, char *av[]) {
  FILE *IN;
  char *pword;
  if (ac < 2) {
    printf("You forgot to specify the list of files!\n");
    exit(0);
  }
  for (int i = 1; i < ac; i++) {
    IN = fopen(av[i], "r");
    if (IN == NULL) {
      printf("Failed to open file %s\n", av[i]);
      continue;
    }
    printf("Processing file %s\n", av[i]);
    while ((pword = getword(IN)) != NULL) {
      int found = 0;
      for (int j = 0; j < totalw; j++) {
        if (strcmp(words[j].Word, pword) == 0) {
          words[j].count++;
          found = 1;
          break;
        }
      }

      if (!found) {
        words[totalw].Word = strdup(pword);
        words[totalw].count = 1;
        totalw++;
      }
    }
    fclose(IN);
  }
  qsort(words, totalw, sizeof(WORD), cmpword_alpha);
  printf("\nWords sorted alphabetically:\n");
  for (int i = 0; i < totalw; i++) {
    printf("%s: %d\n", words[i].Word, words[i].count);
  }
  qsort(words, totalw, sizeof(WORD), cmpword_quant);
  printf("\nWords sorted by frequency:\n");
  for (int i = 0; i < totalw; i++) {
    printf("%s: %d\n", words[i].Word, words[i].count);
  }

  return 0;
}

char *getword(FILE *F) {
  static char buffer[100];
  int c, index = 0;

  while ((c = fgetc(F)) != EOF) {
    if (isalpha(c)) {
      buffer[index++] = tolower(c);
    } else if (index > 0) {
      buffer[index] = '\0';
      return strdup(buffer);
    }
  }

  return NULL;
}

int cmpword_alpha(const void *a, const void *b) {
  return strcmp(((WORD *)a)->Word, ((WORD *)b)->Word);
}
int cmpword_quant(const void *a, const void *b) {
  return ((WORD *)b)->count - ((WORD *)a)->count;
}
