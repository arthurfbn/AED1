#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//The implentation of Insertion Sort´s algorithm is based on the guide's book  of this disciplin 'Algoritmos em linguagem C' written by Paulo Feofiloff

void insercao(int n, char **v) {
    int i, j;
    char *x;
    for (j = 1; j < n; j++) {
        x = v[j];
        i = j - 1;
        while (i >= 0 && strcmp(v[i], x) > 0) {
            v[i + 1] = v[i];
            i--;
        }
        v[i + 1] = x;
    }
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        char **livros = (char **)malloc(n * sizeof(char *));
        for (int i = 0; i < n; i++) {
            livros[i] = (char *)malloc(5 * sizeof(char));
            scanf("%s", livros[i]);
        }
        insercao(n, livros);
        for (int i = 0; i < n; i++) {
            printf("%s\n", livros[i]);
            free(livros[i]);
        }
        free(livros);
    }
    return 0;
}