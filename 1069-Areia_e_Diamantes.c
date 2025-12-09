#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
    int valor;
    struct cel *seg;
} cel;

void Empilha(int y, cel *p) {
    cel *nova = malloc(sizeof(cel));
    nova->valor = y;
    nova->seg = p->seg;
    p->seg = nova;
}

int Desempilha(cel *p) {
    cel *q = p->seg;
    int x = q->valor;
    p->seg = q->seg;
    free(q);
    return x;
}

int PilhaVazia(cel *p) {
    return p->seg == NULL;
}

int main() {
    int N;
    scanf("%d", &N);

    while (N--) {
        char s[1001];
        scanf("%s", s);

        cel cabeca; 
        cabeca.seg = NULL;

        int diamantes = 0;

        for (int i = 0; s[i]; i++) {
            if (s[i] == '<') {
                Empilha(1, &cabeca);
            } else if (s[i] == '>') {
                if (!PilhaVazia(&cabeca)) {
                    Desempilha(&cabeca);
                    diamantes++;
                }
            }
        }

        printf("%d\n", diamantes);

        while (!PilhaVazia(&cabeca))
            Desempilha(&cabeca);
    }

    return 0;
}