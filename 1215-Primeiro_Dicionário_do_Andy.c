#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 5000
#define MAX_LEN 210

int separa(int p, int r, char v[][MAX_LEN]) {
    char c[MAX_LEN], t[MAX_LEN];
    int j = p;

    strcpy(c, v[r]);

    for (int k = p; k < r; k++) {
        if (strcmp(v[k], c) <= 0) {
            strcpy(t, v[j]);
            strcpy(v[j], v[k]);
            strcpy(v[k], t);
            j++;
        }
    }

    strcpy(v[r], v[j]);
    strcpy(v[j], c);

    return j;
}

void quicksort(int p, int r, char v[][MAX_LEN]) {
    int j;
    if (p < r) {
        j = separa(p, r, v);
        quicksort(p, j - 1, v);
        quicksort(j + 1, r, v);
    }
}

int existe(char palavras[][MAX_LEN], int total, char *palavra) {
    for (int i = 0; i < total; i++) {
        if (strcmp(palavras[i], palavra) == 0)
            return 1;
    }
    return 0;
}

int main() {
    char palavras[MAX_WORDS][MAX_LEN];
    int total = 0;

    char linha[210];
    char atual[MAX_LEN];
    int idx = 0;

    while (fgets(linha, sizeof(linha), stdin)) {
        int n = strlen(linha);

        for (int i = 0; i <= n; i++) {
            if (isalpha(linha[i])) {
                atual[idx++] = tolower(linha[i]);
            } else {
                if (idx > 0) {
                    atual[idx] = '\0';
                    if (!existe(palavras, total, atual)) {
                        strcpy(palavras[total++], atual);
                    }
                    idx = 0;
                }
            }
        }
    }

    quicksort(0, total - 1, palavras);

    for (int i = 0; i < total; i++) {
        printf("%s\n", palavras[i]);
    }

    return 0;
}
